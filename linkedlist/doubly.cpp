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
void DoublyList<T>::add_head(T item) {
    if (size() == 0) {
        add(item);
        return;
    } 
    Node<T> *new_node = new Node<T>(item);
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
    list_size++;
}

template <typename T>
void DoublyList<T>::insert(T item, int index) {
    if (index > size()) {
        throw std::exception();
    }
    if (index == 0) {
        add_head(item);
        return;
    }
    if (index == size()) {
        add(item);
        return;
    }
    Node<T> *node = nullptr;
    if (index <= size() - index) {
        node = head;
        for (int i=0; i < index; i++) {
            node = node->next;
        }
    } else {
        node = tail;
        for (int i = size() - 1; i > index; i--) {
            std::cout << i << " " << node->str() << "\n";
            node = node->prev;
        }
    }
    insert_helper(node, new Node<T>(item));
    list_size++;
}

template <typename T>
void DoublyList<T>::insert_helper(Node<T> *node, Node<T> *new_node) {
    new_node->next = node;
    new_node->prev = node->prev;
    new_node->prev->next = new_node;
    new_node->next->prev = new_node;
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
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    DoublyList<int> list = DoublyList<int>(vec);
    list.print();
    list.insert(69, 4);
    list.print();
    list.insert(23, 6);
    list.print();
    list.insert(18, 0);
    list.print();
    list.insert(19, 13);
    list.print();
    printf("%d\n", list.size());
}