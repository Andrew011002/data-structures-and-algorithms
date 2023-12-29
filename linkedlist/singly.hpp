#ifndef SINGLY_LIST_HPP
#define SINGLY_LIST_HPP
#include "./node.hpp"

template <typename T>

struct SinglyList {

protected:
    int nelem;
    Node<T>* head;
    Node<T>* tail;

public:
    SinglyList();
    void add(T item);
    // void insert(int index, T item);
    // void remove(T item);
    // void overwrite(T item, T item);
    // bool contains(T item);
    void print();
    int size();
    bool empty();
};

#endif