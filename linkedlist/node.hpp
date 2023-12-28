#ifndef NODE_HPP
#define NODE_HPP

template <typename T>

struct Node {
    T val;
    Node<T>* prev;
    Node<T>* next;

    Node(T value) {
        val = value;
        prev = nullptr;
        next = nullptr;
    }
};

#endif
