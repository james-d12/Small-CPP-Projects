#include "Armor.h"

std::string decideArmorTypeName(ArmorType armorType)
{
    switch (armorType)
    {
        case CLOTHING:
            return "Clothing";
        case LIGHT:
            return "Light";
        case HEAVY:
            return "Heavy";
        default:
            break;
    }
    return "";
}

Armor::Armor()
: Item()
{
    this->armorRating = 0;
    this->armorType = CLOTHING;
    this->armorTypeName = decideArmorTypeName(CLOTHING);
}
Armor::Armor(std::string name, float price , float weight, int armorRating, enum ArmorType armorType)
: Item(name,price,weight)
{
    this->armorRating = armorRating;
    this->armorType = armorType;
    this->armorTypeName = decideArmorTypeName(armorType);
}
Armor::Armor(const Armor& armor)
: Item(armor.getName(), armor.getPrice(), armor.getWeight())
{   
    this->armorRating = armor.getArmorRating();
    this->armorType = armor.getArmorType();
    this->armorTypeName = armor.getArmorTypeName();
}

Armor::~Armor(){}

int Armor::getArmorRating() const{ return armorRating;}
ArmorType Armor::getArmorType() const { return armorType;}
std::string Armor::getArmorTypeName() const { return armorTypeName;}

void Armor::setArmorRating(int armorRating){ this->armorRating = armorRating;}
void Armor::setArmorType(enum ArmorType armorType)
{
    this->armorType = armorType;
    this->armorTypeName = decideArmorTypeName(this->armorType);
}

void Armor::print() const
{
    Item::print();
    std::cout << "Armor Rating: " << armorRating << std::endl;
    std::cout << "Armor Type: " << armorTypeName << std::endl;
    std::cout << "----------------------------------" << std::endl;
}