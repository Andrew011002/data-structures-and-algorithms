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
        assert(false);
    } catch (const std::out_of_range& e) {
        assert(true);
    }
}

int main() {
    test_get();
}