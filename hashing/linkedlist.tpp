template <typename T>
LinkedList<T>::LinkedList() {
    _size = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
T LinkedList<T>::get(int index) const {
    if (empty()|| index >= size() || index < 0) {
        throw std::exception();
    }
    Node<T> *node = head;
    while (index > 0) {
        node = node->next;
        index--;
    }
    return node->get();
}

template <typename T>
void LinkedList<T>::add(T item) {
    Node<T> *node = new Node<T>(item);
    if (size() == 0) {
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
        Node<T> *next_node = head;
        head = new Node<T>(item);
        head->next = next_node;
    } else {
        Node<T> *node = head;
        while (index - 1 > 0) {
            node = node->next;
            index--;
        }
        Node<T> *next_node = node->next;
        node->next = new Node<T>(item);
        node->next->next = next_node;
    }
    _size++;
}

template <typename T>
void LinkedList<T>::remove(T item) {
    if (empty()) {
        throw std::exception();
    }

    Node<T> *previous_node = nullptr;
    Node<T> *node = head;
    bool not_found = true;
    while (node != nullptr) {
        if (node->get() == item) {
            not_found = false;
            break;
        }
        previous_node = node;
        node = node->next;
    }

    if (not_found) {
        throw std::exception();
    }
    if (size() == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else if (node == head) {
        Node<T> *next_node = head->next;
        delete head;
        head = next_node;
    } else {
        previous_node->next = node->next;
        delete node;
    }
    _size--;
}

template <typename T>
bool LinkedList<T>::contains(T item) const {
    Node<T> *node = head;
    while (node != nullptr) {
        if (node->get() == item) {
            return true;
        }
        node = node->next;
    }
    return false;
}

template <typename T>
int LinkedList<T>::indexof(T item) const {
    if (empty()) {
        throw std::exception();
    }
    int index = 0;
    Node<T> *node = head;
    while (node != nullptr) {
        if (node->get() == item) {
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
    Node<T> *node = head;
    while (index > 0) {
        node = node->next;
        index++;
    }
    node->set(item);
}

template <typename T>
int LinkedList<T>::size() const {
    return _size;
}

template <typename T>
bool LinkedList<T>::empty() const {
    return _size == 0;
}

template <typename T>
void LinkedList<T>::print() const {
    std::cout << "[ ";
    Node<T> *node = head;
    while (node != nullptr) {
        std::cout << node->get() << " ";
        node = node->next;
    }
    std::cout << "]\n";
}
