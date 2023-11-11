#include <iostream>
#include <vector>
#include <queue>
#include "bst.hpp"
#include "print_helper.hpp"
using namespace std;

vector<int> bfs(Node* root) {
    if (!root) {
        return {};
    }
    queue<Node*> nodes;
    vector<int> traversal;

    nodes.push(root);
    while (!nodes.empty()) {
        root = nodes.front();
        nodes.pop();
        traversal.push_back(root->data);
        if (root->left) {
            nodes.push(root->left);
        }
        if (root->right) {
            nodes.push(root->right);
        }
    }
    return traversal;
}

int main() {

    vector<int> list = {15, 10, 20, 8, 12, 17, 25, 6, 9, 11, 13, 16, 19, 23, 27};
    BST tree = BST();
    tree.build_tree(list);
    print_tree(tree.root);
    
    vector<int> traversal = bfs(tree.root);
    print_array(traversal);
    
}