#include <iostream>
#include "../utils/node.hpp"
#include "./singly.hpp"

template <typename T>
SinglyList<T>::SinglyList() {
    list_size = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
T SinglyList<T>::get(int index) {
    if (empty()|| index >= size() || index < 0) {
        throw std::exception();
    }
    Node<T>* node = head;
    for (int i=0; i < index; i++) {
        node = node->next;
    }
    return node->val;
}

template <typename T>
void SinglyList<T>::add(T item) {
    Node<T>* node = new Node<int>(item);
    if (head == nullptr) {
        head = node;
        tail = head;
    }  else {
        tail->next = node;
        tail = tail->next;
    }
    list_size++;
}

template <typename T>
void SinglyList<T>::insert(T item, int index) {
    if (index > size()) {
        throw std::exception();
    }
    if (index == size()) {
        add(item);
        return;
    }
    if (index == 0) {
        Node<T>* next_node = head;
        head = new Node<T>(item);
        head->next = next_node;
    } else {
        Node<T>* node = head;
        for (int i=0; i < index - 1; i++) {
            node = node->next;
        }
        Node<T>* next_node = node->next;
        node->next = new Node<T>(item);
        node->next->next = next_node;
    }
    list_size++;
}

template <typename T>
void SinglyList<T>::remove(T item) {
    bool not_found = true;
    Node<T>* previous_node = nullptr;
    Node<T>* node = head;
    while (node != nullptr) {
        if (node->val == item) {
            not_found = false;
            break;
        }
        previous_node = node;
        node = node->next;
    }
    if (not_found) {
        throw std::exception();
    }
    if (node == head && head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else if (node == head) {
        Node<T>* next_node = head->next;
        delete head;
        head = next_node;
    } else {
        previous_node->next = node->next;
        delete node;
    }
    list_size--;
}

template <typename T>
bool SinglyList<T>::contains(T item) {
    if (empty()) {
        throw std::exception();
    }
    Node<T>* node = head;
    while (node != nullptr) {
        if (node->val == item) {
            return true;
        }
        node = node->next;
    }
    return false;
}

template <typename T>
int SinglyList<T>::indexof(T item) {
    if (empty()) {
        throw std::exception();
    }
    int index = 0;
    int curr = 0;
    Node<T>* node = head;
    while (node != nullptr) {
        if (node->val == item) {
            return index;
        }
        node = node->next;
        index++;
    }
    return -1;
}

template <typename T>
void SinglyList<T>::overwrite(T item, int index) {
    if (empty() || index < 0 || index >= size()) {
        throw std::exception();
    }
    Node<T>* node = head;
    for (int i=0; i < index; i++) {
        node = node->next;
    }
    node->val = item;
}

template <typename T>
int SinglyList<T>::size() {
    return list_size;
}

template <typename T>
bool SinglyList<T>::empty() {
    return list_size == 0;
}

template <typename T>
void SinglyList<T>::print() {
    std::cout << "[ ";
    Node<T>* node = head;
    while (node != nullptr) {
        std::cout << node->str() << " ";
        node = node->next;
    }
    std::cout << "]\n";
}
