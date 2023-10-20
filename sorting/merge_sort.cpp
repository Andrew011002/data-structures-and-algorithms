#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end) {
    // get copies of arrays
    vector<int> left(arr.begin() + start, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + end + 1);
    int l = 0;
    int r = 0;
    int i = start; /* important that we start here & not zero to reflect 
                    where we're at in the "main" array */

    // merge the two copied left & right subarrays to main sorted array
    while (l < left.size() && r < right.size()) {
        // use '<=' to assure stable sorting
        if (left[l] <= right[r]) {
            arr[i] = left[l++];
        } else {
            arr[i] = right[r++];
        }
        i++;
    }
    
    // add remaining subarrays

    // left subarray has elements
    while (l < left.size()) {
        arr[i++] = left[l++];
    }
    // right subarray has elements
    while (r < right.size()) {
        arr[i++] = right[r++];
    }
}

void merge_sort(vector<int> &arr, int start, int end) {
    // base case (array of one element)
    if (end - start + 1 <= 1) {
        return;
    }

    // middle index that defines where we'll cut the array in half
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid); // dividing the left portion
    merge_sort(arr, mid + 1, end); // dividing the right portion

    // start merging our sorted subarrays
    merge(arr, start, mid, end);
}

void print_array(vector<int> vect) {
    cout << "[ ";
    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << " ";
    }
    cout << "]\n";
}

int main() {
    vector<int> vect = {3, 8, 1, 0};
    merge_sort(vect, 0, vect.size() - 1);
    print_array(vect);
    vect = {1, 2, 3, 4};
    merge_sort(vect, 0, vect.size() - 1);
    print_array(vect);
    vect = {4, 3, 2, 1};
    merge_sort(vect, 0, vect.size() - 1);
    print_array(vect);
}