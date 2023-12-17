#include "student.h"

Specialty Student::getSpecialty(std::string specialtyName) {
    if(specialtyName == "Fraud") {
        return FRAUD;
    } else if(specialtyName == "International Schemes") {
        return INTERNATIONAL_SCHEMES;
    } else if(specialtyName == "Creative Nihilism") {
        return CREATIVE_NIHILISM;
    } else if (specialtyName == "Subjectives Researches") {
        return SUBJECTIVE_RESEARCHES;
    } else if (specialtyName == "File Analizis") {
        return FILE_ANALIZIS;
    } else if (specialtyName == "Micromanagement") {
        return MICROMANAGMENT;
    } else if (specialtyName == "Applied Materialization") {
        return APPLIED_MATERIALIZATION;
    } else if (specialtyName == "Subjectivistics") {
        return SUBJECTIVISTICS;
    } else if (specialtyName == "Magnetism and Clearing") {
        return MAGNETISM_AND_CLEARING;
    } else {
        return DEFAULT;
    }
}

Student::Student(size_t facultyNumber, size_t arrivalMinute, std::string specialtyName, size_t enthusiasm) {
    this->facultyNumber = facultyNumber;
    this->arrivalMinute = arrivalMinute;
    this->speciality = getSpecialty(specialtyName);
    this->enterMinute = 0;
    this->enthusiasm = enthusiasm;
}

bool Student::operator==(const Student& other) const {
    return facultyNumber == other.facultyNumber && arrivalMinute == other.arrivalMinute 
        && speciality == other.speciality && enthusiasm == other.enthusiasm;
}
bool Student::operator!=(const Student& other) const {
    return !operator==(other);
}

void Student::setEnterMinute(size_t enterMinute) {
    this->enterMinute = enterMinute;
}

Specialty Student::getSpecialty() const {
    return speciality;
}
size_t Student::getFacultyNumber() const {
    return facultyNumber;
}
size_t Student::getEnterMinute() const {
    return enterMinute;
}