#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include "../headers/inventoryItemFlyweight.h"
#include "../headers/baseInventoryItem.h"
#include <iostream>

class InventoryItem : public BaseInventoryItem
{
private:
    std::string id;
    const InventoryItemFlyweight &flyweight;
    int quantity;

public:
    InventoryItem(const std::string &id, const InventoryItemFlyweight &flyweight, int quantity);

    const std::string &getID() const;

    const InventoryItemFlyweight &getFlyweight() const;

    int getQuantity() const;

    InventoryItem clone() const;

    void print() const override;
};

#endif // INVENTORYITEM_H