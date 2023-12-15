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
    arr_ptr = array;
    ptr = arr_ptr;
    nelem = size;
    cap = capacity;
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
    if (nelem == cap) {
        throw exception();
    }
    *ptr = elem;
    ptr++;
    nelem++;
}

void StaticArray::insert(int index, int elem) {
    if (index < 0 || index > cap) {
        throw exception();
    }
    if (nelem == cap) {
        throw exception();
    }
    if (index == cap) {
        append(elem);
        return;
    }
    
    int* tmp_ptr = arr_ptr;
    for (int i=0; i < index; i++) {
        if (i == index) {
            break;
        }
        tmp_ptr++;
    }
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
    if (nelem == 0) {
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
    for (int i=index; i < nelem - 1; i++) {
        *tmp_ptr = *(tmp_ptr + 1);
        tmp_ptr++;
    }
    ptr = tmp_ptr;
    nelem--;
}

int StaticArray::pop() {
    if (nelem == 0) {
        throw exception();
    }
    nelem--;
    return *--ptr; 
}

void StaticArray::print() {
    int* tmp_ptr = arr_ptr;
    cout << "[ ";
    for (int i = 0; i < nelem + 20; i++) {
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


int main() {
    StaticArray arr = StaticArray(10);
    arr.append(10);
    arr.insert(0, 5);
    arr.insert(2, 3);
    arr.print();
    arr.insert(2, 7);
    arr.remove(3);
    arr.clear();
}