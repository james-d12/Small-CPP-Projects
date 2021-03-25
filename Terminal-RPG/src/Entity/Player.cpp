#include "Player.h"

Player::Player(std::string name, float health, unsigned int inventSize,
Weapon& weapon, Armor& armor)
: Entity(name,health,inventSize)
{
    damageMult = 1.0f;
    experience = 0.0f;
    experienceNext = 25.00f;
    level = 0;
    equippedArmor = armor;
    equippedWeapon = weapon;
    inventory.add(weapon);
    inventory.add(armor);
}

Player::~Player(){}

float Player::getExperience() const { return experience;}
float Player::getExperienceNext() const { return experienceNext;}
int Player::getArmorRating() const { return equippedArmor.getArmorRating();}
float Player::getDamage() const { return (equippedWeapon.getDamage() * damageMult);}
Weapon Player::getWeapon() const { return equippedWeapon;}
Armor Player::getArmor() const { return equippedArmor;}

void Player::addExperience(float experience) 
{
    if(level < 100)
    {
        this->experience += abs(experience);
    }

}
void Player::removeExperience(float experience)
{
    if(this->experience >= experience)
    {
        this->experience -= abs(experience);
    }
}
void Player::addItem(Item& item)
{
    if(inventory.getWeight() + item.getWeight() > carryingCapacity)
    {
        std::cout << "Item is too heavy to add to inventory.\n";
    }
    else
    {
        inventory.add(item);
    }
}
void Player::removeItem(Item& item)
{
    if(inventory.isInInventory(item))
    {
        
    }
}
void Player::equipWeapon(Weapon& weapon) 
{
     this->equippedWeapon = weapon;
}

void Player::equipArmor(Armor& armor) 
{
    if(inventory.isInInventory(armor))
    {
        this->equippedArmor = armor;
    } 
    else 
    {
        this->addItem(armor);
        this->equippedArmor = armor;
    }
    
}

void Player::takeDamage(float damage)
{
    float resultDamage = damage - (getArmorRating() / 2);
    health -= resultDamage;
}

void Player::levelUp()
{
    while(experience >= experienceNext && level < maxLevel)
    {
        health = floor(health * 1.05);
        carryingCapacity = floor(carryingCapacity * 1.025);
        damageMult += 0.10;
        experience -= experienceNext;
        experienceNext = ceil(experienceNext * 1.10);
        level += 1;
    }
    if(level >= maxLevel)
    {
        experience = experienceNext;
    }
}
void Player::print() const 
{
    std::cout << "--------------PLAYER---------------" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Carrying Capacity: " << carryingCapacity << std::endl;
    std::cout << "Inventory Weight: " << inventory.getWeight() << std::endl;
    std::cout << "Experience: " << experience << std::endl;
    std::cout << "Experience Next: " << experienceNext << std::endl;
    std::cout << "Equipped Weapon: " << getWeapon().getName() << std::endl;
    std::cout << "Equipped Armor: " << getArmor().getName() << std::endl;
    std::cout << "Weapon Damage: " << getDamage() << std::endl;
    std::cout << "Armor Rating: " << getArmorRating() << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

