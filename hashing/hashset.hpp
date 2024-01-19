#ifndef HASHSET_HPP
#define HASHSET_HPP 

#include <vector>
#include <iostream>
#include "linkedlist.hpp"

const int MAX_LIST_SIZE = 10;
const int INITIAL_CAPACITY = 19;

template <typename T>
class HashSet {
private:
    int set_size = 0;
    int set_capacity = INITIAL_CAPACITY;
    const int max_list_size = MAX_LIST_SIZE;
    LinkedList<T>** lists = new LinkedList<T>*[INITIAL_CAPACITY];

public:
    HashSet();
    HashSet(const std::vector<T> &vec);
    int hash(T item) const;
    void rehash();
    void add(T item);
    void remove(T item);
    bool contains(T item) const;
    bool issub(const std::vector<T> &vec) const;
    HashSet<T> intersectof(const std::vector<T> &vec) const;
    HashSet<T> unionof(const std::vector<T> &vec) const;
    bool empty() const;
    int size() const;
    int capacity() const;
    void print() const;
};

#include "hashset.tpp"
#endif