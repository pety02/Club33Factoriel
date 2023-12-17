#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "specialty.h"
#include <exception>
#include <stdexcept>

class Student {
private:
    size_t facultyNumber;
    size_t arrivalMinute;
    Specialty speciality;
    size_t enterMinute;
    size_t enthusiasm;

    Specialty getSpecialty(std::string specialtyName);
public:
    Student(size_t facultyNumber, size_t arrivalMinute, std::string specialtyName, size_t enthusiasm);
    
    bool operator==(const Student& other) const;
    bool operator!=(const Student& other) const;

    void setEnterMinute(size_t enterMinute);

    Specialty getSpecialty() const;
    size_t getFacultyNumber() const;
    size_t getEnterMinute() const;
};

#endif