#ifndef _ARMOR_H
#define _ARMOR_H

#include "Item.h"

enum ArmorType
{
    CLOTHING = 1,
    LIGHT = 2,
    HEAVY = 3
};

class Armor : public Item
{
    private:
    int armorRating;
    ArmorType armorType;
    std::string armorTypeName;

    public:
    Armor();
    Armor(std::string name, float price, float weight, int armorRating ,ArmorType armorType);
    Armor(const Armor& armor);
    ~Armor();

    int getArmorRating() const;
    ArmorType getArmorType() const;
    std::string getArmorTypeName() const;

    void setArmorRating(int);
    void setArmorType(ArmorType);

    void print() const override;

};

std::string decideArmorTypeName(ArmorType);
void generateRandArmor(int);

#endif