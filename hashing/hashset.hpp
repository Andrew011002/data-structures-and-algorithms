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
    hash(T item);
    rehash();
    add(T item);
};

#endif