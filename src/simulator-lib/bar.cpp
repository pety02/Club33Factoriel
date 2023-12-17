#include "bar.h"

void Bar::incrementCurrentCount(size_t steps) {
    currentCount += steps;
}
void Bar::decrementCurrentCount(size_t steps) {
    currentCount -= steps;
}

Bar::Bar(std::string name, size_t maxCapacity) {
    this->name = name;
    this->maxCapacity = maxCapacity;
    this->currentCount = 0;
    this->queue = LinkedList<LinkedList<Student>>();
    this->clients = LinkedList<LinkedList<Student>>();
}
const LinkedList<LinkedList<Student>> Bar::getQueue() const {
    return queue;
}
size_t Bar::getMaxCapacity() const {
    return maxCapacity;
}
size_t Bar::getCurrentCount() const {
    return currentCount;
}
const LinkedList<LinkedList<Student>> Bar::getClients() const {
    return clients;
}

void Bar::addToQueue(const LinkedList<Student>& group) {
    queue.pushBack(group);
}
void Bar::removeFromQueue(const LinkedList<Student>& group) {
    clients.pushBack(group);
    incrementCurrentCount(group.size());
    for(LinkedList<LinkedList<Student>>::Iterator groupIt = clients.begin(); groupIt != clients.end(); ++groupIt) {
        LinkedList<Student> currentGroup = *groupIt;
        //if(currentGroup. == group) {
            clients.popFront();
            //continue;
        //}
    }
}
void Bar::exit(const LinkedList<Student>& group) {
    for(LinkedList<LinkedList<Student>>::Iterator groupIt = clients.begin(); groupIt != clients.end(); ++groupIt) {
        //if((*groupIt) == group) {
            clients.popFront();
            continue;
        //}
    }
    decrementCurrentCount(group.size());
}