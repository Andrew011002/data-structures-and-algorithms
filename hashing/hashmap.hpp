#ifndef HASHMAP_HPP
#define HASHMAP_HPP
#include <vector>
#include <array>
#include <utility>
#include "../linkedlist/doubly.hpp"

template <typename K, typename V>
class HashMap {
    DoublyList<std::pair<K, V>> *data;
    int map_size;
    int map_capacity;

public:
    HashMap();
    HashMap(const std::pair<K, V>[] arr);
    template <size_t N>
    HashMap(const std::array<std::pair<K, V>, N> &arr);
    HashMap(const std::vector<std::pair<K, V>> &vec);
    int hash();
    void rehash();
    V get(K key);
    void remove(K key);
    bool contains(K key);
    K[] keys();
    template <size_t N> 
    std::array<K, N> keys();
    std::vector<K> keys();
    K[] values();
    template <size_t N> 
    std::array<K, N> values();
    std::vector<K> values();
    std::pair<K, V>[] items();
    template <size_t N> 
    std::array<std::pair<K, V>, N> values();
    std::vector<std::pair<K, V>> values();
    bool empty();
    int size();
    int capacity();
    void print();
};

#include "hashmap.tpp"

#endif