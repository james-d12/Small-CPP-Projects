#ifndef _WEAPON_HPP
#define _WEAPON_HPP

#include "Item.h"

enum WeaponType
{
    MELEE = 1,
    MAGIC = 2,
    RANGED = 3
};


class Weapon : public Item
{
    private:
    float damage;
    WeaponType weaponType;
    std::string weaponTypeName;

    public:
    Weapon();
    Weapon(std::string name,float price,float weight,float damage, WeaponType weaponType);
    Weapon(const Weapon&);
    ~Weapon();
    
    float getDamage() const;
    WeaponType getWeaponType() const;
    std::string getWeaponTypeName() const;

    void setDamage(float);
    void setWeaponType(WeaponType);

    void print() const override;

};

std::string decideWeaponTypeName(WeaponType);

#endif