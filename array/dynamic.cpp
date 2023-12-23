#include <iostream>
#include "./dynamic.hpp"
using namespace std;

DynamicArray::DynamicArray(int capacity):StaticArray(capacity) {
}

DynamicArray::DynamicArray(int array[], int size):StaticArray(array, size, size) {

}

void DynamicArray::append(int elem) {
    if (full()) {
        resize(cap * 2);
    }
    StaticArray::append(elem);
}

void DynamicArray::insert(int index, int elem) {
    if (full()) {
        resize(cap * 2);
    }
    StaticArray::insert(index, elem);
}


void DynamicArray::resize(int capacity) {
    if (capacity < cap) {
        throw exception();
    }
    int* new_arr_ptr = new int[capacity * 2]; 
    int* new_ptr = new_arr_ptr;
    
    for (int i=0; i < nelem; i++) {
        *new_ptr = StaticArray::get(i);
        new_ptr++;
    }
    delete[] arr_ptr;
    arr_ptr = new_arr_ptr;
    ptr = new_ptr;
    cap = capacity;
}
