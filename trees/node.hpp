#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

struct Node {

    int val;
    Node *left;
    Node *right;

    Node() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    Node(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }

    Node(int value, Node *left_node, Node *right_node) {
        val = value;
        left = left_node;
        right = right_node;
    }
};

#endif
