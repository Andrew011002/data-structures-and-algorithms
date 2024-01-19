#include <iostream>
#include <string>
#include "linkedlist.hpp"

int main() {

    LinkedList<int> list = LinkedList<int>();
    for (int i=0; i < 10; i++) {
        list.add(i);
    }
    list.overwrite(69, 0);
    list.insert(69, 10);
    list.remove(5);
    list.print();
    return 0;
}
