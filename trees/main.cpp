#include "node.hpp"
#include "bst.hpp"
#include <cstdio>

int main() {
    Node<int, int> node = Node<int, int>(10);
    BST<int, int> tree;
    node.print();
    printf("%d\n", node.single());
    return 0;
}
