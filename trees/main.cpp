#include "node.hpp"
#include "bst.hpp"

int main() {
    Node<int, int> node = Node<int, int>(10);
    BST<int, int> tree;
    node.print();
    return 0;
}
