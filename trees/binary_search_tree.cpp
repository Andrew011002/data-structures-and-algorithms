#include <iostream>
#include <assert.h>
#include "node.hpp"
#include "print_tree.hpp"
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

Node* get_min_node(Node *node) {
    Node *curr = node;
    while (curr && curr->left) {
        curr = curr->left;
    }
    return curr;
}

Node* get_max_node(Node *node) {
    Node *curr = node;
    while (curr && curr->right) {
        curr = curr->right;
    }
    return curr;
}

Node* remove(Node *node, int val) {
    if (!node) {
        return nullptr;
    }

    if (node->val < val) {
        node->right = remove(node->right, val);
    } else if (node->val > val) {
        node->left = remove(node->left, val);
    } else {
        if (!node->right) {
            Node *temp = node->left;
            free(node);
            return temp;
        } else if (!node->left) {
            Node *temp = node->right;
            free(node);
            return temp;
        } else {
            Node *min_node = get_min_node(node->right);
            node->val = min_node->val;
            node->right = remove(node->right, node->val);
        }
    }
    return node;
}

int main() {

    Node bst = Node(6);
    print_tree(&bst);

    assert(search(&bst, 6) == true);
    assert(search(&bst, 1) == false);
    cout << "search() tests passed\n";

    insert(&bst, 8);
    insert(&bst, 2);
    insert(&bst, 1);
    insert(&bst, 3);
    print_tree(&bst);

    assert(search(&bst, 8) == true);
    assert(search(&bst, 2) == true);
    assert(search(&bst, 1) == true);
    assert(search(&bst, 3) == true);

    assert(bst.left->val == 2);
    assert(bst.right->val == 8);
    assert(bst.left->left->val == 1);
    assert(bst.left->right->val == 3);

    cout << "insert() tests passed\n";

    assert(get_min_node(&bst)->val == 1);
    assert(get_max_node(&bst)->val == 8);
    assert(get_max_node(bst.left)->val == 3);
    assert(get_min_node(bst.left)->val == 1);
    assert(get_max_node(bst.right)->val == 8);

    cout << "get_min_node() and get_max_node() tests passed\n";

    Node bst2 = bst;
    remove(&bst2, 2);
    print_tree(&bst2);
    assert(bst2.left->val == 3);
    assert(bst2.left->left->val == 1);

    insert(&bst2, 4);
    insert(&bst2, 7);
    insert(&bst2, 9);
    print_tree(&bst2);

    remove(&bst2, 6);
    print_tree(&bst2);
    assert(bst2.val == 7);

    remove(&bst2, 8);
    print_tree(&bst2);
    assert(bst2.right->val == 9);

    remove(&bst2, 4);
    print_tree(&bst2);
    assert(bst2.left->right == nullptr);

    cout << "remove() tests passed\n";
}
