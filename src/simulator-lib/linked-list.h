#pragma once
#ifndef LINKED_LIST_H 
#define LINKED_LIST_H 

#include <iostream>

template <class T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node();
        Node(const T& element);
    };

    Node* first;
    size_t count;

private:
    void copy(const LinkedList& other);
    void erase();
    void printHelper(Node* first) const;

public:
    LinkedList();
    LinkedList(const T& element);
    LinkedList(const LinkedList& other);
    LinkedList(LinkedList&& other) noexcept;
    LinkedList& operator=(const LinkedList& other);
    LinkedList& operator=(LinkedList&& other) noexcept;
    ~LinkedList();

    T front() const;
    T back() const;

    void pushFront(const T& element);
    void popFront();
    void pushBack(const T& element);
    void popBack();
    void print() const;
    void reverse();

    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* node);
        T& operator*() const;
        T* operator->() const;
        Iterator& operator++();
        Iterator operator++(int);
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    };

    Iterator begin() const;
    Iterator end() const;

    size_t size() const;
    bool isEmpty() const;
};

#include "linked-list.inl"

#endif