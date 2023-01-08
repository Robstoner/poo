#include "../headers/inventoryItem.h"
#include "../headers/idGenerator.h"

InventoryItem::InventoryItem(const std::string &id, const InventoryItemFlyweight &flyweight, int quantity)
    : id(id), flyweight(flyweight), quantity(quantity) {}

const std::string &InventoryItem::getID() const
{
    return id;
}

const InventoryItemFlyweight &InventoryItem::getFlyweight() const
{
    return flyweight;
}

int InventoryItem::getQuantity() const
{
    return quantity;
}

InventoryItem InventoryItem::clone() const
{
    return InventoryItem(id, flyweight, quantity);
}

void InventoryItem::print() const
{
    std::cout << "ID: " << id << std::endl;
    std::cout << "Type: " << flyweight.getType() << std::endl;
    std::cout << "Size: " << flyweight.getSize() << std::endl;
    std::cout << "Color: " << flyweight.getColor() << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
}