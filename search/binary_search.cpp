#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int binary_search(vector<int> &nums, int num) {
    // assign/ init pointers
    int low = 0;
    int high = nums.size() - 1;
    int mid, val;

    // continue the search as long as our pointers don't "overcross"
    while (low <= high) {
        // get index between low and high (middle)
        mid = (low + high) / 2;
        val = nums[mid];

        if (val < num) { // too small, move low pointer over
            low = mid + 1;
        } else if (val > num) { // too large, more high pointer over
            high = mid - 1;
        } else { // value found, so return index location
            return mid;
        }
    }
    return -1; // value was not found
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 4, 4, 5, 9, 9, 12, 13, 13, 15};
    assert(binary_search(nums, 5) == 6);
    assert(binary_search(nums, 1) == 0);
    assert(binary_search(nums, 7) == -1);

    nums = {1, 2};
    assert(binary_search(nums, 1) == 0);
    assert(binary_search(nums, 2) == 1);
    assert(binary_search(nums, 3) == -1);

    nums = {};
    assert(binary_search(nums, 1) == -1);
    assert(binary_search(nums, 2) == -1);
    assert(binary_search(nums, 3) == -1);

    cout << "All tests passed!\n";
}