#include "bst.hpp"
#include <optional>
#include <string>

int main() { BST<std::string, int> tree; 
    tree.add("John", 15);
    tree.add("Mike", 21);
    tree.add("Bill", 19);
    tree.add("Sarah", 18);
    tree.print();
    tree.remove("Sarah");
    tree.print();
    tree.add("Rufus");
    tree.print();
    printf("%s -> %d\n", "John", tree.get("John").value_or(-1));
    printf("Size: %d\n", tree.size());
    printf("%s -> %d\n", "Rufus", tree.get("Rufus").value_or(-1));
}
