/*---------------------------------------------------------------------
    'TestHelper.hpp' is part of Atom.SLAL and Atom.TEST, containing 
    helper methods used by other test files.
    Copyright (C) 2019  James Durban

    Atom.SLAL/Atom.TEST is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License,
    any later version.

    Atom.SLAL/Atom.TEST is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Atom.SLAL/Atom.TEST.  If not, see <https://www.gnu.org/licenses/>.

---------------------------------------------------------------------*/

#ifndef _TESTHELPER_HPP
#define _TESTHELPER_HPP

#include <ctime>
#include <cmath>
#include <cstdlib>
#include <random>
#include <limits>

namespace atom{
namespace test{

float randFloatMax() 
{ 
    float r = static_cast<float> (rand() / static_cast <float> (RAND_MAX/std::numeric_limits<float>::max()));
    return r;
}
float randFloatRange(float range=12500.765) 
{ 
    float r = static_cast<float> (rand() / static_cast <float> (RAND_MAX/range));
    return r;
}
int randIntMax() 
{ 
    int r = static_cast<int> (rand() / static_cast<int> (RAND_MAX/std::numeric_limits<int>::max())); 
    return r;
}
int randIntRange(int range=1000) 
{ 
    int r = static_cast<int> (rand() / static_cast<int> (RAND_MAX/range)); 
    return r;
}

template<typename T>
T generateRandomMax()
{
    if(typeid(T) == typeid(float))
    {
       return (randFloatMax());
    }
    else if(typeid(T) == typeid(int))
    {
        return (randIntMax());
    }

    return T();
}

template<typename T>
T generateRandomRange(T range)
{
    if(typeid(T) == typeid(float))
    {
       return (randFloatRange(range));
    }
    else if(typeid(T) == typeid(int))
    {
        return (randIntRange(range));
    }

    return T();
}

}
}

#endif