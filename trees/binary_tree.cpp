#include <iostream>
#include "node.hpp"
using namespace std;

struct BinaryTree {

    Node *root;
    int height;

    BinaryTree(Node *node) {
        root = node;
    }
};

int main() {

    Node a = Node(5);
    Node b = Node(4);
    Node c = Node(3);
    Node d = Node(4);
    Node e = Node(8);
    Node f = Node(2);
    Node g = Node(11);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;

}