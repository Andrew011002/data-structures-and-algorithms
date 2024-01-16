#include <string>
#include "hashmap.hpp"

int main() {
    HashMap<std::string, int> map;
    printf("%d\n", map.hash("hello"));
}