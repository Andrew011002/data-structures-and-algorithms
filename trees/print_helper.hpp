#ifndef PRINT_HELPER_H_INCLUDED
#define PRINT_HELPER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "bst.hpp"
using namespace std;


void print_array(vector<int> arr) {
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

void print_tree_helper(Node *node, string prefix = "", bool isLeft = true) {
    if (node != nullptr) {
        cout << prefix;
        cout << (isLeft ? "├──" : "└──" );
        cout << node->data << endl;
        
        print_tree_helper(node->left, prefix + (isLeft ? "│   " : "    "), true);
        print_tree_helper(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }
}

void print_tree(Node* root) {
    print_tree_helper(root, "", false);    
}

#endif