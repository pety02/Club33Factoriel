#pragma once
#ifndef BAR_H
#define BAR_H

#include "linked-list.h"
#include "student.h"

class Bar {
private:
    std::string name;
    size_t maxCapacity;
    size_t currentCount;
    LinkedList<LinkedList<Student>> queue;
    LinkedList<LinkedList<Student>> clients;

    void incrementCurrentCount(size_t steps);
    void decrementCurrentCount(size_t steps);
public:
    Bar(std::string name, size_t maxCapacity);
    const LinkedList<LinkedList<Student>> getQueue() const;
    size_t getMaxCapacity() const;
    size_t getCurrentCount() const;
    const LinkedList<LinkedList<Student>> getClients() const;

    void addToQueue(const LinkedList<Student>& group);
    void removeFromQueue(const LinkedList<Student>& group);
    void exit(const LinkedList<Student>& group);
};

#endif