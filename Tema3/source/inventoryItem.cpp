#include "../headers/inventoryItem.h"

InventoryItem::InventoryItem() : BaseInventoryItem(""), flyweight(InventoryItemFlyweight()), quantity(0) {}

InventoryItem::InventoryItem(const std::string &id, const InventoryItemFlyweight &flyweight, int quantity)
    : BaseInventoryItem(id), flyweight(flyweight), quantity(quantity) {}

InventoryItem::InventoryItem(const InventoryItem &other) : BaseInventoryItem(other.id), flyweight(other.flyweight), quantity(other.quantity) {}

const InventoryItem &InventoryItem::operator=(const InventoryItem &other)
{
    if (this != &other)
    {
        id = other.id;
        flyweight = other.flyweight;
        quantity = other.quantity;
    }
    return *this;
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