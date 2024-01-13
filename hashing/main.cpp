#include "hashset.hpp"

int main() {
    HashSet<int> set;
    for (int i=0; i < 10; i++) {
        set.add(i);
    }
    int arr[5] = {0, 2, 4, 6, 8};
    printf("Is subset? %d\n", set.issub(arr, 5));
}