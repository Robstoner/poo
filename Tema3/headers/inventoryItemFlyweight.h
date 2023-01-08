#ifndef INVENTORYITEMFLYWEIGHT_H
#define INVENTORYITEMFLYWEIGHT_H
#include <string>

// sablon de proiectare Flyweight

class InventoryItemFlyweight
{
private:
    std::string type;
    std::string size;
    std::string color;

public:
    InventoryItemFlyweight() = default;

    InventoryItemFlyweight(const std::string &type, const std::string &size, const std::string &color);

    InventoryItemFlyweight(const InventoryItemFlyweight &other);

    const InventoryItemFlyweight &operator=(const InventoryItemFlyweight &other);

    const std::string &getType() const;

    const std::string &getSize() const;

    const std::string &getColor() const;
};

#endif // INVENTORYITEMFLYWEIGHT_H