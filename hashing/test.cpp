#include <iostream>
#include <string>
#include "linkedlist.hpp"

int main() {

    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    HashSetList<int> list = HashSetList<int>();
    for (int item: vec) {
        list.add(item);
    }
    list.remove(5);
    list.print();
    std::cout << list.contains(5) << "\n";
    std::cout << list.contains(1) << "\n";
    return 0;
}
