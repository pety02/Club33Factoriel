#pragma once
#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

class InputParser {
public:
    // checks wheather an argument contains only digits in case of number argument
    static bool containsOnlyDigits(std::string arg) {
        for (size_t i = 0; i < arg.length(); ++i) {
            if(arg[i] < '0' || '9' < arg[i]) {
                return false;
            }   
        }

        return true;
    }
    
    // parse other command lines
    static void parseFirstCmdLine(std::string firstCmdLine, size_t& barCapacity, size_t& maxGroupCapacity, size_t& nextRowsCount) {
        std::string currArg = "";
        size_t argsCounter = 0;
        for (int i = 0; i <= firstCmdLine.length(); ++i) {
            if(firstCmdLine[i] != '\0' && firstCmdLine[i] != ' ') {
                currArg += firstCmdLine[i];
            } else {
                if(argsCounter == 0) {
                    barCapacity = std::stoul(currArg);
                } else if (argsCounter == 1) {
                    maxGroupCapacity = std::stoul(currArg);
                } else if (argsCounter == 2) {
                    nextRowsCount = std::stoul(currArg);
                }

                ++argsCounter;
                currArg = "";
            }
        }
    
    }

    // parses arguments
    static void parseArgs(std::string cmdRow, size_t& fn, size_t& arrivalMin, std::string& spec, size_t& enthusiasm) {
        std::string currArg = "";
        size_t digitsArgCounter = 0;
        for(size_t i = 0; i <= cmdRow.length(); ++i) {
            if(cmdRow[i] != '\0' && cmdRow[i] != ' ') {
                currArg += cmdRow[i];
            } else {
                if(containsOnlyDigits(currArg) && digitsArgCounter == 0) {
                    fn = std::stoi(currArg);
                    ++digitsArgCounter;
                } else if (containsOnlyDigits(currArg) && digitsArgCounter == 1) {
                    arrivalMin = std::stoi(currArg);
                    ++digitsArgCounter;
                } else if (containsOnlyDigits(currArg) && digitsArgCounter == 2) {
                    enthusiasm = std::stoi(currArg);
                    ++digitsArgCounter;
                } else {
                    spec = currArg;
                }

                currArg = "";
            }
        }
    }
};

#endif