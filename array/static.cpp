#include <iostream>
#include "../print.hpp"
using namespace std;

struct StaticArray {
    int* arr;
    int* ptr;
    int nelem;
    int cap;

public:

    StaticArray(int size) {
        arr = new int[size];
        cap = size;
    }

    void insert() {

    }

    void append() {

    }

    void remove() {

    }

    void print() {

    }

    int len() {
        return nelem;
    }

    int capacity() {
        return cap;
    }

};

int main() { 

    /*
    A static array is a contiguous block of memory that stores elements. The
    number of elements that can be stored within the array is fixed
    and is determined by the user.

    The amount of memory allocated is defined by size * sizeof(datatype) in bytes.
    For example, if size = 10 and int size = 4 bytes, the memory size = 10 * 4 = 40 bytes.

    Arrays have indices that correlate to memory addresses within RAM.
    When you access an element via its index, it retrieves the element in RAM
    based on the memory address it correlates to in constant time O(1).

    The same is done for writing values into an array via an index, but instead
    of retrieving the value at that index, it overwrites it with the value
    you assign to it.

    When you add or append elements to an array, it adds the desired element
    to the first available memory address within the array block. This
    process is also O(1). After the element is added, the pointer is incrementally
    moved (by the number of bytes each element takes up) to append the next available
    element in the future.

    For removing elements from the end, the same process is applied, except the pointer decrements
    (by the number of bytes each element takes up) to overwrite the last value
    at the end of the array with zero or some arbitrary number and remains at that
    position (memory address) for future removals or to ensure valid appending.

    Arrays can also insert values. Inserting is not a constant time operation because it goes
    to the position where you want to insert, then moves the values over
    ahead of the insertion position (O(n)) to maintain the order of the array.

    Almost the same can be said for removing values (not at the end), because
    it goes to the position you want to delete and removes it by shifting all
    subsequent elements one position to the left, which at worst involves shifting the entire array
    if you remove the first element of an array with more than one element.

    In the case that the array is full for appending/inserting or empty for
    removing at any position within the array, an error is typically thrown
    as the static array cannot write to more memory than it has been allocated
    and it cannot remove values it does not contain.
    */

    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, size);


}