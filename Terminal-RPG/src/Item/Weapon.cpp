#include "Weapon.h"

std::string decideWeaponTypeName(WeaponType WeaponType)
{
    switch (WeaponType)
        {
            case MELEE:
                return "Melee";
            case MAGIC:
                return "Magic";
            case RANGED:
                return "Ranged";
            default:
                break;
        }
    return "";
}
Weapon::Weapon()
: Item()
{
    this->damage = 0.0f;
    this->weaponType = MELEE;
    this->weaponTypeName = decideWeaponTypeName(MELEE);
}
Weapon::Weapon(std::string name, float price, float weight, float damage, enum WeaponType weaponType)
: Item(name,price,weight)
{
    this->damage = damage;
    this->weaponType = weaponType;
    this->weaponTypeName = decideWeaponTypeName(weaponType);
}

Weapon::Weapon(const Weapon& weapon)
: Item(weapon.getName(), weapon.getPrice(), weapon.getWeight())
{
    this->damage = weapon.getDamage();
    this->weaponType = weapon.getWeaponType();
    this->weaponTypeName = decideWeaponTypeName(this->weaponType);
}

Weapon::~Weapon(){}

float Weapon::getDamage() const{ return damage;}
enum WeaponType Weapon::getWeaponType() const { return weaponType;}
std::string Weapon::getWeaponTypeName() const { return weaponTypeName;}

void Weapon::setDamage(float damage) { this->damage = damage;}
void Weapon::setWeaponType(enum WeaponType weaponType)
{
    this->weaponType = weaponType;
    this->weaponTypeName = decideWeaponTypeName(this->weaponType);
}

void Weapon::print() const 
{
    Item::print();
    std::cout << "Damage: " << damage << std::endl;
    std::cout << "Weapon Type: " << weaponTypeName << std::endl;
    std::cout << "----------------------------------" << std::endl;
}