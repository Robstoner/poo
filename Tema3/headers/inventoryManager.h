#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H
#include <unordered_map>
#include "../headers/inventoryItemFlyweightFactory.h"

template <typename T>
class InventoryManager
{
private:
    std::unordered_map<std::string, T> items;
    InventoryItemFlyweightFactory flyweightFactory;

public:
    void addItem(const std::string &id, const std::string &type, const std::string &size, const std::string &color, int quantity)
    {
        const InventoryItemFlyweight &flyweight = flyweightFactory.getFlyweight(type, size, color);
        items[id] = T(id, flyweight, quantity);
    }

    void removeItem(const std::string &id)
    {
        items.erase(id);
    }

    T &getItem(const std::string &id)
    {
        return items[id];
    }

    template <typename U>
    U cloneItem(const std::string &id)
    {
        return items[id].template clone<U>();
    }

    // sablon de proiectare Iterator
    class Iterator
    {
    private:
        typename std::unordered_map<std::string, T>::iterator it;

    public:
        Iterator(typename std::unordered_map<std::string, T>::iterator it) : it(it) {}

        bool operator!=(const Iterator &other)
        {
            return it != other.it;
        }

        Iterator &operator++()
        {
            ++it;
            return *this;
        }

        T &operator*()
        {
            return it->second;
        }
    };

    Iterator begin()
    {
        return Iterator(items.begin());
    }

    Iterator end()
    {
        return Iterator(items.end());
    }
};

#endif // INVENTORYMANAGER_H
