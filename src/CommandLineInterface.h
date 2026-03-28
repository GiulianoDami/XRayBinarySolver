cpp
#ifndef COMMAND_LINE_INTERFACE_H
#define COMMAND_LINE_INTERFACE_H

#include <string>
#include <vector>
#include "BinarySystemParams.h"

class CommandLineInterface {
public:
    static void parseArguments(int argc, char* argv[], BinarySystemParams& params);
    static void printUsage(const char* programName);
};

#endif // COMMAND_LINE_INTERFACE_H