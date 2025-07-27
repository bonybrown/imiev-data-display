#include "dashboard.h"

void Dashboard::render(Model &model)
{
    ImGui::Begin("Dashboard");

    ImGui::Text("items per frame = %ld", model.pids_processed_this_update);
    char buf[128];
    float batt_charge = 0;
    float batt_discharge = 0;
    if (model.battery_amps < 0.0f) batt_discharge = -model.battery_amps;
    else batt_charge = model.battery_amps;
    sprintf(buf, "%.1fA", batt_charge);
    ImGui::ProgressBar(batt_charge / 100.0f, ImVec2(0.0f, 0.0f), buf);
    ImGui::SameLine();
    ImGui::Text("Battery Charge Amps");
    sprintf(buf, "%.1fA", batt_discharge);
    ImGui::ProgressBar(batt_discharge / 100.0f, ImVec2(0.0f, 0.0f), buf);
    ImGui::SameLine();
    ImGui::Text("Battery Discharge Amps");


    sprintf(buf, "%.1f%%", model.accelerator_pedal_percentage);
    ImGui::ProgressBar(model.accelerator_pedal_percentage / 100.0f, ImVec2(0.0f, 0.0f), buf);
    ImGui::SameLine();
    ImGui::Text("Accelerator Pedal");

    sprintf(buf, "%.1fV", model.battery_voltage);
    float batt_volts = model.battery_voltage / 370.0f;
    ImGui::ProgressBar(batt_volts, ImVec2(0.0f, 0.0f), buf);
    ImGui::SameLine();
    ImGui::Text("Battery Voltage");

    sprintf(buf, "%.1f%%", model.battery_soc_1);
    ImGui::ProgressBar(model.battery_soc_1 / 100.0f, ImVec2(0.0f, 0.0f), buf);
        ImGui::SameLine();
    ImGui::Text("Battery SOC");


    float cells[88];
    int c = 0;
    for (int i = 0; i < 96; i++)
    {
        if (model.cell_voltages[i] > 2.1f)
        {
            cells[c] = model.cell_voltages[i];
            c++;
            if (c >= 88)
            {
                break; // Limit to 88 cells
            }
        }
    }
    float cell_average = 0.0f;
    for (int i = 0; i < 88; i++)
    {
        cell_average += cells[i];
    }
    cell_average /= 88.0f;
    sprintf(buf, "Cell Voltages\nAvg: %.3fV\nMin: %.3fV\nMax: %.3fV\nDiff: %.3fV", cell_average, model.cell_min_voltage, model.cell_max_voltage, model.cell_max_voltage - model.cell_min_voltage);
    ImGui::PlotHistogram(buf, cells, IM_ARRAYSIZE(cells), 0, "Volts", 2.0f, 4.3f, ImVec2(0, 180.0f));

    //ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
    ImGui::End();
}