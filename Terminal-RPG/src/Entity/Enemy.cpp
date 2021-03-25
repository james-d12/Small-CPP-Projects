#include "Enemy.h"

Enemy::Enemy()
{
    this->name = "";
    this->health = 0.0f;
    this->experienceDrop = 0.0f;
    this->level = 0;
}

Enemy::Enemy(std::string name, float health, float experienceDrop, int level, 
Weapon& weapon, Armor& armor)
{
    this->name = name;
    this->health = health;
    this->experienceDrop = experienceDrop;
    this->level = level;
    this->equippedWeapon = weapon;
    this->equippedArmor = armor;
}

Enemy::~Enemy(){}

float Enemy::getExperienceDrop() const { return experienceDrop;}
Weapon Enemy::getWeapon() const { return equippedWeapon;}
Armor Enemy::getArmor() const { return equippedArmor;}

void Enemy::addItem(Item& item)
{
    inventory.add(item);
}
void Enemy::takeDamage(float damage)
{
    health -= damage;
}
void Enemy::print() const
{
    std::cout << "----------ENEMY------------" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Experience Drop: " << experienceDrop << std::endl;
    std::cout << "Weapon: " << equippedWeapon.getName() << std::endl;
    std::cout << "Armor: " << equippedArmor.getName() << std::endl;
    std::cout << "Damage: " << equippedWeapon.getDamage() << std::endl;
    std::cout << "---------------------------" << std::endl;
}
