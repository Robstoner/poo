#include "../headers/inventoryItemFlyweight.h"

InventoryItemFlyweight::InventoryItemFlyweight(const std::string &type, const std::string &size, const std::string &color)
    : type(type), size(size), color(color) {}

const std::string &InventoryItemFlyweight::getType() const
{
    return type;
}

const std::string &InventoryItemFlyweight::getSize() const
{
    return size;
}

const std::string &InventoryItemFlyweight::getColor() const
{
    return color;
}