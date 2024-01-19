#ifndef SINGLY_LIST_HPP
#define SINGLY_LIST_HPP

#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include <stdexcept>
#include "node.hpp"

template <typename T>
class HashSetList {
private:
    int _size;
    Node<T>* head;
    Node<T>* tail;

public:
    HashSetList();
    void add(T item);
    void remove(T item);
    bool contains(T item) const;
    int size() const;
    bool empty() const;
    void print() const;
};

template <typename T, typename U>
class HashMapList{
    int _size;
    NodeKV<T, U>* head;
    NodeKV<T, U>* tail;

public:
    HashMapList();
    U get(T key) const;
    void add(T key);
    void add(T key, U value);
    void remove(T key);
    bool contains(T key) const;
    bool containsval(U value) const;
    int size() const;
    bool empty() const;
    void print() const;
};

#include "linkedlist.tpp"
#endif