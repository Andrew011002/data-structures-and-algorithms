#include "hashset.hpp"

int main() {
    HashSet<int> set;
    for (int i=0; i < 10; i++) {
        set.add(i);
    }
    set.print();
    printf("contains: %d\n", set.contains(0));
}