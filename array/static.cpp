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

    void insert() {

    }

    void append(int elem) {
        *ptr = elem;
        ptr++;
        size++;
    }

    void remove() {

    }

    void print() {
        int* temp = arr;
        cout << "[ ";
        for (int i = 0; i < size; i++) {
           cout << *temp << " "; 
           temp++;
        }        
        cout << "]" << endl;
    }

    int len() {
        return size;
    }

    int capacity() {
        return cap;
    }

};

int main() { 
    StaticArray arr = StaticArray(10);
    arr.append(10);
    arr.append(11);
    arr.print();

    int array[10] = {1, 2, 3};
    arr = StaticArray(array, 3, 10);
    arr.print(); 
    cout << arr.len() << " " << arr.capacity() << endl;
}