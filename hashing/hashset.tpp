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
    return func(item) % capacity();
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
    // can this be faster than O(mn)?
    for (DoublyList<T> *list: data_copy) {
        for (int i=0; i < list->size(); i++) {
            add(list->get(i));
        }
    }
}

template <typename T>
void HashSet<T>::add(T item) {
    if (contains(item)) {
        return;
    }
    int index = hash(item);
    DoublyList<T> *list = data[index];
    while (list->size() == MAX_ELEMENTS) {
        index = (index + 1) % capacity();
        list = data[index];
    }
    list->add(item);
    set_size++;
    if (size() >= capacity() / 2) {
        rehash();
    }
}

template <typename T>
void HashSet<T>::remove(T item) {
    if (!contains(item)) {
        throw std::exception();
    }
    int index = hash(item);
    DoublyList<T> *list = data[index];
    while (!list->contains(item)) {
        index = (index + 1) % capacity();
        list = data[index];
    }
    list->remove(item);
    set_size--;
}

template <typename T>
bool HashSet<T>::contains(T item) {
    int index = hash(item);
    DoublyList<T> *list = data[index];
    while (list->size() > 0) {
        if (list->contains(item)) {
            return true;
        }
        index = (index + 1) % capacity(); 
        list = data[index]; 
    }
    return false;
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


