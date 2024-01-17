#ifndef DOUBLY_LIST_HPP
#define DOUBLY_LIST_HPP

#include <array>
#include <iostream>
#include <vector>
#include "node.hpp"

template <typename T>
struct DoublyList {

private:
    Node<T>* head;
    Node<T>* tail;
    int list_size;

public:
    DoublyList();
    DoublyList(const T arr[], int size);
    DoublyList(const std::vector<T> &vec);
    template <size_t N>
    DoublyList(const std::array<T, N> &arr);
    void add(T item);
    void add_head(T item);
    void insert(T item, int index);
    Node<T>* get_node(int index);
    T get(int index);
    void write(T item, int index);
    bool contains(T item);
    int indexof(T item);
    void remove_head();
    void remove_tail();
    void remove(T item, int count);
    void remove(T item);
    void replace(T item, T with, int count);
    void replace(T item, T with);
    bool empty();
    int size();
    void clear();
    void print();
};

template <typename T, typename U>
struct DoublyList {

private:
    Node<T, U> *head;
    Node<T, U> *tail;
    int list_size;

public:
    DoublyList();
    DoublyList(const T arr[], int size);
    DoublyList(const std::vector<T> &vec);
    template <size_t N>
    DoublyList(const std::array<T, N> &arr);
    void add(T item);
    void add_head(T item);
    void insert(T item, int index);
    Node<T>* get_node(int index);
    T get(int index);
    void write(T item, int index);
    bool contains(T item);
    int indexof(T item);
    void remove_head();
    void remove_tail();
    void remove(T item, int count);
    void remove(T item);
    void replace(T item, T with, int count);
    void replace(T item, T with);
    bool empty();
    int size();
    void clear();
    void print();
};
#include "doubly.tpp"
#endif