#include "hashset.hpp"

int main() {
    HashSet<int> set;
    for (int i=0; i < 10; i++) {
        set.add(i);
    }

    std::array<int, 4> arr = {19, 20, 0, 8};
    set.intersectof(arr).print();
}