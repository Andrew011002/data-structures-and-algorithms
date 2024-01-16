int MAX_CAPACITY = 10;

template <typename K, typename V>
HashMap<K, V>::HashMap() {
    for (int i=0; i < map_capacity; i++) {
        data[i] = new DoublyList<std::pair<K, std::optional<V>>>();
    }
}

template <typename K, typename V>
HashMap<K, V>::HashMap(const std::vector<std::pair<K, V>> &vec):HashMap() {
    for (std::pair<K, V> &item: vec) {
        add(item.first, item.second);
    }
}

template <typename K, typename V>
int HashMap<K, V>::hash(K key) {
   std::hash<K> f; 
   return f(key) % map_capacity;
}

template <typename K, typename V>
void HashMap<K, V>::rehash() {
    const int old_capacity = map_capacity;
    map_capacity = map_capacity * 2 + 1;
    map_size = 0;
    std::array<DoublyList<std::pair<K, std::optional<V>>>*, old_capacity> data_copy = data;
    data = std::array<DoublyList<std::pair<K, std::optional<V>>>, map_capacity>();
    for (int i=0; i < data_copy.size(); i++) {
        DoublyList<std::pair<K, std::optional<V>>> *list = data_copy[i];
        for (int j=0; j < list->size(); j++) {
            std::pair<K, std::optional<V>> item = list[j];
            add(item.first, item.second);
        }
    }
}

template <typename K, typename V>
void HashMap<K, V>::add(K key, V value) {
    // add contains here 

    std::pair<K, std::optional<V>> item = {key, value};
    int index = hash(key);
    while (data[index]->size() == MAX_CAPACITY) {
        index = (index + 1) % capacity();
    }
    data[index]->add(item);
    map_size++;
    if (size() >= capacity() / 2) {
        rehash();
    }
}

template <typename K, typename V>
void HashMap<K, V>::add(K key) {
    add(key, std::nullopt);
}

template <typename K, typename V>
bool HashMap<K, V>::empty() {
    return map_size == 0;
}

template <typename K, typename V>
int HashMap<K, V>::size() {
    return map_size;
}

template <typename K, typename V>
int HashMap<K, V>::capacity() {
    return map_capacity;
}