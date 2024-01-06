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
DoublyList<T>::DoublyList(const T arr[], int arr_size):DoublyList() {
    for (int i=0; i < arr_size; i++) {
        add(arr[i]);
    }
}

template <typename T>
DoublyList<T>::DoublyList(const std::vector<T> &vec):DoublyList() {
    for (T item: vec) {
        add(item);
    }
} 

template <typename T>
template <size_t N>
DoublyList<T>::DoublyList(const std::array<T, N> &arr):DoublyList() {
    for (T item: arr) {
        add(item);
    }
}

template <typename T>
void DoublyList<T>::add(T item) {
    if (size() == 0) {
        head = new Node<T>(item);
        tail = head;
    } else {
        Node<T> *node = new Node<T>(item);
        tail->next = node;
        node->prev = tail;
        tail = tail->next;
    }
    list_size++;
}

template <typename T>
int DoublyList<T>::size() {
    return list_size;
}

template <typename T>
void DoublyList<T>::print() {
    std::cout << "[ ";
    Node<T> *node = head;
    while (node) {
        std::cout << node->str() << " ";
        node = node->next;
    }
    std::cout << "]\n";
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    DoublyList<int> list = DoublyList<int>(vec);
    list.print();
    printf("%d\n", list.size());
}