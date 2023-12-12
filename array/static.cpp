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
    arr.append(15);
    arr.pop();
    arr.print();
}