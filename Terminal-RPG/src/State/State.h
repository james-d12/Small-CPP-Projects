#ifndef _STATE_H
#define _STATE_H

#include "../Entity/Player.h"

class State
{
    protected:
    Player player;

    public:
    

    
    virtual State* update() = 0;
};  

#endif