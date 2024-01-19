#ifndef HASHSET_HPP
#define HASHSET_HPP 

#include <vector>
#include <array>
#include <iostream>
#include "linkedlist.hpp"

const int INITIAL_CAPACITY = 19;

template <typename T>
class HashSet {
    std::array<HashSetList<T>*, INITIAL_CAPACITY> lists;
    int _size;
    int _capacity;

public:
    HashSet();
    HashSet(const T arr[], int size);
    template <size_t N>
    HashSet(const std::array<T, N> &arr);
    HashSet(const std::vector<T> &vec);
    int hash(T item);
    void rehash();
    void add(T item);
    void remove(T item);
    bool contains(T item);
    bool issub(const T arr[], int size);
    template <size_t N>
    bool issub(const std::array<T, N> &arr);
    bool issub(const std::vector<T> &vec);
    HashSet<T> intersectof(const T arr[], int size);
    template <size_t N>
    HashSet<T> intersectof(const std::array<T, N> &arr);
    HashSet<T> intersectof(const std::vector<T> &vec);
    HashSet<T> unionof(const T arr[], int size);
    template <size_t N>
    HashSet<T> unionof(const std::array<T, N> &arr);
    HashSet<T> unionof(const std::vector<T> &vec);
    bool empty();
    int size();
    int capacity();
    void print();
};

#include "hashset.tpp"
#endif