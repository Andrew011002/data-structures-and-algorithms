#include <functions.h>
#include <iostream>
#include <vector>
using namespace std;

void print_array(vector<int> vect) {
    cout << "[ ";
    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << " ";
    }
    cout << "]\n";
}