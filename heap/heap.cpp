#include <iostream>
#include <vector>
#include "../print.hpp"

struct Heap {

private:
vector<int> heap;
bool is_max;

int compare(int a, int b) {
    if (is_max) {
        return a >= b;
    }
    return a <= b;
}

public:

Heap(bool max=true) {
    is_max = max;
    heap.push_back(0);
}

void heapify(vector<int> arr, bool max) {
    is_max = max;
    heap = arr;

    // heapify code here
}

void push(int val) {
    heap.push_back(val);
    int index = heap.size() - 1;

    while (index > 1 && compare(heap[index], heap[index / 2])) {
        int tmp = heap[index / 2];
        heap[index / 2] = heap[index];
        heap[index] = tmp;
        index /= 2;
    }
}

    int pop() {
        if (heap.size() == 1) {
            return -1;
        } else if (heap.size() == 2) {
            int num = heap[1];
            heap.pop_back();
            return num;
        }

        int index = 1;
        int num = heap[index];
        heap[index] = heap[heap.size() - 1];
        heap.pop_back();
        
        while (2 * index < heap.size()) {
            
            // has both children
            if (2 * index + 1 < heap.size() && 
                !compare(heap[index], heap[index * 2 + 1]) && 
                compare(heap[index * 2 + 1], heap[index * 2])) {

            }
            // has left
            // has none

        }

        return num;
    }

    int size() {
        return heap.size() - 1;
    }

    void print() {
        print_vector(heap);
    }
};

int main() {

    Heap heap = Heap();
    heap.push(2);
    heap.push(3);
    heap.push(5);
    heap.print();

}