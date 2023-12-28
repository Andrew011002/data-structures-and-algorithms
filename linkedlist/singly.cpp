#include "./node.hpp"
#include "./singly.hpp"


template <typename T>
SinglyList<T>::SinglyList() {
    nelem = 0;
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
    nelem++;
}

template <typename T>
int SinglyList<T>::size() {
    return nelem;
}

template <typename T>
bool SinglyList<T>::empty() {
    return nelem == 0;
}

int main() {
    SinglyList<int> list = SinglyList<int>();
    list.add(5);
    list.add(18);
    printf("%d\n", list.size());
}