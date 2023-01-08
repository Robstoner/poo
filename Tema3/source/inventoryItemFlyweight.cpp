#include "../headers/inventoryItemFlyweight.h"

InventoryItemFlyweight::InventoryItemFlyweight(const std::string &type, const std::string &size, const std::string &color)
    : type(type), size(size), color(color) {}

InventoryItemFlyweight::InventoryItemFlyweight(const InventoryItemFlyweight &other) : type(other.type), size(other.size), color(other.color) {}

const InventoryItemFlyweight &InventoryItemFlyweight::operator=(const InventoryItemFlyweight &other)
{
    if (this != &other)
    {
        type = other.type;
        size = other.size;
        color = other.color;
    }
    return *this;
}

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