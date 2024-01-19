#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node {
public:
    T value;
    Node<T>* next;

    Node(T val) {
        value = val;
        next = nullptr;
    }
    
};

template <typename T, typename U>
class NodeKV {
public:
    T key;
    U value;
    NodeKV<T, U>* next;

    NodeKV(T key, U val) {
        key = key;
        value = val;
        next = nullptr;
    }
};

#endif