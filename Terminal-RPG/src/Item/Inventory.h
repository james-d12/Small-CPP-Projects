#ifndef _INVENTORY_H
#define _INVENTORY_H

#include "../Item/Item.h"

class Inventory
{   
    private:
    Item* content;
    float weight;
    unsigned int size;
    unsigned int capacity;

    void createInventory(unsigned int capacity)
    {
        content = new Item[capacity];
        this->capacity = capacity;
        this->size = 0;
        this->weight = 0.0f;
    }
    void copyInventory(const Inventory& inventory)
    {
        content = new Item[inventory.getCapacity()];
        size = inventory.getSize();
        for(unsigned int i = 0; i < inventory.getSize(); i++)
        {
            content[i] = inventory[i];
        }
    }

    bool isFull() const { return (size >= capacity) ? true : false;}
    bool isEmpty() const { return (size <= 0) ? true : false;}

    public:
    Inventory();
    Inventory(unsigned int capacity);
    Inventory(const Inventory& inventory);
    ~Inventory();

    float getWeight() const;
    unsigned int getSize() const;
    unsigned int getCapacity() const;

    bool isInInventory(Item& item);
    void create(unsigned int capacity);
    void add(Item& item);
    void remove(Item& item);
    void remove();
    void print() const;

    //operator overload
    Item& operator[](unsigned int index) const;
};

#endif