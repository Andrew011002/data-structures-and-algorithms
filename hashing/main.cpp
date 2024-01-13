#include "hashset.hpp"

int main() {
    HashSet<int> set;
    for (int i=0; i < 10; i++) {
        set.add(i);
    }

    int arr[] = {69, 4, 5, 19, 20, 490};
    set.unionof(arr, 6).print();
}