#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node {
public:
    T _value;
    Node<T>* next;

    Node(T value) {
        _value = value;
        next = nullptr;
    }

    T get() const {
        return _value
    } 
    
};

template <typename T, typename U>
class NodeKV {
public:
    T _key;
    U _value;
    NodeKV<T, U>* next;

    NodeKV(T item, U data) {
        _key = item;
        _value = data;
        next = nullptr;
    }
    
    U get() const {
        return _value;
    }
    
    T key() const {
        return _key;
    }
};

#endif