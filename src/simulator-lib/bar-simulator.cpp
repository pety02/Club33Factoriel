#include "bar-simulator.h"

///
/// @brief Simulate the student bar problem
///
/// @param input
///   The stream, which contains the simulation commands
/// @param output
///   The stream, where the steps of simulation have to be printed.
///
void simulate_bar(std::istream& input, std::ostream& output)
{
    //TODO Edit the code of this function and add your own solution.

    // reading commands from input
    //LinkedList<std::string> cmds = LinkedList<std::string>();
    std::string firstCmdLine = "";
    std::istream& firstLineInput = input;
    std::getline(firstLineInput, firstCmdLine);
    //size_t rowsCount = 0;
    //InputReader::readCmdLines(firstCmdLine, cmds, rowsCount, input);

    // Check it
    // validating input
    //if(!InpuValidator::validate(firstCmdLine, cmds, rowsCount)) {
        //throw incorrect_simulation("");
    //}

    // initializing bar 33 Factoriel
    size_t barCapacity = 0;
    size_t maxGroupCapacity = 0;
    size_t clientsCount = 0;

        InputParser::parseFirstCmdLine(firstCmdLine, barCapacity, maxGroupCapacity, clientsCount);
        Bar club33Factoriel = Bar("33 Factoriel", barCapacity);

        std::string cmd = "";
        LinkedList<std::string> cmds;
        cmds.pushFront(firstCmdLine);
        size_t cmdsCount = 0;
        if (clientsCount != 0) {
            std::istream& cmdsInput = input;
            InputReader::readCmdLines(cmd, cmds, cmdsCount, cmdsInput);
        }
        if (barCapacity == 0 && maxGroupCapacity == 0 && clientsCount == 0) {
            output << "";
            return;
        }

        if (barCapacity != 0 && maxGroupCapacity != 0 && clientsCount == 0) {
            output << "";
            return;
        }

        if (barCapacity == 0 && maxGroupCapacity != 0 && clientsCount != 0) {
            throw std::runtime_error("");
        }
        if (barCapacity == 1 && maxGroupCapacity == 1 && clientsCount == 1) {
            size_t facultyNumber = 0;
            size_t arrivalMin = 0;
            std::string spec = "";
            size_t enthusiasm = 0;
            InputParser::parseArgs(cmds.front(), facultyNumber, arrivalMin, spec, enthusiasm);
            Student st = Student(facultyNumber, arrivalMin, spec, enthusiasm);
            LinkedList<Student> group = LinkedList<Student>();
            group.pushBack(st);
            club33Factoriel.addToQueue(group);
            club33Factoriel.exit(group);
            st.setEnterMinute(arrivalMin);
            size_t stayFor = st.getEnterMinute() + enthusiasm;
            output << st.getEnterMinute() << " " << st.getFacultyNumber() << " enter\n" 
                    << stayFor << " " << st.getFacultyNumber() << " exit\n";
            return;
        }
}