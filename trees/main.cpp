#include "bst.hpp"
#include <optional>
#include <string>

int main() { BST<std::string, int> tree; 
    tree.add("John", 15);
    tree.add("Mike", 21);
    tree.add("Bill", 19);
    tree.add("Sarah", 18);
    printf("Size: %d\n", tree.size());
    tree.add("Baker");
    tree.print();
    tree.remove("Sarah");
    tree.print();
    tree.add("Rufus");
    tree.print();
    printf("%s -> %d\n", "John", tree.get("John").value_or(-1));
    printf("Size: %d\n", tree.size());
    printf("%s -> %d\n", "Rufus", tree.get("Rufus").value_or(-1));
    printf("Contains %s? %d\n", "Mike", tree.contains("Mike"));
    printf("Contains %s? %d\n", "Sarah", tree.contains("Sarah"));
}
