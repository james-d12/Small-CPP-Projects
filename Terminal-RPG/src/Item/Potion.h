#ifndef _POTION_H
#define _POTION_H

#include "Item.h"

class Potion : public Item
{
    private:
    float restore;

    public:
    Potion();
    Potion(std::string name, float price, float weight, float restore);
    ~Potion();


    float getRestore();
};


#endif