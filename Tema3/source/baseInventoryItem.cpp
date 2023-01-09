#include "../headers/baseInventoryItem.h"

BaseInventoryItem::BaseInventoryItem() : id("") {}

BaseInventoryItem::BaseInventoryItem(const std::string &id) : id(id) {}

const std::string &BaseInventoryItem::getID() const
{
    return id;
}

