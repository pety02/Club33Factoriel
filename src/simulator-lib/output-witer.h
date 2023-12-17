#pragma once
#ifndef OUTPUT_WRITER_H
#define OUTPUT_WRITER_H

class OutputWriter {
public:
    static void writeResult(std::string result, std::ostream& output) {
        output << result;
    }
};

#endif