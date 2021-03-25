#ifndef _SAVE_H
#define _SAVE_H

#include <iostream>
#include <fstream>

#include "../Entity/Player.h"

void savePlayer(Player* player)
{
    std::string filePath;
    std::ofstream file;
    file.open("savedata.txt",std::ios::in);

    file << player->getName() << "\n";
    file << player->getHealth() << "\n";
    file << player->getExperience() << "\n";
    file << player->getLevel() << "\n";
    file << player->getHealth() << "\n";
    file << player->getHealth() << "\n";
    file << player->getHealth() << "\n";
    file << player->getHealth() << "\n";
    file << player->getHealth() << "\n";
}

#endif