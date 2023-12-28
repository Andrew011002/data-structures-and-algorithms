#ifndef NODE_HPP
#define NODE_HPP

template <typename T>

struct Node {
    T val;
    Node* next;
    
    Node(T value) {
        val = value;
        next = nullptr;
    }
};

#endif