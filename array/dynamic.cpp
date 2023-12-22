#include <iostream>
#include "./dynamic.hpp"
using namespace std;

DynamicArray::DynamicArray(int capacity):StaticArray(capacity) {
}

DynamicArray::DynamicArray(int array[], int size):StaticArray(array, size, size) {

}

void DynamicArray::write(int index, int elem) {
    if (full()) {
        resize();
    }
    StaticArray::write(index, elem);
}

void DynamicArray::append(int elem) {
    if (full()) {
        resize();
    }
    StaticArray::append(elem);
}

void DynamicArray::insert(int index, int elem) {
    if (full()) {
        resize();
    }
    StaticArray::insert(index, elem);
}


void DynamicArray::resize() {
    int* new_arr_ptr = new int[cap * 2]; 
    int* new_ptr = new_arr_ptr;
    
    for (int i=0; i < nelem; i++) {
        *new_ptr = StaticArray::get(i);
        new_ptr++;
    }
    delete[] arr_ptr;
    arr_ptr = new_arr_ptr;
    ptr = new_ptr;
    cap *= 2;
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    DynamicArray arr = DynamicArray(array, 10);
    arr.print();
    arr.append(10);
    arr.print();
}
