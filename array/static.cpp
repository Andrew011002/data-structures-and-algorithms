#include <iostream>
#include "../print.hpp"
using namespace std;

struct StaticArray {

private:

    int* arr;
    int* ptr;
    int size;
    int cap;

public:

    StaticArray(int capacity) {
        arr = new int[capacity];
        ptr = arr;
        cap = capacity;
    }

    StaticArray(int array[], int nelem, int capacity) {
        arr = array;
        ptr = arr;
        size = nelem;
        cap = capacity;
    }

    void append(int elem) {
        *ptr = elem;
        ptr++;
        size++;
    }

    void insert(int value, int index) {
        if (size == 0 || index >= size) {
            append(value);
            return;
        }

        int* tmp_ptr = arr;
        for (int i=0; i < index; i++) {
            tmp_ptr++;
        }

        for (int i=index; i < size + 1; i++) {
            int tmp = *tmp_ptr;
            *tmp_ptr = value;
            value = tmp;
            tmp_ptr++;
        }
        ptr = tmp_ptr;
        size++;
    }

    void remove(int index) {

    }
    
    int pop() {
        if (size > 0) {
            int val = *ptr;
            *ptr = 0;
            ptr--;
            size--;
            return val; 
        }
        return 0;
    }

    void print() {
        int* tmp = arr;
        cout << "[ ";
        for (int i = 0; i < size; i++) {
           cout << *tmp << " "; 
           tmp++;
        }        
        cout << "]" << endl;
    }

    int length() {
        return size;
    }

    int capacity() {
        return cap;
    }

    bool empty() {
        return size == 0;
    }

    void clear() {
        for (int i=0; i < size; i++) {
            *ptr = 0;
            ptr--;
        }
        size = 0;
    }

};

int main() { 
    StaticArray arr = StaticArray(10);
    arr.append(15);
    arr.append(18);
    arr.append(23);
    arr.append(17);
    arr.append(2);
    arr.print();
    arr.insert(69, 3);
    arr.print();
}