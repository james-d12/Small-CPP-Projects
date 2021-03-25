/*---------------------------------------------------------------------
    'Vector.hpp' is part of Atom.SLAL, and provides a generic vector with
    specified dimensions and type.
    Copyright (C) 2019  James Durban

    Atom.SLAL is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License,
    any later version.

    Atom.SLAL is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Atom.SLAL.  If not, see <https://www.gnu.org/licenses/>.

---------------------------------------------------------------------*/

#ifndef _VECTOR_HPP
#define _VECTOR_HPP

#include "BaseVector.hpp"

namespace atom{
namespace slal{

template<typename T>
struct Vector : public Base_Vector<T>
{
    T* list;
    int dimensions;

    //default constructor.
    Vector() : dimensions(0)
    {
        list = nullptr;
    }
    //create vector with specified dimensions.
    Vector(int _dimensions) : dimensions(_dimensions)
    {
        list = new T[dimensions];
    }
    //copy constructor.
    Vector(const Vector<T>& vec) : dimensions(vec.dimensions) 
    {
        list = new T[dimensions];
        for(int i = 0; i < dimensions; i++)
        {
            list[i] = vec.list[i];
        }
    }
    ~Vector() { delete list; }
};

}
}

#endif