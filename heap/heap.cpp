#include <iostream>
#include <vector>
#include "../utils/print.hpp"
using namespace std;

struct Heap {

private:

    vector<int> heap;
    bool is_max;

    int compare(int a, int b) {
        if (is_max) {
            return a > b;
        }
        return a < b;
    }

    void percolate_up(int index) {
        while (index > 1 && compare(heap[index], heap[index / 2])) {
            int tmp = heap[index / 2];
            heap[index / 2] = heap[index];
            heap[index] = tmp;
            index /= 2;
        }
    }

    void percolate_down(int index) {
        while (2 * index < heap.size()) {
            // has both children
            if (2 * index + 1 < heap.size() && 
                compare(heap[index * 2 + 1], heap[index]) && 
                compare(heap[index * 2 + 1], heap[index * 2])) {
                int tmp = heap[index * 2 + 1];
                heap[index * 2 + 1] = heap[index];
                heap[index] = tmp; 
                index = index * 2 + 1;
            // has left
            } else if (2 * index < heap.size() && 
                compare(heap[index * 2], heap[index])) {
                    int tmp = heap[index * 2];
                    heap[index * 2] = heap[index];
                    heap[index] = tmp;
                    index = index * 2;
            // has none
            } else {
                break;
            }
        }
    }

public:

    Heap(bool max=true) {
        is_max = max;
        heap.push_back(0);
    }

    Heap(vector<int> arr, bool max=true) {
        heapify(arr, max);
    }

    void heapify(vector<int> arr, bool max) {
        arr.push_back(arr[0]);
        arr[0] = 0;
        heap = arr;
        is_max = max;

        int index = (arr.size() - 1) / 2;

        while (index > 0) {
            percolate_down(index);
            index--;
        }
    }

    void push(int val) {
        heap.push_back(val);
        int index = heap.size() - 1;
        // percolate up
        percolate_up(index);
    }

    int pop() {
        if (heap.size() == 1) {
            return -1;
        } 

        int index = 1;
        int num = heap[index];
        heap[index] = heap[heap.size() - 1];
        heap.pop_back();
        percolate_down(index);
        return num;
    }
    
    int top() {
        if (heap.size() == 1) {
            return -1;
        } 
        return heap[1];
    }

    int size() {
        return heap.size() - 1;
    }

    void print() {
        print_vector(heap);
    }
};

int main() {

    printf("Min Heap\n");

    printf("push\n");
    Heap heap = Heap(false);
    heap.push(2);
    heap.push(3);
    heap.push(5);
    heap.push(18);
    heap.push(21);
    heap.print();
    printf("size: %d\n", heap.size());

    printf("\npop\n");
    int num = heap.pop();
    printf("num: %d\n", num);
    heap.print();
    num = heap.pop();
    printf("num: %d\n", num);
    heap.print();
    num = heap.pop();
    printf("num: %d\n", num);
    heap.print();
    printf("size: %d\n", heap.size());
    
    vector<int> arr = {1, 3, 6, 2, 4, 18, 10, 5};
    heap = Heap(arr, false);

    printf("\nheapify\n");
    heap.print();
    num = heap.pop();
    printf("num: %d\n", num);
    heap.print();
    num = heap.pop();
    printf("num: %d\n", num);
    heap.print();
    num = heap.pop();
    printf("num: %d\n", num);
    heap.print();
    printf("size: %d\n", heap.size());

    printf("\nMax Heap\n");


    printf("push\n");
    heap = Heap(true);
    heap.push(2);
    heap.push(3);
    heap.push(5);
    heap.push(18);
    heap.push(21);
    heap.print();
    printf("size: %d\n", heap.size());

    printf("\npop\n");
    num = heap.pop();
    printf("num: %d\n", num);
    heap.print();
    num = heap.pop();
    printf("num: %d\n", num);
    heap.print();
    num = heap.pop();
    printf("num: %d\n", num);
    heap.print();
    printf("size: %d\n", heap.size());
    
    arr = {1, 3, 6, 2, 4, 18, 10, 5};
    heap = Heap(arr, true);

    printf("\nheapify\n");
    heap.print();
    num = heap.pop();
    printf("num: %d\n", num);
    heap.print();
    num = heap.pop();
    printf("num: %d\n", num);
    heap.print();
    num = heap.pop();
    printf("num: %d\n", num);
    heap.print();
    printf("size: %d\n", heap.size());

}