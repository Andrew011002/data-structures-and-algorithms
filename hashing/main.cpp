#include <vector>
#include <utility>
#include <string>
#include "linkedlist.hpp"
// #include "hashmap.hpp"

int main() {
    LinkedListKV<std::string, int> list;
    list.add("Andrew", 11);
    list.print();
    list.add("John");
    list.print();
    list.replace("John", 100);
    list.print();
    list.remove("John");
    printf("Contains? %d\n", list.contains("John"));
    printf("Contains? %d\n", list.contains("Andrew"));
    list.print();
}