#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "bst.hpp"
#include "print_helper.hpp"
using namespace std;

struct MapNode {

    string name;
    int data;
    MapNode *left;
    MapNode *right;

    MapNode() {
        name = "";
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    MapNode(string key, int value) {
        name = key; 
        data = value;
        left = nullptr;
        right = nullptr;
    }

    MapNode(string key, int value, MapNode *left_node, MapNode *right_node) {
        name = key;
        data = value;
        left = left_node;
        right = right_node;
    }
};


class TreeMap {

public:
    MapNode* root;

    TreeMap() {
        root = nullptr;
    }

    void build_tree(const map<string, int>& mapping) {
        for (const auto& pair : mapping) {
            root = insert(root, pair.first, pair.second);
        }
    }

    MapNode* insert(MapNode* node, string key, int value) {
        if (node == nullptr) {
            return new MapNode(key, value);
        }

        if (node->name.compare(key) > 0) {
            node->left = insert(node->left, key, value);
        } else {
            node->right = insert(node->right, key, value);
        }

        return node;
    }
};

void print_tree_helper(MapNode *node, string prefix = "", bool isLeft = true) {
    if (node != nullptr) {
        cout << prefix;
        cout << (isLeft ? "├──" : "└──" );
        cout << node->name << ": " << node->data << endl;
        
        print_tree_helper(node->left, prefix + (isLeft ? "│   " : "    "), true);
        print_tree_helper(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }
}

void print_tree(MapNode* root) {
    print_tree_helper(root, "", false);    
}


int main() {

    map<string, int> games = {{"call_of_duty", 70}, {"the_witcher", 60}}; 
    TreeMap tree_map = TreeMap();
    tree_map.root = tree_map.insert(tree_map.root, "star_wars", 80);
    tree_map.build_tree(games);
    print_tree_helper(tree_map.root);
}