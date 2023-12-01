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

void print_vector(vector<int> vec) {
    cout << "[ ";
    for (int i=0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "]" << endl;
}

#endif