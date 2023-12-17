#pragma once
#ifndef INPUT_VALIDATOR_H
#define INPUT_VALIDATOR_H

#include "input-parser.h"

class InpuValidator {
public:
    // validate specialty
    static bool validateSpecialty(std::string specialtyName) {
        return !specialtyName.empty() 
            && (specialtyName == "Fraud" || specialtyName == "International Schemes" 
            || specialtyName == "Creative Nihilism" || specialtyName == "Subjectives Researches"
            || specialtyName == "File Analizis" || specialtyName == "Micromanagement" 
            || specialtyName == "Applied Materialization" || specialtyName == "Subjectivistics" 
            || specialtyName == "Magnetism and Clearing");
    }

    // validate facultyNumber
    static bool validateFacultyNumber(size_t facultyNumber) {
        return facultyNumber <= 999999999;
    }

    // validate first c0mmand line
    static bool validateFirstCmdRow(std::string cmdRow) {
        bool isValid = !cmdRow.empty();
        if(isValid) {
            for (size_t i = 0; i < cmdRow.length(); ++i) {
                if((cmdRow[i] < '0' || '9' < cmdRow[i]) && cmdRow[i] != ' ') {
                    return false;
                }
            }
        }

        return isValid;
    }

    // validate basic command line with student information
    static bool validateCmdRow(std::string cmdRow) {
        size_t fn = 0, arrivalMin = 0, enthusiasm = 0;
        std::string spec = "";

        InputParser::parseArgs(cmdRow, fn, arrivalMin, spec, enthusiasm);
        return validateFacultyNumber(fn) && validateSpecialty(spec);
    }

    // validate students information lines
    static bool validateNextNCmdRows(LinkedList<std::string> rows, size_t rowsCount) {
        bool isValid = rows.size() == rowsCount;
        if(isValid) {
            for(LinkedList<std::string>::Iterator it = rows.begin(); it != rows.end(); ++it) {
                if(!isValid) {
                    return false;
                }
                isValid = validateCmdRow(*it);
            }
        }

        return isValid;
    }

    // validate full input
    static bool validate(std::string firstCmdRow, LinkedList<std::string> cmdRows, size_t cmdRowsCount) {
        return validateFirstCmdRow(firstCmdRow) && validateNextNCmdRows(cmdRows, cmdRowsCount);
    }
};

#endif