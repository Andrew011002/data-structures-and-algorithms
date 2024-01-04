#include <iostream>
#include "./node.hpp"
#include "./doubly.hpp"

template <typename T>
DoublyList<T>::DoublyList() {
    head = nullptr;
    tail = nullptr;
    list_size = 0;
} 

template <typename T>
DoublyList<T>::DoublyList(const std::vector<T> &vec) {
    head = nullptr;
    tail = nullptr;
    list_size = 0;
} 

template <typename T>
template <size_t N>
DoublyList<T>::DoublyList(const std::array<T, N> &arr) {

}


