#ifndef SINGLY_LIST_HPP
#define SINGLY_LIST_HPP

#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include "node.hpp"

template <typename T>
class LinkedList {
private:
    int _size;
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList();
    LinkedList(const std::vector<T> &vec);
    T get(int index) const;
    void add(T item);
    void insert(T item, int index);
    void remove(T item);
    bool contains(T item) const;
    int indexof(T item) const;
    void overwrite(T item, int index);
    int size() const;
    bool empty() const;
    void print() const;
};

// template <typename T, typename U>
// class LinkedListKV{
//     int _size;
//     NodeKV<T, U>* head;
//     NodeKV<T, U>* tail;

// public:
//     LinkedListKV();
//     std::pair<T, U> get(int index);
//     void add(T item);
//     void add(T item, U data);
//     void insert(T item, int index);
//     void remove(T item);
//     bool contains(T item);
//     int indexof(T item);
//     void overwrite(T item, int index);
//     int size();
//     bool empty();
//     void print();
// };

#include "linkedlist.tpp"
#endif