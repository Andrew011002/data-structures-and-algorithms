#include <iostream>
#include "./node.hpp"
#include "./singly.hpp"

template <typename T>
SinglyList<T>::SinglyList() {
    list_size = 0;
    head = nullptr;
    tail = nullptr;
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
    if (index == size()) {
        add(item);
        return;
    }
    if (index > size()) {
        throw std::exception();
    }
    
    if (index == 0) {
        Node<T>* old_head = head;
        head = new Node<T>(item);
        head->next = old_head;
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

int main() {
    SinglyList<int> list = SinglyList<int>();
    list.add(5);
    list.add(18);
    list.insert(9, 3);
    list.print();
}