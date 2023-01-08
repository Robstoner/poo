#ifndef INVENTORYITEMFLYWEIGHTFACTORY_H
#define INVENTORYITEMFLYWEIGHTFACTORY_H
#include <unordered_map>
#include "inventoryItemFlyweight.h"

class InventoryItemFlyweightFactory
{
private:
    std::unordered_map<std::string, InventoryItemFlyweight> flyweights;

public:
    const InventoryItemFlyweight &getFlyweight(const std::string &type, const std::string &size, const std::string &color);
};

#endif // INVENTORYITEMFLYWEIGHTFACTORY_H