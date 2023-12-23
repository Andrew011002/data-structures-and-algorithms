#include <iostream>
#include <string>
#include "./static.hpp"
#include "../print.hpp"
using namespace std;


StaticArray::StaticArray(int capacity) {
    arr_ptr = new int[capacity];
    ptr = arr_ptr;
    nelem = 0;
    cap = capacity;
}

StaticArray::StaticArray(int array[], int size, int capacity) {
    arr_ptr = new int[capacity];
    ptr = arr_ptr;
    nelem = size;
    cap = capacity;

    for (int i=0; i < nelem; i++) {
        *ptr = array[i];
        ptr++;
    }
}

int StaticArray::get(int index) {
    if (index < 0 || index >= cap) {
        throw exception();
    }
    return *(arr_ptr + index);
}

void StaticArray::write(int index, int elem) {
    if (index < 0 || index >= cap) {
        throw exception();
   }
   *(arr_ptr + index) = elem; 
}

void StaticArray::append(int elem) {
    if (full()) {
        throw exception();
    }
    *ptr = elem;
    ptr++;
    nelem++;
}

void StaticArray::insert(int index, int elem) {
    if (index < 0 || index > nelem) {
        throw exception();
    }
    if (full()) {
        throw exception();
    }
    if (index == nelem) {
        append(elem);
        return;
    }
    
    ptr = arr_ptr + index;
    for (int i=index; i < nelem + 1; i++) {
        int tmp = *ptr;
        *ptr = elem;
        elem = tmp;
        ptr++;
    }
    nelem++;
}

void StaticArray::remove(int value) {
    if (empty()) {
        throw exception();
    }

    bool found = false;
    int* tmp_ptr = arr_ptr;
    int index;
    for (int i=0; i < nelem; i++) {
        if (*tmp_ptr == value) {
            index = i;
            found = true;
            break;
        }
        tmp_ptr++;
    }

    if (!found) {
        throw exception();
    }

    ptr = arr_ptr + index;
    for (int i=index; i < nelem - 1; i++) {
        *ptr = *(ptr + 1);
        ptr++;
    }
    *ptr = 0;
    nelem--;
}

int StaticArray::pop() {
    if (empty()) {
        throw exception();
    }
    nelem--;
    return *--ptr; 
}

void StaticArray::print() {
    int* tmp_ptr = arr_ptr;
    cout << "[ ";
    for (int i = 0; i < nelem; i++) {
        cout << *tmp_ptr << " "; 
        tmp_ptr++;
    }        
    cout << "]" << endl;
}

void StaticArray::clear() {
    for (int i=0; i < nelem; i++) {
        ptr--;
        *ptr = 0;
    }
    nelem = 0;
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
