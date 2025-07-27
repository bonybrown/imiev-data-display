#include "parser.h"
#include <iostream>
#include <sstream>
#include <string>
#include <sys/select.h>
#include <unistd.h>
#include <algorithm>

int Parser::read_candump_data(std::ifstream &infile, int timeout_ms, unsigned int &pid, uint64_t &data)
{

    int fd = fileno(stdin);
    std::string interface, pidstr, bytes;
    struct timeval tv;
    tv.tv_sec = 0;                  // 0 second timeout
    tv.tv_usec = timeout_ms * 1000; // milliseconds -> usec timeout
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(fd, &fds);
    int ret = select(fd + 1, &fds, NULL, NULL, &tv);
    if (ret <= 0)
    {
        // Timeout or error
        return 1;
    }

    infile >> interface >> pidstr >> bytes; // Read the first line
    if (infile.eof())
    {
        return 0; // End of file reached
    }
    int bytecount = bytes[1] - '0'; // Get the byte count from the second character [n]
    std::string candata;
    if (!std::getline(infile, candata))
    {
        return 0; // End of file or error
    }
    candata.erase(std::remove_if(candata.begin(), candata.end(), ::isspace), candata.end());
    pid = std::stoul(pidstr, nullptr, 16);    // convert pid field to uint16_t
    data = std::stoull(candata, nullptr, 16); // Convert the rest to uint64_t
    data <<= ((8 - bytecount) * 8);           // shift left as required so first bit is in the MSB of the 64-bit unsigned value
    // data = htole64(data); // Convert to little-endian format
    return 1; // Success
}
