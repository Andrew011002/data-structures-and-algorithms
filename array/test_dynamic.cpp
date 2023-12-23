#include <iostream>
#include <cassert>
#include <string>
#include "dynamic.hpp"
using namespace std;

void test_get() {
    int test_array[5] = {10, 20, 30, 40, 50};
    DynamicArray arr = DynamicArray(test_array, 5);
    assert(arr.get(0) == 10);
    assert(arr.get(1) == 20);
    assert(arr.get(4) == 50);
    try {
        arr.get(10);
        assert(false);
    } catch (const exception) {
        assert(true);
    }
}

void test_append() {
    DynamicArray arr = DynamicArray(5);

    arr.append(10);
    assert(arr.get(0) == 10);
    assert(arr.size() == 1);

    arr.append(20);
    assert(arr.get(1) == 20);
    assert(arr.size() == 2);

    arr.append(30);
    assert(arr.get(2) == 30);
    assert(arr.size() == 3);

    arr.append(40);
    assert(arr.get(3) == 40);
    assert(arr.size() == 4);

    arr.append(50);
    assert(arr.get(4) == 50);
    assert(arr.size() == 5);

    arr.append(60);
    assert(arr.get(5) == 60);
    assert(arr.size() == 6);
}

void test_insert() {
    DynamicArray arr = DynamicArray(5);

    arr.insert(0, 10);
    assert(arr.get(0) == 10);
    assert(arr.size() == 1);

    arr.insert(1, 20);
    assert(arr.get(1) == 20);
    assert(arr.size() == 2);

    arr.insert(1, 15);
    assert(arr.get(1) == 15);
    assert(arr.get(2) == 20);
    assert(arr.size() == 3);

    arr.insert(3, 30);
    arr.insert(4, 40); 
    arr.insert(5, 50);
    assert(arr.get(3) == 30);
    assert(arr.get(4) == 40);
    assert(arr.get(5) == 50);
    assert(arr.size() == 6);
}

void test_remove() {
    int test_array[] = {10, 20, 30, 40};
    DynamicArray arr = DynamicArray(test_array, 4);

    arr.remove(20);
    assert(arr.size() == 3);
    assert(arr.get(1) == 30);

    arr.remove(10);
    assert(arr.size() == 2);
    assert(arr.get(0) == 30);

    try {
        arr.remove(50); 
        assert(false);
    } catch (const exception) {
        assert(true);
    }

    arr.remove(30);
    arr.remove(40);
    try {
        arr.remove(1); 
        assert(false);
    } catch (const exception) {
        assert(true);
    }
}

void test_write() {
    DynamicArray arr = DynamicArray(5);

    arr.append(10);
    arr.append(20);
    arr.append(30);

    arr.write(1, 99);
    assert(arr.get(1) == 99);
    assert(arr.size() == 3);

    arr.write(0, 88);
    assert(arr.get(0) == 88);

    arr.write(4, 77); 
    assert(arr.get(4) == 77);
    assert(arr.size() == 5);

    try {
        arr.write(6, 66); 
        assert(false);
    } catch (const exception) {
        assert(true);
    }
}

void test_pop() {
    DynamicArray arr = DynamicArray(5);

    arr.append(10);
    arr.append(69);
    arr.append(30);

    assert(arr.pop() == 30);
    assert(arr.size() == 2);

    assert(arr.pop() == 69);
    assert(arr.size() == 1);

    assert(arr.pop() == 10);
    assert(arr.size() == 0);

    try {
        arr.pop(); 
        assert(false);
    } catch (const exception) {
        assert(true);
    }
}



int main() {
    test_get();
    test_append();
    test_insert();
    test_write();
    test_remove();
    test_pop();
    cout << "All tests passed" << endl;
}