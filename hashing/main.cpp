#include "hashset.hpp"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    HashSet<int> set1(arr, 5);
    printf("Capacity: %d\n", set1.capacity());

    set1.add(6);
    set1.print();

    set1.remove(3);
    set1.print();

    printf("Contains 4? %d\n", set1.contains(4));

    int arr2[] = {4, 5, 6};
    printf("Is subset? %d\n", set1.issub(arr2, 3));

    HashSet<int> set2 = set1.intersectof(arr2, 3);
    set2.print();
    printf("Capacity: %d\n", set2.capacity());

    int arr3[] = {7, 8, 9, 11, 12, 14, 15, 16};
    HashSet<int> set3 = set1.unionof(arr3, 8);
    set3.print();
    printf("Empty? %d\n", set3.empty());
    printf("Size: %d\n", set3.size());
    printf("Capacity: %d\n", set3.capacity());
    return 0;
}