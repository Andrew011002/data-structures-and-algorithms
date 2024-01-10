#ifndef HASHSET_HPP
#define HASHSET_HPP 

#include "vector"
#include "array"
#include "../utils/node.hpp"
#include "../linkedlist/doubly.hpp"

template <typename T>
class HashSet {
    std::vector<DoublyList<T>> data;
    int n_elements;
    int max_elements;

public:
    HashSet();
    HashSet(const T arr[], int size);
    template <size_t N>
    HashSet(const std::array<T, N> arr);
    HashSet(const std::vector<T> vec);
    int hash(T item);
    void rehash();
    void add(T item);
    void remove(T item);
    bool contains(T item);
    bool issub(const T arr[], int size);
    template <size_t N>
    bool issub(const std::array<T, N> arr);
    bool issub(const std::vector<T> vec);
    bool empty();
    int size();
    void print();
};

#include "hashset.tpp"
#endif