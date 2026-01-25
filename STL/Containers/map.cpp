#include <iostream>
#include <map>
#include <string>

int main() {
    // 1. Declaration: map<KeyType, ValueType>
    std::map<std::string, int> inventory;

    // 2. Insertion
    inventory["apples"] = 50;
    inventory["bananas"] = 20;
    inventory.insert({"cherries", 15});

    // 3. Access (Searching)
    std::cout << "We have " << inventory["apples"] << " apples." << std::endl;

    // 4. Checking if a key exists
    if (inventory.find("grapes") == inventory.end()) {
        std::cout << "Grapes are not in stock." << std::endl;
    }

    // 5. Iterating (Always stays sorted by key!)
    for (const auto& [fruit, count] : inventory) {
        std::cout << fruit << ": " << count << "\n";
    }

    return 0;
}