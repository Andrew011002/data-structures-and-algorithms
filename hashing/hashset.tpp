template <typename T>
HashSet<T>::HashSet() {
    n_elements = 0;   
    max_elements = 7;
    for (int i=0; i < max_elements; i++) {
        data.push_back(DoublyList<T>());
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
void HashSet<T>::add(T item) {
    int index = hash(item);
}

template <typename T>
int HashSet<T>::hash(T item) {
    std::hash<T> func;
    return func(item) % max_elements;
}

template <typename T>
bool HashSet<T>::empty() {
    return n_elements == 0;
}

template <typename T>
int HashSet<T>::size() {
    return n_elements;
}


