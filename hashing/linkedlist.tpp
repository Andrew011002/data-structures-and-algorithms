template <typename T>
LinkedList<T>::LinkedList() {
    _size = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
T LinkedList<T>::get(int index) {
    if (empty()|| index >= size() || index < 0) {
        throw std::exception();
    }
    Node<T>* node = head;
    while (index > 0) {
        node = node->next;
    }
    return node->get();
}

template <typename T>
void LinkedList<T>::add(T item) {
    Node<T>* node = new Node<T>(item);
    if (head == nullptr) {
        head = node;
        tail = head;
    }  else {
        tail->next = node;
        tail = tail->next;
    }
    _size++;
}

template <typename T>
void LinkedList<T>::insert(T item, int index) {
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
void LinkedList<T>::remove(T item) {
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
bool LinkedList<T>::contains(T item) {
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
int LinkedList<T>::indexof(T item) {
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
void LinkedList<T>::overwrite(T item, int index) {
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
int LinkedList<T>::size() {
    return list_size;
}

template <typename T>
bool LinkedList<T>::empty() {
    return list_size == 0;
}

template <typename T>
void LinkedList<T>::print() {
    std::cout << "[ ";
    Node<T>* node = head;
    while (node != nullptr) {
        std::cout << node->str() << " ";
        node = node->next;
    }
    std::cout << "]\n";
}
