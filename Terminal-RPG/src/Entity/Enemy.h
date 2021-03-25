#ifndef _ENEMY_H
#define _ENEMY_H

#include "../Item/Weapon.h"
#include "../Item/Armor.h"

#include "Entity.h"

class Enemy : public Entity
{
    private:
    float damageMult;
    float experienceDrop;
    Weapon equippedWeapon;
    Armor equippedArmor;

    public:
    Enemy();
    Enemy(std::string,float,float,int,Weapon&,Armor&);
    Enemy(const Enemy&);
    ~Enemy();

    float getExperienceDrop() const;
    float getDamage() const;
    Weapon getWeapon() const;
    Armor getArmor() const;

    void addItem(Item& item) override;
    void takeDamage(float damage) override;
    void print() const override;
};

#endif