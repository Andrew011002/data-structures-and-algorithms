#include <iostream>
#include <string>
#include "hashset.hpp"

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    HashSet<int> set = HashSet<int>(vec);
    std::vector<int> vec1 = {11, 12, 13, 14};
    HashSet<int> set1 = set.unionof(vec1);
    HashSet<int> set2 = set.intersectof(vec1); 
    std::vector<int> vec2 = {3, 4, 5};
    set1.print();
    set2.print();
    printf("is subset? %d\n", set1.issub(vec2));
    printf("is subset? %d\n", set2.issub(vec2));
    HashSet<int> set3 = set.intersectof(vec2);
    set3.print();
    printf("cotains? %d\n", set.contains(5));
    printf("cotains? %d\n", set.contains(11));
    printf("cotains? %d\n", set1.contains(11));
    return 0;
}
