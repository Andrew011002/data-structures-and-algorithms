#include "bst.hpp"
#include <cstdio>

int main() {
    BST<int, int> tree;
    tree.add(10);
    tree.add(11, 25);
    tree.add(9);
    tree.print("preorder");
    tree.print("inorder");
    tree.print("postorder");
    printf("Contains ? %d\n", tree.contains(5));
    printf("Contains ? %d\n", tree.contains(11));
    return 0;
}
