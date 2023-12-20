#include <iostream>
#include "./dynamic.hpp"
using namespace std;

DynamicArray::DynamicArray(int capacity):StaticArray(capacity) {
}

DynamicArray::DynamicArray(int array[], int size):StaticArray(array, size, size) {

}

void DynamicArray::resize() {
    int* new_arr_ptr = new int[StaticArray::capacity() * 2]; 
    int* new_ptr = new_arr_ptr;
    
    for (int i=0; i < StaticArray::size(); i++) {
        *new_ptr = StaticArray::get(i);
        new_ptr++;
    }
    delete StaticArray::arr_ptr;
    delete StaticArray::ptr;
    StaticArray::arr_ptr = new_arr_ptr;
    StaticArray::ptr = new_ptr;
}

int main() {
    DynamicArray arr = DynamicArray(33);
    arr.print();
}
