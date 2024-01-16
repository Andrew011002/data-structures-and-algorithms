#ifndef HASHMAP_HPP
#define HASHMAP_HPP
#include <vector>
#include <array>
#include <utility>
#include <optional>
#include "../linkedlist/doubly.hpp"

template <typename K, typename V>
class HashMap {
    int map_size = 0;
    int map_capacity = 19;
    std::array<DoublyList<std::pair<K, std::optional<V>>>*, 19> data;

public:
    HashMap();
    HashMap(const std::vector<std::pair<K, V>> &vec);
    int hash(K key);
    void rehash();
    void add(K key, V value);
    void add(K key);
    std::optional<V> get(K key);
    void remove(K key);
    bool contains(K key);
    std::vector<K> keys();
    std::vector<V> values();
    std::vector<std::pair<K, V>> items();
    bool empty();
    int size();
    int capacity();
    void print();
};

#include "hashmap.tpp"

#endif