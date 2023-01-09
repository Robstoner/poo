#ifndef BASEINVENTORYITEM_H
#define BASEINVENTORYITEM_H

#include <string>

class BaseInventoryItem
{
protected:
    std::string id;
public:
    BaseInventoryItem();

    BaseInventoryItem(const std::string &id);

    const std::string &getID() const;

    virtual void print() const = 0;
};

#endif // BASEINVENTORYITEM_H
