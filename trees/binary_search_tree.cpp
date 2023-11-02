#include <iostream>
#include <assert.h>
#include "node.hpp"
using namespace std;

struct BinarySearchTree {

    Node *root;

    BinarySearchTree(Node *node) {
        root = node;
    }

    bool search(Node *node, int val) {
        if (node == nullptr) {
            return false;
        }

        if (node->val == val) {
            return true;
        }
        if (node->val > val) {
            return search(node->left, val);
        } else {
            return search(node->right, val);
        }
    }
};

int main() {

    Node a = Node(5);
    Node b = Node(3);
    Node c = Node(7);
    Node d = Node(2);
    Node e = Node(4);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;

    BinarySearchTree bst = BinarySearchTree(&a);

    assert (bst.search(&a, 7) == true);
    assert (bst.search(&a, 4) == true);
    assert (bst.search(&b, 2) == true);
    assert (bst.search(&a, 3) == true);

    assert (bst.search(&c, 5) == false);
    assert (bst.search(&b, 5) == false);
    assert (bst.search(&b, 5) == false);
    assert (bst.search(&e, 7) == false);

}