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
    Node<T> *node = get_node(index);
    Node<T> *new_node = new Node<T>(item);
    new_node->next = node;
    new_node->prev = node->prev;
    new_node->prev->next = new_node;
    new_node->next->prev = new_node;   
    list_size++;
}

template <typename T>
T DoublyList<T>::get(int index) {
    if (empty() || index > size()) {
        throw std::exception();
    }
    return get_node(index)->val;
}

template <typename T>
Node<T>* DoublyList<T>::get_node(int index) {
    if (empty() || index > size()) {
        throw std::exception();
    }
    if (index < 0) {
        index = index + size();
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
            node = node->prev;
        }
    } 
    return node;
}

template <typename T>
void DoublyList<T>::write(T item, int index) {
    if (empty() || index > size()) {
        throw std::exception();
    }
    Node<T> *node = get_node(index);
    node->val = item;
}

template <typename T>
bool DoublyList<T>::contains(T item) {
    if (empty()) {
        throw std::exception();
    }
    Node<T> *node = head;
    while (node) {
        if (node->val == item) {
            return true;
        }
        node = node->next;
    }
    return false;
}

template <typename T>
int DoublyList<T>::indexof(T item) {
    if (empty() || !contains(item)) {
        throw std::exception();
    }
    Node<T> *node = head;
    int index = 0;
    while (node) {
        if (node->val == item) {
            break;
        }
        node = node->next;
        index++;
    }
    return index;
}

template <typename T>
void DoublyList<T>::remove_head() {
    if (empty()) {
        throw std::exception();
    }
    if (size() == 1) {
        clear();
        return;
    } 
    head = head->next;
    delete head->prev;
    head->prev = nullptr;
    list_size--;
}

template <typename T>
void DoublyList<T>::remove_tail() {
    if (empty()) {
        throw std::exception();
    }
    if (size() == 1) {
        clear();
        return;
    } 
    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
    list_size--;
}

template <typename T>
void DoublyList<T>::remove(T item, int count) {
    if (empty() || !contains(item) || count < 0) {
        throw std::exception();
    }
    Node<T> *node = head;
}

template <typename T>
bool DoublyList<T>::empty() {
    return list_size == 0;
}

template <typename T>
int DoublyList<T>::size() {
    return list_size;
}

template <typename T>
void DoublyList<T>::clear() {
    delete head;
    head = nullptr;
    tail = nullptr;
    list_size = 0;
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
    for (int i=0; i < list.size(); i++) {
        list.write(list.get(i) * i, (i * i) % list.size());
    }
    list.print();
    printf("%d\n", list.size());
    list.clear();
    list.print();
    printf("%d\n", list.size());
    list.insert(0, -1);
    list.print();
}