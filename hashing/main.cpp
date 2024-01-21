#include <vector>
#include <utility>
#include <string>
#include "hashmap.hpp"

int main() {
    HashMap<std::string, int> map;
    map.add("Andrew", 11);
    map.print();
    printf("size: %d\n", map.size());
    map.add("Alexis");
    map.print();
    map.add("Caitlin", 29);
    map.add("Brian");
    map.replace("Andrew", 22);
    map.add("Kim");
    map.add("Austin");
    map.print();
    map.remove("Andrew");
    map.add("Natalie", 15);
    map.add("Terry", 17);
    map.add("Maia", 55);
    map.add("Kim", 20);
    printf("Contains ? %d\n", map.contains("Andrew"));
    map.replace("Terry", 83);
    map.add("Austin", 69);
    map.print();
}