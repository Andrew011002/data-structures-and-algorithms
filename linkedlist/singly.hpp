#ifndef SINGLY_LIST_HPP
#define SINGLY_LIST_HPP
#include "./node.hpp"

template <typename T>

struct SinglyList {

protected:
    int list_size;
    Node<T>* head;
    Node<T>* tail;

public:
    SinglyList();
    void add(T item);
    void insert(T item, int index);
    void remove(T item);
    // void overwrite(T item, T item);
    // bool contains(T item);
    int size();
    bool empty();
    void print();
};

#endif