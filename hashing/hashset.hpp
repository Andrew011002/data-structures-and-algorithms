#ifndef HASHSET_HPP
#define HASHSET_HPP 

#include "vector"
#include "array"
#include "../utils/node.hpp"
#include "../linkedlist/doubly.hpp"

template <typename T>
class HashSet {

    std::vector<Node<T>> elements;
    int n_elements;

public:
    HashSet();
    HashSet(const T arr[], int size);
    HashSet(const std::array arr);
    HashSet(const std::vector vec);
    int hash(T item);
    void rehash();
    void add(T item);
    void remove(T item);
    bool contains(T item);
    bool issub(const T arr[], int size);
    bool issub(const T std::array);
    bool issub(const T std:vector);
    bool empty();
    int size();
    void print();
};

#endif