#include "linked-list.h"

template <typename T>
LinkedList<T>::Node:: Node() : data(0), next(nullptr){

}
template <typename T>
LinkedList<T>::Node::Node(const T& element) : data(element), next(nullptr) {

}
template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& other) {
    if (other.first == nullptr) {
        first = nullptr;
        return;
    }
    first = new Node{other.first->data};
    Node* temp = first;
    Node* otherTemp = other.first->next;
    while(otherTemp != nullptr) {
        temp->next = new Node{otherTemp->data};
        temp = temp->next;
        otherTemp = otherTemp->next;
    }
    count = other.count;
}
template <typename T>
void LinkedList<T>::erase() {
    if (first == nullptr) {
        return;
    }
    Node* holder = first->next;
    while(holder != nullptr) {
        delete first;
        first = holder;
        holder = holder->next;
    }
    delete first;
}
template <typename T>
void LinkedList<T>::printHelper(Node* first) const {
    if (first == nullptr) {
        std::cout << "nullptr\n";
        return;
    }
    std::cout << first->data << " -> ";
    printHelper(first->next);
}
template <typename T>
LinkedList<T>::LinkedList() : first(nullptr), count(0) {}
template <typename T>
LinkedList<T>::LinkedList(const T& element) : first(new Node(element)), count(1) {}
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) { 
    copy(other);
}
template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>&& other) noexcept : first(nullptr), count(0) {
    copy(other);

    other->first = nullptr;
    other->count = 0;
}
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
    if (this != &other) {
        erase();
        copy(other);
    }

    return *this;
}
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& other) noexcept {
    
    if (this != &other) {
        erase();
        copy(other);

        other.first = nullptr;
        other.count = 0;
    }

    return *this;
}
template <typename T>
LinkedList<T>::~LinkedList() {
    erase();
}
template <typename T>
T LinkedList<T>::front() const {
    return *begin();
}
template <typename T>
T LinkedList<T>::back() const {
    return *end();
}
template <typename T>
void LinkedList<T>::pushFront(const T& element) {
    first = new Node(element);
    ++count;
}
template <typename T>
void LinkedList<T>::popFront() {
    if (first == nullptr) {
        count = 0;
        return;
    }
    Node* holder = first;
    first = first->next;
    delete holder;
    --count;
}
template <typename T>
void LinkedList<T>::pushBack(const T& element) {
    if(first == nullptr) {
        pushFront(element);
        return;
    }
    
    Node* temp = first;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    
    temp->next = new Node(element);
    ++count;
}
template <typename T>
void LinkedList<T>::popBack() {
    if(first == nullptr) {
        count = 0;
        return;
    }

    Node* prev = nullptr;
    Node* curr = first;
    while(curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }

    if(prev != nullptr){
        prev->next = nullptr;
    }
    
    delete curr; 
    --count;
}
template <typename T>
void LinkedList<T>::print() const {
    printHelper(first);
}
template <typename T>
void LinkedList<T>::reverse() {
    Node* holder = first;
    Node* temp = nullptr;
    Node* prev = nullptr;
    
    while (holder != nullptr) {
        temp = holder->next;
        holder->next = prev;
        prev = holder;
        holder = temp;
    }
    
    first = prev;
}
template <typename T>
LinkedList<T>::Iterator::Iterator(Node* node) : current(node) {}
template <typename T>
T& LinkedList<T>::Iterator::operator*() const {
    return current->data;
}
template <typename T>
T* LinkedList<T>::Iterator::operator->() const {
    return &(current->data);
}
template <typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++() {
    if (current) {
        current = current->next;
    }
    
    return *this;
}
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    ++(*this);
    
    return temp;
}
template <typename T>
bool LinkedList<T>::Iterator::operator==(const Iterator& other) const {
    return current == other.current;
}
template <typename T>
bool LinkedList<T>::Iterator::operator!=(const Iterator& other) const {
    return !(*this == other);
}
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() const {
    return Iterator(first);
}
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end() const {
    Node* temp = first;
    while (temp != nullptr && temp->next != nullptr) {
        temp = temp->next;
    }
    
    return Iterator(temp);
}
template <typename T>
size_t LinkedList<T>::size() const {
    return count;
}
template <typename T>
bool LinkedList<T>::isEmpty() const {
    return count == 0;
}