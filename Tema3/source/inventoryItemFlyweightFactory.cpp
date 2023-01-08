#include "../headers/inventoryItemFlyweightFactory.h"

const InventoryItemFlyweight &InventoryItemFlyweightFactory::getFlyweight(const std::string &type, const std::string &size, const std::string &color)
{
    std::string key = type + size + color;
    flyweights.try_emplace(key, InventoryItemFlyweight(type, size, color));
    return flyweights[key];
}