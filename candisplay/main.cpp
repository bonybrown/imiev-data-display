// Dear ImGui: standalone example application for SDL2 + OpenGL
// (SDL is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)

// Learn about Dear ImGui:
// - FAQ                  https://dearimgui.com/faq
// - Getting Started      https://dearimgui.com/getting-started
// - Documentation        https://dearimgui.com/docs (same as your local docs/ folder).
// - Introduction, links and more at the top of imgui.cpp

#include <imgui.h>
#include <backends/imgui_impl_sdl.h>
#include <backends/imgui_impl_opengl3.h>
#include <stdio.h>
#include <SDL.h>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL_opengles2.h>
#else
#include <SDL_opengl.h>
#endif

#include "../model.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdint>
#include <sys/select.h>
#include <unistd.h>



// This example can also compile and run with Emscripten! See 'Makefile.emscripten' for details.
#ifdef __EMSCRIPTEN__
#include "../libs/emscripten/emscripten_mainloop_stub.h"
#endif

int get_candump_data(std::ifstream& infile, int timeout_ms, unsigned int& pid, uint64_t& data) {

    int fd = fileno(stdin);
    std::string interface, pidstr, bytes;
    struct timeval tv;
    tv.tv_sec = 0;  // 0 second timeout
    tv.tv_usec = timeout_ms * 1000; // milliseconds -> usec timeout
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(fd, &fds);
    int ret = select(fd + 1, &fds, NULL, NULL, &tv);
    if (ret <= 0) {
        // Timeout or error
        return 1;
    }

    infile >> interface >> pidstr >> bytes; // Read the first line
    if (infile.eof()) {
        return 0; // End of file reached
    }
    int bytecount = bytes[1] - '0'; // Get the byte count from the second character [n]
    std::string candata;
    if (!std::getline(infile, candata)) {
        return 0; // End of file or error
    }
    candata.erase(std::remove_if(candata.begin(), candata.end(), ::isspace), candata.end());
    pid = std::stoul(pidstr, nullptr, 16); // convert pid field to uint16_t
    data = std::stoull(candata, nullptr, 16); // Convert the rest to uint64_t
    data <<= (bytecount - 8);
    //data = htole64(data); // Convert to little-endian format
    return 1; // Success
}

int get_data(std::ifstream& infile, unsigned int& pid, uint64_t& data) {
    std::string time, interface, candata;
    infile >> time >> interface >> candata; // Read the first line
    if (infile.eof()) {
        return 0; // End of file reached
    }

    if( candata.length() < 20 ) {
        //pad right with zeros
        candata += std::string(20 - candata.length(), '0');
        
    }
    //std::cout << "candata: " << candata << std::endl;
    pid = std::stoul(candata.substr(0, 3), nullptr, 16); // Convert first 3 characters to uint16_t
    data = std::stoull(candata.substr(4), nullptr, 16); // Convert the rest to uint64_t
    //data = htole64(data); // Convert to little-endian format
    return 1; // Success
}


