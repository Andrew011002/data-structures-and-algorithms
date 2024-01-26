#include "node.hpp"

int main() {
    Node<int, int> node = Node<int, int>(10, 11);
    node.print();
    return 0;
}
