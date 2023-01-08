#include "../headers/inventoryItemFlyweightFactory.h"

const InventoryItemFlyweight &InventoryItemFlyweightFactory::getFlyweight(const std::string &type, const std::string &size, const std::string &color)
{
    std::string key = type + size + color;
    if (flyweights.count(key) == 0)
    {
        flyweights[key] = InventoryItemFlyweight(type, size, color);
    }
    return flyweights[key];
}