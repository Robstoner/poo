#include "headers/inventoryManager.h"
#include "headers/inventoryItem.h"
#include "headers/idGenerator.h"

int main()
{
    InventoryManager<InventoryItem> manager;

    manager.addItem("T-shirt", "M", "red", 10);
    manager.addItem("T-shirt", "M", "red", 10);
    manager.addItem("T-shirt", "M", "blue", 30);
    manager.addItem("T-shirt", "M", "red", 50);
    manager.addItem("T-shirt", "S", "red", 10);
    manager.addItem("T-shirt", "S", "red", 30);
    manager.addItem("T-shirt", "S", "red", 20);
    manager.addItem("T-shirt", "L", "red", 10);
    manager.addItem("T-shirt", "L", "red", 10);
    manager.addItem("T-shirt", "L", "red", 10);
    int i = 0;
    for (auto &item : manager)
    {
        i++;
        std::cout << i << std::endl;
        item.print();
        std::cout << std::endl;
    }

    std::cout << "Clone: " << std::endl;
    InventoryItem clone = manager.getRandomItem().clone();
    clone.print();
    std::cout << std::endl;

    std::unordered_map<std::string, InventoryItem> items = manager.getItems();

    std::cout << "Items: " << std::endl;
    for (auto &item : items)
    {
        item.second.print();
        std::cout << std::endl;
    }

    return 0;
}