#ifndef PRINT_ARRAY_H_INCLUDED
#define PRINT_ARRAY_H_INCLUDED
#include <vector>
#include <iostream>
using namespace std;

void print_array(vector<int> arr) {
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}
#endif