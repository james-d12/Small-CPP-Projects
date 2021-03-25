#include "Item.h"


Item::Item()
{
    this->name = "";
    this->price = 0.0f;
    this->weight = 0.0f;
}
Item::Item(std::string name, float price, float weight)
{
    this->name = name;
    this->price = price;
    this->weight = weight;
}
Item::Item(const Item& item)
{
    this->name = item.getName();
    this->price = item.getPrice();
    this->weight = item.getWeight();
}
Item::~Item(){}

std::string Item::getName() const { return name;}
float Item::getPrice() const { return price;}
float Item::getWeight() const { return weight;}

void Item::setName(std::string name){ this->name = name;}
void Item::setPrice(float price){ this->price = price;}
void Item::setWeight(float weight) { this->weight = weight;}

void Item::print() const
{
    std::cout << "----------------ITEM---------------" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Weight: " << weight << std::endl;
}
