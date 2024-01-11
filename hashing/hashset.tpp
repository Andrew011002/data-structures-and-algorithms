int MAX_ELEMENTS = 5;

template <typename T>
HashSet<T>::HashSet() {
    set_size = 0;
    set_capacity = 19;
    for (int i=0; i < set_capacity; i++) {
        data.push_back(new DoublyList<T>());
    }
}

template <typename T>
HashSet<T>::HashSet(const T arr[], int size):HashSet() {
    for (int i=0; i < size; i++) {
        add(arr[i]);
    }
}

template <typename T>
template <size_t N>
HashSet<T>::HashSet(const std::array<T, N> arr):HashSet() {
    for (T item: arr) {
        add(item);
    }
}

template <typename T>
HashSet<T>::HashSet(const std::vector<T> vec):HashSet() {
    for (T item: vec) {
        add(item);
    }
 }

template <typename T>
int HashSet<T>::hash(T item) {
    std::hash<T> func;
    return func(item) % set_capacity;
}

template <typename T>
void HashSet<T>::rehash() {
    set_size = 0;
    set_capacity = set_capacity * 2 + 1;
    std::vector<DoublyList<T>*> data_copy = data; 
    data.clear();
    for (int i=0; i < set_capacity; i++) {
        data.push_back(new DoublyList<T>());
    }

    for (DoublyList<T> *list: data_copy) {
        for (int i=0; i < list->size(); i++) {
            add(list->get(i));
        }
    }
}

template <typename T>
void HashSet<T>::add(T item) {
    int index = hash(item);
    while (true) {
        DoublyList<T> *list = data[index];
        if (list->contains(item)) {
            return;
        }
        if (list->size() == MAX_ELEMENTS) {
            index = (index + 1) % capacity();
        } else {
            list->add(item);
            set_size++;
            break;
        }
    }
    if (size() >= capacity() / 2) {
        rehash();
    }
}

template <typename T>
bool HashSet<T>::empty() {
    return set_size == 0;
}

template <typename T>
int HashSet<T>::size() {
    return set_size;
}

template <typename T>
int HashSet<T>::capacity() {
    return set_capacity;
}

template <typename T>
void HashSet<T>::print() {
    std::cout << "{ ";
    int index = 0;
    
    while (index < set_capacity) {
        DoublyList<T> *list = data[index];
        for (int i=0; i < list->size(); i++) {
            std::cout << list->get(i) << " ";
        }
        index++; 
    }
    std::cout << "}\n";
}


