#ifndef HASHMAP_HPP
#define HASHMAP_HPP
#include <vector>
#include <array>
#include <utility>
#include <optional>
#include "linkedlist.hpp"

const int MAX_LIST_SIZE = 10;
const int INITIAL_CAPACITY = 5;

template <typename T, typename U>
class HashMap {
    int map_size = 0;
    int map_capacity = INITIAL_CAPACITY;
    const int max_list_size = MAX_LIST_SIZE;
    LinkedListKV<T, U>** lists = new LinkedListKV<T, U>*[INITIAL_CAPACITY];

public:
    HashMap();
    HashMap(const std::vector<T> &vec);
    HashMap(const std::vector<std::pair<T, U>> &vec);
    int hash(T key) const;
    void rehash();
    void add(T key, U value);
    void add(T key);
    std::optional<U> get(T key) const;
    void remove(T key);
    bool contains(T key) const;
    void replace(T key, U value);
    std::vector<T> keys() const;
    std::vector<U> values() const;
    std::vector<std::pair<T, std::optional<U>>> items() const;
    bool empty() const;
    int size() const;
    int capacity() const;
    void print() const;
};

#include "hashmap.tpp"
#endif