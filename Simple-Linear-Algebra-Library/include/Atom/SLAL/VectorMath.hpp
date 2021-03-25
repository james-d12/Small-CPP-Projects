/*---------------------------------------------------------------------
    'VectorMath.hpp' is part of Atom.SLAL, and is used for generic vector
    math operations.
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

#ifndef _VECTORMATH_HPP
#define _VECTORMATH_HPP

#include <iostream>
#include <initializer_list>
#include "../../../external/Atom/Core/Core.h"

#include "Vector.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"

namespace atom{
namespace slal{

/*
template<typename Vec, typename T,
typename = std::enable_if_t<std::is_base_of<Base_Vector<T>,Vec>::value>>
float dotProduct(const Vec vec1, const Vec vec2, float radians)
{
    float resultMag = vec1.magnitude() * vec2.magnitude();
    return (resultMag * std::cos(radians));
}
*/

//calculate dotProduct of any number of vector2s.
template<typename T> 
T dotProduct(const std::initializer_list<Vector2<T>>& iList)
{   
    T xRes = 1;
    T yRes = 1;
    for(Vector2<T> vec2 : iList)
    {
        xRes *= vec2.x;
        yRes *= vec2.y;
    }

    return (xRes + yRes);
}

//calculate dotProduct of any number of vector3s.
template<typename T> 
T dotProduct(const std::initializer_list<Vector3<T>>& iList)
{
    T xRes = 1;
    T yRes = 1;
    T zRes = 1;
    for(Vector3<T> vec3 : iList)
    {
        xRes *= vec3.x;
        yRes *= vec3.y;
        zRes *= vec3.z;
    }
    return (xRes + yRes + zRes);
}

//calculate dotProduct of any number of vector4s.
template<typename T> 
T dotProduct(const std::initializer_list<Vector4<T>>& iList)
{
    T xRes = 1;
    T yRes = 1;
    T zRes = 1;
    T wRes = 1;
    for(Vector4<T> vec4 : iList)
    {
        xRes *= vec4.x;
        yRes *= vec4.y;
        zRes *= vec4.z;
        wRes *= vec4.w;
    }
    return (xRes + yRes + zRes);
}

//calculate angle between 2 vector2s.
template<typename T>
T angle(const Vector2<T>& fVec2, const Vector2<T>& sVec2)
{
    T dotProd = dotProduct({fVec2,sVec2});
    T mag = fVec2.magnitude() * sVec2.magnitude();

    std::cout << "Dot Prod: " << dotProd << "\n";
    std::cout << "Mag: " << mag << "\n";

    return (dotProd / mag);
}

}
}


#endif