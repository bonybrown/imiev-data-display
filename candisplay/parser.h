// parser.h
#pragma once

#include <fstream>
#include <cstdint>

class Parser
{
public:
    // Reads a line of CAN data from the input file stream, parses it, and returns the PID and data.
    // Returns 1 on success, 0 on end of file or error.
    static int read_candump_data(std::ifstream &infile, int timeout_ms, unsigned int &pid, uint64_t &data);
};