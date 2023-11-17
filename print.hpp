#ifndef PRINT_H_HEADER_FILE
#define PRINT_H_HEADER_FILE

#include <iostream>
using namespace std;

void print_array(int arr[], int size) {
    cout << "[ ";
    for (int i=0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

#endif