// Main code
int main(int argc, char *argv[])
{
    // Setup SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
    {
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100 (WebGL 1.0)
    const char* glsl_version = "#version 100";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#elif defined(IMGUI_IMPL_OPENGL_ES3)
    // GL ES 3.0 + GLSL 300 es (WebGL 2.0)
    const char* glsl_version = "#version 300 es";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#elif defined(__APPLE__)
    // GL 3.2 Core + GLSL 150
    const char* glsl_version = "#version 150";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG); // Always required on Mac
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif

    // From 2.0.18: Enable native IME.
#ifdef SDL_HINT_IME_SHOW_UI
    SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
#endif

    // Create window with graphics context
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Window* window = SDL_CreateWindow("Dashboard", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
    if (window == nullptr)
    {
        printf("Error: SDL_CreateWindow(): %s\n", SDL_GetError());
        return -1;
    }
SDL_GL_MakeCurrent(window, NULL);
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    if (gl_context == nullptr)
    {
        printf("Error: SDL_GL_CreateContext(): %s\n", SDL_GetError());
        return -1;
    }

    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    bool result = ImGui_ImplOpenGL3_Init(glsl_version);
printf("ImGui_ImplOpenGL3_Init(%s) result = %d\n" ,glsl_version, result);
if(!result){
  exit(1);
}
//ImGui_ImplOpenGL3_Init()
    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return a nullptr. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use Freetype for higher quality font rendering.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    // - Our Emscripten build process allows embedding fonts to be accessible at runtime from the "fonts/" folder. See Makefile.emscripten for details.
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf", 18.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != nullptr);

    // Our state
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);


    Model model{};
    std::ifstream infile;
    if( argc > 1){
        infile.open(argv[1]);
        if (!infile.is_open()) {
            std::cerr << "Error opening file: " << argv[1] << std::endl;
            return 1;
        }

    }
    else{
        infile.open("/dev/stdin");
    }
    unsigned int pid;
    uint64_t data;

    // Main loop
    bool done = false;
#ifdef __EMSCRIPTEN__
    // For an Emscripten build we are disabling file-system access, so let's not attempt to do a fopen() of the imgui.ini file.
    // You may manually call LoadIniSettingsFromMemory() to load settings from your own storage.
    io.IniFilename = nullptr;
    EMSCRIPTEN_MAINLOOP_BEGIN
#else
    while (!done)
#endif
    {
        auto frame_start = SDL_GetTicks();
        auto next_frame = frame_start + 20; //20ms per frame, 50 FPS
        auto items_per_frame = 0;
        // Read data from the file
        int timeout_ms = (next_frame - SDL_GetTicks());
        do{
            if (!get_candump_data(infile, timeout_ms, pid, data)) {
                done = true;
                break;
            }
            model.process(pid, data);
            items_per_frame++;
            timeout_ms = (next_frame - SDL_GetTicks());
        } while(timeout_ms > 0 );
        //while(SDL_GetTicks() < next_frame) {}
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                done = true;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
                done = true;
        }
        if (SDL_GetWindowFlags(window) & SDL_WINDOW_MINIMIZED)
        {
            SDL_Delay(10);
            continue;
        }

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        {
            ImGui::Begin("Dashboard");

            ImGui::Text("items per frame = %d", items_per_frame);
            char buf[128];
            sprintf(buf, "%.1fA", model.battery_amps);
            float batt_amps = 0.25f + model.battery_amps / 100.0f; // Scale battery SOC to a range of 0.25 to 1.0
            ImGui::ProgressBar(batt_amps, ImVec2(0.0f, 0.0f), buf);

            sprintf(buf, "%.1fV", model.battery_voltage);
            float batt_volts =  model.battery_voltage / 370.0f;
            ImGui::ProgressBar(batt_volts, ImVec2(0.0f, 0.0f), buf);


            sprintf(buf, "%.1f%%", model.battery_soc_1);
            ImGui::ProgressBar(model.battery_soc_1 / 100.0f, ImVec2(0.0f, 0.0f), buf);

            float cells[88];
            int c = 0;
            for (int i = 0; i < 96; i++) {
                if(model.cell_voltages[i] > 2.1f){
                    cells[c] = model.cell_voltages[i];
                    c++;
                    if(c >= 88) {
                        break; // Limit to 88 cells
                    }
                }
            }
            float cell_average = 0.0f;
            for (int i = 0; i < 88; i++) {
                cell_average += cells[i];
            }
            cell_average /= 88.0f;
            sprintf(buf, "Cell Voltages\nAvg: %.3fV\nMin: %.3fV\nMax: %.3fV\nDiff: %.3fV", cell_average, model.cell_min_voltage, model.cell_max_voltage, model.cell_max_voltage - model.cell_min_voltage);
            ImGui::PlotHistogram(buf, cells, IM_ARRAYSIZE(cells), 0, "Volts", 2.0f, 4.3f, ImVec2(0, 180.0f));

            

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            ImGui::End();
        }


        // Rendering
        ImGui::Render();
        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }
#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_MAINLOOP_END;
#endif

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
