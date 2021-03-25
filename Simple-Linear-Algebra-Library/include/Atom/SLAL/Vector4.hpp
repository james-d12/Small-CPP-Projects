/*---------------------------------------------------------------------
    'Vector4.hpp' is part of Atom.SLAL, and is a generic vector of 4
    dimensions implementation.
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

#ifndef _VECTOR4_HPP
#define _VECTOR4_HPP

#include "BaseVector.hpp"

namespace atom{
namespace slal{

template<typename T>
struct Vector4 : public Base_Vector<T>
{
    T x;
    T y;
    T z;
    T w;

    //default construct.r
    Vector4() : x(0), y(0), z(0), w(0) {}
    //custom constructor - x,y,z,w values specified.
    Vector4(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}
    //copy constructor
    Vector4(const Vector4<T>& vec4) : x(vec4.x), y(vec4.y), z(vec4.z), w(vec4.w) {}
    //destructor.
    ~Vector4() {}

    //set x,y,z,w to values of 0.
    virtual void fillZero() override { x = 0; y = 0; z = 0; w = 0; }
    //normalise vector4 - all axis / magnitude.
    virtual void normalise() override
    {
        T mag = magnitude();
        x = x/mag;
        y = y/mag;
        z = z/mag;
        w = w/mag;
    }
    //return magnitude of vector4 - sqrt of x*x + y*y + z*z + w*w.
    virtual T magnitude() const override 
    { return std::sqrt((x * x), (y * y), (z * z), (w * w)); }
    
      //overload + operator - add passed vector4 to current vector4 and return a new vector4.
    Vector4<T> operator+ (const Vector4<T>& vec4) 
    { return Vector4<T>((x + vec4.x), (y + vec4.y), (z + vec4.z), (w + vec4.w)); }
    //overload - operator - subtract passed vector4 to current vector4 and return a new vector4.
    Vector4<T> operator- (const Vector4<T>& vec4) 
    { return Vector4<T>((x - vec4.x), (y - vec4.y), (z - vec4.z), (w - vec4.w)); }
    //overload * operator - multiply passed vector4 to current vector4 and return a new vector4.
    Vector4<T> operator* (const Vector4<T>& vec4) 
    { return Vector4<T>((x * vec4.x), (y * vec4.y), (z * vec4.z), (w * vec4.w)); }
    //overload * operator - multiple current vector4 by a passed scalar values
    Vector4<T> operator* (const T scalar) 
    { return Vector4<T>((x * scalar), (y * scalar), (z * scalar), (w * scalar)); }
    //overload / operator - divide passed vector4 to current vector4 and return a new vector4.
    Vector4<T> operator/ (const Vector4<T>& vec4) 
    { return Vector4<T>((x / vec4.x), (y / vec4.y), (z / vec4.z), (w / vec4.w)); }

    //overload += operator - add passed vector4 to current vector4 and assign values.
    Vector4<T> operator+=(const Vector4<T>& vec4) 
    { x += vec4.x; y += vec4.y; z += vec4.z; w += vec4.w; return *this; }
    //overload -= operator - subtract passed vector4 to current vector4 and assign values.
    Vector4<T> operator-=(const Vector4<T>& vec4) 
    { x -= vec4.x; y -= vec4.y; z -= vec4.z; w -= vec4.w; return *this; }
    //overload *= operator - multiply passed vector4 to current vector4 and assign values.
    Vector4<T> operator*=(const Vector4<T>& vec4) 
    { x *= vec4.x; y *= vec4.y; z *= vec4.z; w *= vec4.w; return *this; }
    //overload *= operator - multiply current vector4 by passed scalar.
    Vector4<T> operator*=(const T scalar) 
    { x *= scalar; y *= scalar; z *= scalar; w *= scalar; return *this; }
    //overload /= operator - divide passed vector4 to current vector4 and assign values.
    Vector4<T> operator/=(const Vector4<T>& vec4)
     { x /= vec4.x; y /= vec4.y; z /= vec4.z; w /= vec4.w; return *this; }

    //overload == operator - compare if x and y equals passed vector4's x and y.
    bool operator==(const Vector4<T>& vec4) 
    { return (x == vec4.x && y == vec4.y && z == vec4.z && w == vec4.w) ? true : false; }
    //overload != operator - compare if x and y doesnt equal passed vector4's x and y.
    bool operator!=(const Vector4<T>& vec4) 
    { return (!operator==(vec4)); }
    //overload >= operator - compare if x and y is greater than or equal to passed vector4's x and y.
    bool operator>=(const Vector4<T>& vec4) 
    { return (x >= vec4.x && y >= vec4.y && z >= vec4.z && w >= vec4.w) ? true : false; }
    //overload >= operator - compare if x and y is less than or equal to passed vector4's x and y.
    bool operator<=(const Vector4<T>& vec4) 
    { return (x <= vec4.x && y <= vec4.y && z <= vec4.z && w <= vec4.w) ? true : false; }
    //overload >= operator - compare if x and y is greater  to passed vector4's x and y.
    bool operator> (const Vector4<T>& vec4) 
    { return (x > vec4.x && y > vec4.y && z > vec4.z && w > vec4.w) ? true : false; }
    //overload >= operator - compare if x and y is less than or equal to passed vector4's x and y.
    bool operator< (const Vector4<T>& vec4) 
    { return (x < vec4.x && y < vec4.y && z < vec4.z && w < vec4.w) ? true : false; }

    //assignment operator
    Vector4<T> operator= (const Vector4<T>& vec4) 
    { x = vec4.x; y = vec4.y; z = vec4.z; w = vec4.w; return *this; }

};

}
}

#endif