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
    list.insert(9, 0);
    printf("size: %d\n", list.size());
    list.print();
    list.remove(18);
    printf("size: %d\n", list.size());
    list.print();
    list.remove(5);
    printf("size: %d\n", list.size());
    list.print();
    list.remove(9);
    printf("size: %d\n", list.size());
    list.print();
    list.add(15);
    list.print();
    printf("%d\n", list.contains(10));
    for (int i=0; i < 10; i++) {
        list.add(i * i);
    }
    list.print();
    printf("%d\n", list.get(0));
    printf("%d\n", list.get(3));
    printf("%d\n", list.get(10));
    printf("%d\n", list.get(5));
}