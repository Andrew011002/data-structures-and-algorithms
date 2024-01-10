#include <vector>
#include <array>
#include "singly.hpp"
#include "doubly.hpp"

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    SinglyList<int> singly;
    for (int num: vec) {
        singly.add(num);
    }
    singly.print();

    DoublyList<int> doubly = DoublyList<int>(vec);
    doubly.print();
    std::cout << doubly.contains(3) << "\n";

}