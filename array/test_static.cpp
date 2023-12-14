#include <iostream>
#include <string>
#include <cassert>
#include "./static.hpp"
using namespace std;

void test_get() {
    int testArray[5] = {10, 20, 30, 40, 50};
    StaticArray arr = StaticArray(testArray, 5, 10);
    assert(arr.get(0) == 10);
    assert(arr.get(1) == 20);
    assert(arr.get(4) == 50);
    try {
        arr.get(5);
        assert(false);
    } catch (const std::out_of_range& e) {
        assert(true);
    }
}

void test_append() {
    StaticArray arr = StaticArray(5);

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
    try {
        arr.append(60);
        assert(false);
    } catch (const std::length_error&) {
        assert(true);
    }
}

void test_insert() {
    StaticArray arr = StaticArray(5);

    arr.insert(10, 0);
    assert(arr.get(0) == 10);
    assert(arr.size() == 1);
    cout << "here\n";

    arr.insert(20, 1);
    assert(arr.get(1) == 20);
    assert(arr.size() == 2);

    arr.insert(15, 1);
    assert(arr.get(1) == 15);
    assert(arr.get(2) == 20);
    assert(arr.size() == 3);


    try {
        arr.insert(30, 5);
        assert(false);
    } catch (const std::out_of_range&) {
        assert(true);
    }

    try {
        arr.insert(40, 3); 
        arr.insert(50, 4); 
        assert(false);
    } catch (const std::length_error&) {
        assert(true);
    }
}

int main() {
    test_get();
    test_append();
    test_insert();
}