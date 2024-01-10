#ifndef SINGLY_LIST_HPP
#define SINGLY_LIST_HPP

#include <iostream>
#include <array>
#include <vector>
#include "../utils/node.hpp"

template <typename T>
struct SinglyList {

protected:
    int list_size;
    Node<T>* head;
    Node<T>* tail;

public:
    SinglyList();
    T get(int index);
    void add(T item);
    void insert(T item, int index);
    void remove(T item);
    bool contains(T item);
    int indexof(T item);
    void overwrite(T item, int index);
    int size();
    bool empty();
    void print();
};

#include "singly.tpp"
#endif