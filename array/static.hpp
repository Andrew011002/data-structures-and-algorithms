#ifndef STATIC_ARRAY_HPP
#define STATIC_ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

struct StaticArray {
    private:
        int* arr;
        int* ptr;
        int nelem;
        int cap;

        void in_bounds_check(int index, string msg);
        void can_add_check(string msg);
        void can_retrieve_check(string msg);
        int* move_ptr_to_index(int* ptr, int index);

    public:
        StaticArray(int capacity);
        StaticArray(int array[], int size, int capacity);
        int get(int index);
        void append(int elem);
        void insert(int elem, int index);
        void remove(int elem);
        int pop();
        int size();
        int capacity();
        bool empty();
        bool full();
        void clear();
        void print();
};

#endif