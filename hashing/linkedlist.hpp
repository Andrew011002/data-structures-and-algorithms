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
    HashSetNode<T>* head;
    HashSetNode<T>* tail;

public:
    HashSetList();
    T get(int index) const;
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
    HashMapNode<T, U>* head;
    HashMapNode<T, U>* tail;

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