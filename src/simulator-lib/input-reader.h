#pragma once
#ifndef INPUT_READER_H
#define INPUT_READER_H

#include "bar.h"

class InputReader {
public:
    // read all command lines
    static void readCmdLines(std::string& firstCmdLine, LinkedList<std::string>& cmds, size_t& rowsCount, std::istream& input) {
        std::string line = "";

        while (std::getline(input, line)) {
            cmds.pushFront(line);
        }
    }
};

#endif