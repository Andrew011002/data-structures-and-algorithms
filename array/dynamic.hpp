#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include "./static.hpp"
using namespace std;

struct DynamicArray: public StaticArray {

public:
    DynamicArray(int capacity=10);
    DynamicArray(int array[], int size);
    void append(int elem) override; 
    void insert(int index, int elem) override;
    void resize(int capacity);
};

#endif