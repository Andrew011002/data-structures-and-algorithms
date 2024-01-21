template <typename T, typename U>
HashMap<T, U>::HashMap() {
    for (int i=0; i < map_capacity; i++) {
        lists[i] = new LinkedListKV<T, U>();
    }
}

template <typename T, typename U>
HashMap<T, U>::HashMap(const std::vector<T> &vec):HashMap() {
    for (T key: vec) {
        add(key);
    }
}

template <typename T, typename U>
HashMap<T, U>::HashMap(const std::vector<std::pair<T, U>> &vec):HashMap() {
    for (std::pair<T, U> item: vec) {
        add(item.first, item.second);
    }
}

template <typename T, typename U>
int HashMap<T, U>::hash(T key) const {
   std::hash<T> function; 
   return function(key) % map_capacity;
}

template <typename T, typename U>
void HashMap<T, U>::rehash() {
    const int previous_map_capacity = map_capacity;
    LinkedListKV<T, U>** old_lists = new LinkedListKV<T, U>*[previous_map_capacity];
    for (int i=0; i < previous_map_capacity; i++) {
        old_lists[i] = lists[i];
    }

    map_size = 0;
    map_capacity = map_capacity * 2 + 1;
    const int new_map_capacity = map_capacity;
    lists = new LinkedListKV<T, U>*[new_map_capacity];
    for (int i=0; i < new_map_capacity; i++) {
        lists[i] = new LinkedListKV<T, U>();
    }

    for (int i=0; i < previous_map_capacity; i++) {
        LinkedListKV<T, U> *list = old_lists[i];
        for (int j=0; j < list->size(); j++) {
            std::pair<T, std::optional<U>> item = list->get(j);
            if (item.second.has_value()) {
                add(item.first, item.second.value());
            } else {
                add(item.first);
            }
        }
    }
    delete [] old_lists;
}

template <typename T, typename U>
void HashMap<T, U>::add(T key, U value) {
    if (contains(key)) {
        replace(key, value);
        return;
    }

    int index = hash(key);
    LinkedListKV<T, U> *list = lists[index];
    while (list->size() == max_list_size) {
        index = (index + 1) % capacity();
        list = lists[index];
    }
    list->add(key, value);
    map_size++;
    if (size() >= capacity() / 2) {
        rehash();
    }
}

template <typename T, typename U>
void HashMap<T, U>::add(T key) {
    if (contains(key)) {
        return;
    }

    int index = hash(key);
    LinkedListKV<T, U> *list = lists[index];
    while (list->size() == max_list_size) {
        index = (index + 1) % capacity();
        list = lists[index];
    }
    list->add(key);
    map_size++;
    if (size() >= capacity() / 2) {
        rehash();
    }
}


template <typename T, typename U>
std::optional<U> HashMap<T, U>::get(T key) const {
    if (!contains(key)) {
        throw std::exception();
    }

    int index = hash(key);
    LinkedListKV<T, U> *list = lists[index];
    while (!list->contains(key)) {
        index = (index + 1) % capacity();
        list = lists[index];
    }
    for (int i=0; i < list->size(); i++) {
        std::pair<T, std::optional<U>> item = list->get(i);
        if (item.first == key) {
            return item.second;
        }
    }
    return std::nullopt;
}

template <typename T, typename U>
void HashMap<T, U>::remove(T key) {
    if (!contains(key)) {
        throw std::exception();
    }

    int index = hash(key);
    LinkedListKV<T, U> *list = lists[index];
    while (!list->contains(key)) {
        index = (index + 1) % capacity();
        list = lists[index];
    }
    list->remove(key);
    map_size--;
}

template <typename T, typename U>
bool HashMap<T, U>::contains(T key) const {
    int index = hash(key);
    LinkedListKV<T, U> *list = lists[index];
    while (!(list->empty())) {
        if (list->contains(key)) {
            return true;
        }
        index = (index + 1) % capacity();
        list = lists[index];
    }
    return false;
}


template <typename T, typename U>
void HashMap<T, U>::replace(T key, U value) {
    if (!contains(key)) {
        throw std::exception();
    }

    int index = hash(key);
    LinkedListKV<T, U> *list = lists[index];
    while (!list->contains(key)) {
        index = (index + 1) % capacity();
        list = lists[index];
    }
    list->replace(key, value);
}

template <typename T, typename U>
std::vector<T> HashMap<T, U>::keys() const {
    std::vector<T> vec;
    for (int i=0; i < map_capacity; i++) {
        LinkedListKV<T, U> *list = lists[i];
        for (int j=0; j < list->size(); j++) {
            T key = list->get(j).first;
            vec.push_back(key);
        }
    }
    return vec;
}


template <typename T, typename U>
std::vector<U> HashMap<T, U>::values() const {
    std::vector<U> vec;
    for (int i=0; i < map_capacity; i++) {
        LinkedListKV<T, U> *list = lists[i];
        for (int j=0; j < list->size(); j++) {
            std::optional<U> value = list->get(j).second;
            if (value.has_value()) {
                vec.push_back(value.value());
            }
        }
    }
    return vec;
}

template <typename T, typename U>
std::vector<std::pair<T, std::optional<U>>> HashMap<T, U>::items() const {
    std::vector<std::pair<T, std::optional<U>>> vec;
    for (int i=0; i < map_capacity; i++) {
        LinkedListKV<T, U> *list = lists[i];
        for (int j=0; j < list->size(); j++) {
            std::pair<T, std::optional<U>> item = list->get(j);
            vec.push_back(item);
        }
    }
    return vec;
}

template <typename T, typename U>
bool HashMap<T, U>::empty() const {
    return map_size == 0;
}

template <typename T, typename U>
int HashMap<T, U>::size() const {
    return map_size;
}

template <typename T, typename U>
int HashMap<T, U>::capacity() const {
    return map_capacity;
}

template <typename T, typename U>
void HashMap<T, U>::print() const {
    std::cout << "{ ";
    for (int i=0; i < map_capacity; i++) {
        LinkedListKV<T, U> *list = lists[i];
        for (int j=0; j < list->size(); j++) {
            std::pair<T, std::optional<U>> item = list->get(j);
            std::cout << item.first << ": ";
            if (item.second.has_value()) {
                std::cout << item.second.value();
            } else {
                std::cout << "null";
            }
            std::cout << " ";
        }
    }
    std::cout << "}\n";
}