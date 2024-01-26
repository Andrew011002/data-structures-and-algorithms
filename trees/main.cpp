#include "bst.hpp"

int main() {
    BST<int, int> tree;
    tree.add(10);
    tree.add(11, 25);
    tree.add(9);
    tree.print("preorder");
    tree.print("inorder");
    tree.print("postorder");
    return 0;
}
