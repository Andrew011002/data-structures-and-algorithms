template <typename T>
HashSetList<T>::HashSetList() {
    _size = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
T HashSetList<T>::get(int index) const {
    if (empty()|| index >= size() || index < 0) {
        throw std::exception();
    }
    HashSetNode<T>* node = head;
    while (index > 0) {
        node = node->next;
        index--;
    }
    return node->get();
}

template <typename T>
void HashSetList<T>::add(T item) {
    HashSetNode<T> *node = new HashSetNode<T>(item);
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
void HashSetList<T>::remove(T item) {
    if (empty()) {
        throw std::exception();
    }

    HashSetNode<T> *previous_node = nullptr;
    HashSetNode<T> *node = head;
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
        HashSetNode<T> *next_node = head->next;
        delete head;
        head = next_node;
    } else {
        previous_node->next = node->next;
        delete node;
    }
    _size--;
}

template <typename T>
bool HashSetList<T>::contains(T item) const {
    HashSetNode<T> *node = head;
    while (node != nullptr) {
        if (node->get() == item) {
            return true;
        }
        node = node->next;
    }
    return false;
}

template <typename T>
int HashSetList<T>::size() const {
    return _size;
}

template <typename T>
bool HashSetList<T>::empty() const {
    return _size == 0;
}

template <typename T>
void HashSetList<T>::print() const {
    std::cout << "[ ";
    HashSetNode<T> *node = head;
    while (node != nullptr) {
        std::cout << node->get() << " ";
        node = node->next;
    }
    std::cout << "]\n";
}
