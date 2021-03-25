#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "Entity/Player.h"
#include "Entity/Enemy.h"
#include "Item/Item.h"
#include "Item/Armor.h"
#include "Item/Weapon.h"

#include "Test/Test.h"

#ifdef __linux__
const char* clear = "clear";
#elif __WIN32__
const char* clear = "cls";
#endif

int main()
{

    Weapon sword("Iron Sword",125,7.50,10,MELEE);
    Armor armor("Steel Armor",375,22.5,38.75,HEAVY);
    Armor armor2("Leather Armor",100,15,20,LIGHT);

    Player player("James",100,10,sword,armor);

    

    return 0;
}