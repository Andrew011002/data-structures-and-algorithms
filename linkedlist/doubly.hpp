#ifndef DOUBLY_LIST_HPP
#define DOUBLY_LIST_HPP
#include "./node.hpp"

template <typename T>
struct DoublyList {

private:
    Node<T>* head;
    Node<T>* tail;
    int list_size;

public:
    DoublyList();
    DoublyList(const std::vector<T> &vec);
    template <size_t N>
    DoublyList(const std::array<T, N> &arr);
    DoublyList(const int[] arr, int size);
    void add(T item);
    void insert(T item, int index);
    T get(int index);
    int indexof(T item);
    bool contains(T item);
    void remove(T item);
    void replace(T item, T other);
    void write(T item, int index);
    void clear();
    bool empty();
    void print();
};

#endif