#include <iostream>
#include <vector>
#include <functions.h>
using namespace std;

void quick_sort(vector<int> &arr, int start, int end) {
    // base case (array of one element)
    if (end - start + 1 <= 1) {
        return;
    }

    // get left pointer (insertion pointer) & pivot value
    int l = start;
    int pivot = arr[end];
    int temp;

    // compare all values that come before pivot index (end) to pivot value
    for (int i = start; i < end; i++) {

        // perform swaps for values less than or equal pivot (keep in place other wise)
        if (arr[i] <= pivot) {
            temp = arr[i];
            arr[i] = arr[l];
            arr[l++] = temp; // make sure to increment left pointer after swap
        }
    }

    // swap pivot value & value at the left pointer
    arr[end] = arr[l];
    arr[l] = pivot;

    // run quick sort on values to left of pivot (less than or equal to) & right of pivot (greater than)
    quick_sort(arr, start, l - 1);
    quick_sort(arr, l + 1, end);
}

int main() {
    vector<int> vect = {3, 8, 1, 0};
    quick_sort(vect, 0, vect.size() - 1);
    print_array(vect);
    vect = {1, 2, 3, 4};
    quick_sort(vect, 0, vect.size() - 1);
    print_array(vect);
    vect = {4, 3, 2, 1};
    quick_sort(vect, 0, vect.size() - 1);
    print_array(vect);
    vect = {4, 3, 2, 1, 0, 3, 8, 9, -1, 20};
    quick_sort(vect, 0, vect.size() - 1);
    print_array(vect);

    vect = {3, 2, 1, 5, 6, 4};
    quick_sort(vect, 0, vect.size() - 1);
    print_array(vect);
}