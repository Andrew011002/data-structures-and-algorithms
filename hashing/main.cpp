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
    map.add("John");
    map.print();
    map.add("John");
    map.replace("John", 21);
    map.print();
    map.add("John", 25);
    map.print();
    for (auto key: map.keys()) {
        std::cout << key << " ";
    }
    std::cout << "\n";

    for (auto value: map.values()) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    for (auto item: map.items()) {
        std::cout << item.first << ": ";
        if (item.second.has_value()) {
            std::cout << item.second.value();
        } else {
            std::cout << "null";
        }
        std::cout << " ";
    }
    std::cout << "\n";
    
    std::vector<std::string> keys = map.keys();
    HashMap<std::string, std::string> map2(keys);
    map2.print();
    map2.add("Andrew", "Holmes");
    map2.print();
    printf("size: %d\n", map2.size());

    std::vector<std::pair<std::string, std::string>> vec2 = {{"Lamar", "Jackson"}, {"Christian", "McCaffrey"}, {"Jahmyr", "Gibbs"}, {"Mike", "Evans"}};
    HashMap<std::string, std::string> map3(vec2);
    map3.print();

    HashMap<int, int> map4;
    for (int i=0; i < 100; i++) {
        map4.add(i, i * i);
        std::cout << map4.get(i).value_or(-1) << " ";
    }
    std::cout << "\n";
}