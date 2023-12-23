#include <iostream>
#include <string>
#include "static.hpp"
#include "dynamic.hpp"

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(int);
    StaticArray s_arr = StaticArray(arr, size, 20);
    s_arr.print();
    
    DynamicArray d_arr(arr, 10);
    d_arr.print();
    for (int i=1; i < 11; i++) {
        d_arr.append(i);
    }
    d_arr.print();
    printf("%d\n", d_arr.capacity());
    d_arr.append(69);
    d_arr.insert(10, 18);
    d_arr.print();
    printf("%d\n", d_arr.capacity());
    printf("%d\n", d_arr.size());
}