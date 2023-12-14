#include <iostream>
#include <string>
#include "./static.hpp"
#include "../print.hpp"
using namespace std;


StaticArray::StaticArray(int capacity) {
    arr = new int[capacity];
    ptr = arr;
    nelem = 0;
    cap = capacity;
}

StaticArray::StaticArray(int array[], int size, int capacity) {
    arr = array;
    ptr = arr;
    nelem = size;
    cap = capacity;
}

    
void StaticArray::in_bounds_check(int index, string msg) {
    if (index < 0 || index >= nelem) {
        throw out_of_range(msg);
    }
}

void StaticArray::can_add_check(string msg) {
    if (nelem == cap) {
        throw length_error(msg);
    }
}

void StaticArray::can_retrieve_check(string msg) {
    if (nelem == 0) {
        throw length_error(msg);
    }
}

int* StaticArray::move_ptr_to_index(int *ptr, int index) {
    int* tmp_ptr = ptr;
    for (int i=0; i < index; i++) {
        tmp_ptr++; 
    }
    return tmp_ptr;
}


int StaticArray::get(int index) {
    can_retrieve_check("cannot get, array is empty");
    in_bounds_check(index, "index out of bounds");
    return *(ptr + index);
}

void StaticArray::append(int elem) {
    can_add_check("array is full, cannot append");
    *ptr = elem;
    ptr++;
    nelem++;
}

void StaticArray::insert(int elem, int index) {
    can_add_check("array is full, cannot insert");
    in_bounds_check(index, "index out of bounds");

    if (nelem == 0 || index == nelem - 1) {
        append(elem);
        return;
    }

    int* tmp_ptr = move_ptr_to_index(arr, index);
    for (int i=index; i < nelem + 1; i++) {
        int tmp = *tmp_ptr;
        *tmp_ptr = elem;
        elem = tmp;
        tmp_ptr++;
    }
    ptr = tmp_ptr;
    nelem++;
}

void StaticArray::remove(int value) {
    can_retrieve_check("array is empty, cannot remove");
    bool found = false;
    int* tmp_ptr = arr;
    int index;
    
    for (int i=0; i < nelem; i++) {
        if (*tmp_ptr == value) {
            index = i;
            found = true;
            break;
        }
        tmp_ptr++;
    }

    if (found) {
        for (int i=index; i < nelem - 1; i++) {
            *tmp_ptr = *(tmp_ptr + 1);
            tmp_ptr++;
        }
        ptr = tmp_ptr;
        nelem--;
    }
}

int StaticArray::pop() {
    can_retrieve_check("array is empty, cannot pop");
    int val = *(ptr - 1);
    ptr--;
    nelem--;
    return val; 
}

void StaticArray::print() {
    int* tmp = arr;
    cout << "[ ";
    for (int i = 0; i < nelem; i++) {
        cout << *tmp << " "; 
        tmp++;
    }        
    cout << "]" << endl;
}

int StaticArray::size() {
    return nelem;
}

int StaticArray::capacity() {
    return cap;
}

bool StaticArray::empty() {
    return nelem == 0;
}

bool StaticArray::full() {
    return nelem == cap;
}

void StaticArray::clear() {
    for (int i=0; i < nelem; i++) {
        ptr--;
        *ptr = 0;
    }
    nelem = 0;
}
