#include "model.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdint>
#include <endian.h> // for htobe64
#include <unistd.h> // for usleep

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

int main(int argc, char* argv[]) {
    Model model{};
    std::ifstream infile(argv[1]);
    unsigned int pid;
    uint64_t data;
    if (!infile.is_open()) {
        std::cerr << "Error opening file: " << argv[1] << std::endl;
        return 1;
    }
    std::cout << "\x1B[2J"; // Clear the screen
        
    //int i = 300;
    while( get_data(infile, pid, data) ) {
        // Process the data
        //std::cout << "PID: " << pid << ", Data: " << std::hex << data << std::dec << std::endl;
        model.process(pid, data);
        std::cout << "\x1B[0;0H"; // place cursor at home position
        model.dump();
        usleep(100);
    }
    
    //model.dump();
    return 0;
}
