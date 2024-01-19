#include <iostream>
#include <string>
#include "hashset.hpp"

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    HashSet<int> set = HashSet<int>(vec);
    set.print();
    return 0;
}
