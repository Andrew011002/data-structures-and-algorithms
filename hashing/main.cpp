#include <vector>
#include <utility>
#include <string>
#include "linkedlist.hpp"

int main() {
    LinkedListKV<std::string, int> list;
    list.add("Andrew", 11);
    list.add("John", 15);
    list.print();
    list.remove("John");
    list.print();
    std::pair<std::string, int> p = list.get(0);
    std::cout << p.first << " " << p.second << std::endl;
    std::cout << "size: " << list.size() << std::endl;
    std::cout << "empty? " << list.empty() << std::endl;
    std::cout << "contains? " << list.contains("Andrew") << std::endl;
    std::cout << "contains? " << list.contains("John") << std::endl;
    return 0;
}