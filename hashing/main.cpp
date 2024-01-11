#include "hashset.hpp"

int main() {
    HashSet<int> set;
    for (int i=0; i < 21; i++) {
        set.add(i * 3 + 1);
        printf("size: %d ", set.size());
        set.print();
    }
}