#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include "./static.hpp"
using namespace std;

struct DynamicArray: public StaticArray {

    DynamicArray();
    DynamicArray(int array[]);
    void resize() {}
};

#endif