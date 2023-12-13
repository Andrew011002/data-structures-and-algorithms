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
        size = 0;
        cap = capacity;
    }

    StaticArray(int array[], int nelem, int capacity) {
        arr = array;
        ptr = arr;
        size = nelem;
        cap = capacity;
    }

    int get(int index) {
        if (empty()) {        
            return 0;
        }

        if (index >= size) {
            cout << "here" << endl;
            *(ptr - 1);
        }

        int* tmp_ptr = arr;
        for (int i=0; i < index; i++) {
            tmp_ptr++;
        }
        return *tmp_ptr;
    }

    void append(int elem) {
        if (full()) {
            return;
        }

        *ptr = elem;
        ptr++;
        size++;
    }

    void insert(int value, int index) {
        if (full()) {
            return;
        }

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

    void remove(int value) {
        if (empty()) {
            return;
        }

        bool found = false;
        int* tmp_ptr = arr;
        int index;
        
        for (int i=0; i < size; i++) {
            if (*tmp_ptr == value) {
                index = i;
                found = true;
                break;
            }
            tmp_ptr++;
        }

        if (found) {
            for (int i=index; i < size - 1; i++) {
                value = *(tmp_ptr + 1);
                *tmp_ptr = value;
                tmp_ptr++;
            }
            ptr = tmp_ptr;
            size--;
        }
    }
    
    int pop() {
        if (empty()) {
            return 0;
        }

        int val = *ptr;
        *ptr = 0;
        ptr--;
        size--;
        return val; 
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
    
    bool full() {
        return size == cap;
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
    for (int i=0; i < 10; i++) {
        arr.append(i * i);
    }
    arr.print();
    cout << "length: " << arr.length() << endl;
    cout << "is full: " << arr.full() << endl;
    // arr.get(5);
    arr.remove(9);
    arr.print();
    cout << "length: " << arr.length() << endl;
    cout << "is full: " << arr.full() << endl;
    arr.append(15);
    arr.print();
    cout << "length: " << arr.length() << endl;
    cout << "is full: " << arr.full() << endl;
    arr.append(15);
    arr.print();
    arr.clear();
    arr.append(16);
    arr.print();
    cout << "length: " << arr.length() << endl;
    cout << "is full: " << arr.full() << endl;
    int val = arr.get(5);
    cout << val << endl;
}