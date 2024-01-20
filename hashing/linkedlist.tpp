template <typename T>
LinkedList<T>::LinkedList() {
    list_size = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
T LinkedList<T>::get(int index) const {
    if (empty()|| index >= size() || index < 0) {
        throw std::exception();
    }
    Node<T>* node = head;
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
    list_size++;
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
    list_size--;
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
int LinkedList<T>::size() const {
    return list_size;
}

template <typename T>
bool LinkedList<T>::empty() const {
    return list_size == 0;
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

template <typename T, typename U>
LinkedListKV<T, U>::LinkedListKV() {
    list_size = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T, typename U>
std::pair<T, U> LinkedListKV<T, U>::get(int index) const {
    if (empty()|| index >= size() || index < 0) {
        throw std::exception();
    }
    NodeKV<T, U>* node = head;
    while (index > 0) {
        node = node->next;
        index--;
    }
    return {node->key(), node->value()};
}

template <typename T, typename U>
void LinkedListKV<T, U>::add(T item, U data) {
    NodeKV<T, U> *node = new NodeKV<T, U>(item, data);
    if (size() == 0) {
        head = node;
        tail = head;
    }  else {
        tail->next = node;
        tail = tail->next;
    }
    list_size++;
}

template <typename T, typename U>
void LinkedListKV<T, U>::remove(T key) {
    if (empty()) {
        throw std::exception();
    }

    NodeKV<T, U> *previous_node = nullptr;
    NodeKV<T, U> *node = head;
    bool not_found = true;
    while (node != nullptr) {
        if (node->key() == key) {
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
        NodeKV<T, U> *next_node = head->next;
        delete head;
        head = next_node;
    } else {
        previous_node->next = node->next;
        delete node;
    }
    list_size--;
}

template <typename T, typename U>
bool LinkedListKV<T, U>::contains(T key) const {
    NodeKV<T, U> *node = head;
    while (node != nullptr) {
        if (node->key() == key) {
            return true;
        }
        node = node->next;
    }
    return false;
}

template <typename T, typename U>
void LinkedListKV<T, U>::replace(T key, U value) {
    if (!contains(key)) {
        throw std::exception();
    }
    NodeKV<T, U> *node = head;
    while (node->key() != key) {
        node = node->next;
    }
    node->setval(value);
}

template <typename T, typename U>
int LinkedListKV<T, U>::size() const {
    return list_size;
}

template <typename T, typename U>
bool LinkedListKV<T, U>::empty() const {
    return list_size == 0;
}

template <typename T, typename U>
void LinkedListKV<T, U>::print() const {
    std::cout << "[ ";
    NodeKV<T, U> *node = head;
    while (node != nullptr) {
        std::cout << "(" << node->key() << ": " << node->value() << ") ";
        node = node->next;
    }
    std::cout << "]\n";
}