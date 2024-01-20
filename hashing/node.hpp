#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node {
private:
    T _value;

public:
    Node<T> *next;

    Node(T value) {
        _value = value;
        next = nullptr;
    }


    T get() const {
        return _value;
    }

    void set(T value) {
        _value = value;
    } 
};

template <typename T, typename U>
class NodeKV {
private:
    T _key;
    U _value;

public:
    NodeKV<T, U>* next;

    NodeKV(T item, U data) {
        _key = item;
        _value = data;
        next = nullptr;
    }
    
    T key() const {
        return _key;
    }
    
    U value() const {
        return _value;
    }

    void setkey(T item) {
        _key = item;
    }

    void setval(U data) {
        _value = data;
    }

    void setall(T item, U data) {
        _key = item;
        _value = data;
    }
};

#endif