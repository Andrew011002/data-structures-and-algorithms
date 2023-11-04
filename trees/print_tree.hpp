#ifndef PRINT_TREE_H_INCLUDED
#define PRINT_TREE_H_INCLUDED

#include <iostream>
#include <string>
#include "node.hpp"
using namespace std;

void print_tree_helper(Node *node, string prefix = "", bool isLeft = true) {
    if (node != nullptr) {
        cout << prefix;
        cout << (isLeft ? "├──" : "└──" );
        cout << node->val << endl;
        
        print_tree_helper(node->left, prefix + (isLeft ? "│   " : "    "), true);
        print_tree_helper(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }
}

void print_tree(Node* root) {
    print_tree_helper(root, "", false);    
}

#endif