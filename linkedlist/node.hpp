#ifndef NODE_HPP
#define NODE_HPP
#include <string>

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
    
    string str() {
        return std::to_string(val);
    }
};

#endif
