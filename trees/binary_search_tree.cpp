#include <iostream>
#include <assert.h>
#include "node.hpp"
using namespace std;

bool search(Node *node, int val) {
    if (node == nullptr) {
        return false;
    } else if (node->val > val) {
        return search(node->left, val);
    } else if (node->val < val) {
        return search(node->right, val);
    }
    return true;
}

Node* insert(Node *node, int val) {
    if (node == nullptr) {
        return new Node(val);
    }
    if (node->val > val) {
        node->left = insert(node->left, val);
    } else if (node->val < val) {
        node->right = insert(node->right, val);
    }
    return node;
}

int main() {

    Node bst = Node(6);
    assert(search(&bst, 6) == true);
    assert(search(&bst, 1) == false);
    cout << "search() tests passed\n";
    
    insert(&bst, 8);
    insert(&bst, 2);
    insert(&bst, 1);
    insert(&bst, 3);

    assert(search(&bst, 8) == true);
    assert(search(&bst, 2) == true);
    assert(search(&bst, 1) == true);
    assert(search(&bst, 3) == true);

    assert(bst.left->val == 2);
    assert(bst.right->val == 8);
    assert(bst.left->left->val == 1);
    assert(bst.left->right->val == 3);

    cout << "insert() tests passed\n";
}
