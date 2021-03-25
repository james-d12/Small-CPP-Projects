/*---------------------------------------------------------------------
    BaseVector.hpp is part of Atom.SLAL, and provides an abstract vector
    struct inherited by all other vector implementations.
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

#ifndef _BASEVECTOR_HPP
#define _BASEVECTOR_HPP

#include <math.h>
#include <type_traits>
#include "../../../external/Atom/Core/Core.h"

namespace atom{
namespace slal{

template<typename T,
typename = std::enable_if_t<std::is_arithmetic<T>::value>>
struct Base_Vector
{
    virtual ~Base_Vector() {}
    virtual void fillZero() = 0;
    virtual void normalise() = 0;
    virtual T magnitude() const = 0;
};

}
}

#endif