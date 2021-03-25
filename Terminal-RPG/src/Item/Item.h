#ifndef _ITEM_H
#define _ITEM_H

#include <iostream>
#include <string>

class Item
{
    private:
    std::string name;
    float price;
    float weight;

    public:
    Item();
    Item(std::string, float, float);
    Item(const Item&);
    virtual ~Item();

    std::string getName() const;
    float getPrice() const;
    float getWeight() const;

    void setName(std::string);
    void setPrice(float);
    void setWeight(float);

    virtual void print() const;
};

void generateRandItems(int count);

#endif