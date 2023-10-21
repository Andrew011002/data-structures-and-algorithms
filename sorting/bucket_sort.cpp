#include <iostream>
#include <vector>
#include <algorithm>
#include <functions.h>
using namespace std;

void bucket_sort(vector<int> &arr, int low, int high) {
    // get counts array
    vector<int> counts(high - low + 1, 0);

    // populate array with occurences for value
    for (int i = 0; i < arr.size(); i++) {
        /* we want counts of lowest value to be at index zero, 
        so we  make all values relative to low where low is basically zero */
        counts[arr[i] - low]++; 
    }

    /*Nowe we add the values based on their frequencies starting
    with the lowest value & incrementing as we add values*/
    int i = 0;
    for (int j = 0; j < counts.size(); j++) { // j is a value in the og array
        for (int k = 0; k < counts[j]; k++) { // we want to add j how many times it occured
            arr[i++] = j + low; // we modify in-place while incrementing our pointer for where to insert
        }
    }
}

int main() {
    vector<int> arr = {0, 3, 3, 1, 1, 2, 2, 5, 4, 18};
    int min_val = *min_element(arr.begin(), arr.end());
    int max_val = *max_element(arr.begin(), arr.end());
    bucket_sort(arr, min_val, max_val);
    print_array(arr);

    arr = {5, 4, 6, 6, 2, 0, 1, 5, 10, 3, 2, 0, 0, 1, 3};
    min_val = *min_element(arr.begin(), arr.end());
    max_val = *max_element(arr.begin(), arr.end());
    bucket_sort(arr, min_val, max_val);
    print_array(arr);

    arr = {5, -4, 6, -6, 2, 0, 1, 5, 10, -3, 2, 0, 0, 1, -3};
    min_val = *min_element(arr.begin(), arr.end());
    max_val = *max_element(arr.begin(), arr.end());
    bucket_sort(arr, min_val, max_val);
    print_array(arr);
}