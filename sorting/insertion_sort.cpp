#include <iostream>
#include <vector>
#include <functions.h>
using namespace std;

void insertion_sort(vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++) {
        int j = i - 1;

        while (j >= 0 && arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int main() {
    vector<int> vect = {3, 8, 1, 0};
    insertion_sort(vect);
    print_array(vect);
    vect = {1, 2, 3, 4};
    insertion_sort(vect);
    print_array(vect);
    vect = {4, 3, 2, 1};
    insertion_sort(vect);
    print_array(vect);
}
