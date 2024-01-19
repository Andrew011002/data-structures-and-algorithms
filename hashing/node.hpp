#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class HashSetNode {
private:
    T _value;

public:
    HashSetNode<T> *next;

    HashSetNode(T value) {
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
class HashMapNode {
private:
    T _key;
    U _value;

public:
    HashMapNode<T, U>* next;

    HashMapNode(T item, U data) {
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