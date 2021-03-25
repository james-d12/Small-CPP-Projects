#include "Inventory.h"

Inventory::Inventory()
{
    content = nullptr;
    capacity = 0;
    size = 0;
    weight = 0.0f;
}
Inventory::Inventory(unsigned int capacity)
{
    createInventory(capacity);
}
Inventory::Inventory(const Inventory& inventory)
{
    copyInventory(inventory);
}
Inventory::~Inventory()
{
    delete [] content;
}

float Inventory::getWeight() const { return weight;}
unsigned int Inventory::getSize() const { return size;}
unsigned int Inventory::getCapacity() const { return capacity;}

bool Inventory::isInInventory(Item& item)
{
    for(unsigned int i = 0; i < size; i++)
    {
        if(&content[i] == &item)
        {
            return true;
        }
    }
    return false;
}

void Inventory::create(unsigned int capacity)
{
    createInventory(capacity);
}
void Inventory::add(Item& item)
{
    if(isFull())
    {
        std::cout << "Inventory is full!\n";
    }
    else
    {
        content[size] = item;
        size += 1;
        weight += item.getWeight();
    }
}
void Inventory::remove(Item& item)
{
    for(unsigned int i = 0; i < size; i++)
    {
        if(&content[i] == &item)
        {
            content[i].~Item();
        }
    }
}
void Inventory::remove()
{
    if(isEmpty())
    {
        std::cout << "Inventory is empty!\n";
    }
    else
    {
        weight -= content[size].getWeight();
        size -= 1;
    }
}
void Inventory::print() const
{
    std::cout << "|--------------------INVENTORY-------------------------|" << std::endl;
    for(unsigned int i = 0; i < size; i++)
    {
        content[i].print();
    }
    std::cout << "|------------------------------------------------------|" << std::endl;
}

Item& Inventory::operator[](unsigned int index) const
{
    if(index > capacity)
    {
        std::cerr << "Index out of range, exiting.\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        return content[index];
    }
}
