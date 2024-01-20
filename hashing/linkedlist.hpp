#ifndef SINGLY_LIST_HPP
#define SINGLY_LIST_HPP

#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include <stdexcept>
#include "node.hpp"

template <typename T>
class LinkedList {
private:
    int list_size;
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList();
    T get(int index) const;
    void add(T item);
    void remove(T item);
    bool contains(T item) const;
    int size() const;
    bool empty() const;
    void print() const;
};

template <typename T, typename U>
class LinkedListKV{
    int list_size;
    NodeKV<T, U>* head;
    NodeKV<T, U>* tail;

public:
    LinkedListKV();
    std::pair<T, U> get(int index) const;
    void add(T key, U value);
    void remove(T key);
    bool contains(T key) const;
    int size() const;
    bool empty() const;
    void print() const;
};

#include "linkedlist.tpp"
#endif