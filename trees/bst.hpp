#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;


struct Node {

    int data;
    Node *left;
    Node *right;

    Node() {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }

    Node(int value, Node *left_node, Node *right_node) {
        data = value;
        left = left_node;
        right = right_node;
    }
};


class BST {

public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void build_tree(const vector<int>& list) {
        for (int value : list) {
            root = insert(root, value);
        }
    }

private:
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        return node;
    }
};

#endif
