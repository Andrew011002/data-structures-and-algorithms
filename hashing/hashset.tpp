template <typename T>
HashSet<T>::HashSet() {
    for (int i=0; i < set_capacity; i++) {
        lists[i] = new HashSetList<T>();
    }
}

template <typename T>
HashSet<T>::HashSet(const std::vector<T> &vec):HashSet() {
    for (T item: vec) {
        add(item);
    }
 }

template <typename T>
int HashSet<T>::hash(T item) const {
    std::hash<T> function;
    return function(item) % capacity();
}

template <typename T>
void HashSet<T>::rehash() {
    const int previous_set_capacity = set_capacity;
    HashSetList<T>** old_lists = new HashSetList<T>*[previous_set_capacity];
    for (int i = 0; i < previous_set_capacity; i++) {
        old_lists[i] = lists[i];
    }

    set_size = 0;
    set_capacity = set_capacity * 2 + 1;
    const int new_set_capacity = set_capacity;
    lists = new HashSetList<T>*[new_set_capacity];
    for (int i=0; i < new_set_capacity; i++) {
        lists[i] = new HashSetList<T>();
    }

    for (int i=0; i < previous_set_capacity; i++) {
        HashSetList<T> *list = old_lists[i];
        for (int j=0; j < list->size(); j++) {
            add(list->get(j));
        }
    }
    delete [] old_lists;
}

template <typename T>
void HashSet<T>::add(T item) {
    if (contains(item)) {
        return;
    }
    
    int index = hash(item);
    HashSetList<T> *list = lists[index];
    while (list->size() == max_list_size) {
        index = (index + 1) % capacity();
        list = lists[index];
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
    HashSetList<T> *list = lists[index];
    while (!list->contains(item)) {
        index = (index + 1) % capacity();
        list = lists[index];
    }
    list->remove(item);
    set_size--;
}

template <typename T>
bool HashSet<T>::contains(T item) const {
    int index = hash(item);
    HashSetList<T> *list = lists[index];
    while (list->size() > 0) {
        if (list->contains(item)) {
            return true;
        }
        index = (index + 1) % capacity(); 
        list = lists[index]; 
    }
    return false;
}

template <typename T>
bool HashSet<T>::issub(const std::vector<T> &vec) const {
    for (T item: vec) {
        if (!contains(item)) {
            return false;
        }
    }
    return true;
}

template <typename T>
HashSet<T> HashSet<T>::intersectof(const std::vector<T> &vec) const {
    HashSet<T> set;
    for (T item: vec) {
        if (contains(item)) {
            set.add(item);
        }
    }
    return set;
}

template <typename T>
HashSet<T> HashSet<T>::unionof(const std::vector<T> &vec) const {
    HashSet<T> set;
    for (int i=0; i < set_capacity; i++) {
        HashSetList<T> *list = lists[i];
        for (int j=0; j < list->size(); j++) {
            set.add(list->get(j));
        } 
    }
    for (T item: vec) {
        set.add(item);
    }
    return set;
}

template <typename T>
bool HashSet<T>::empty() const {
    return set_size == 0;
}

template <typename T>
int HashSet<T>::size() const {
    return set_size;
}

template <typename T>
int HashSet<T>::capacity() const {
    return set_capacity;
}

template <typename T>
void HashSet<T>::print() const {
    std::cout << "{ ";
    int index = 0;
    
    while (index < set_capacity) {
        HashSetList<T> *list = lists[index];
        for (int i=0; i < list->size(); i++) {
            std::cout << list->get(i) << " ";
        }
        index++; 
    }
    std::cout << "}\n";
}


