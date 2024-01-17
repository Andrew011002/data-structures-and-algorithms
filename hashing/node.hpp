#ifndef NODE_HPP
#define NODE_HPP
#include <string>
#include <format>

template <typename T>
class Node {
public:
    T value;
    Node<T>* prev;
    Node<T>* next;

    Node(T val) {
        value = val;
        prev = nullptr;
        next = nullptr;
    }
    
    std::string str() {
        return std::to_string(val);
    }
};

template <typename T, typename U>
class Node {
public:
    T key;
    U value;
    Node<T, U>* prev;
    Node<T, U>* next;

    Node(T key, U val) {
        key = key;
        value = val;
        prev = nullptr;
        next = nullptr;
    }
    
    std::string str() {
        std::string s = "{";
        std::string info = std::format("({}: {})", std::to_string(key), std::to_string(value));
        s.append(info);
        s.append("}");
        return s;
    }
};

#endif