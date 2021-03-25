/*---------------------------------------------------------------------
    'Vector3.hpp' is part of Atom.SLAL, and is a generic vector of 3
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

#ifndef _VECTOR3_HPP
#define _VECTOR3_HPP

#include "BaseVector.hpp"

namespace atom{
namespace slal{

template<typename T>
struct Vector3 : public Base_Vector<T>
{
    T x;
    T y;
    T z;

    //default constructor.
    Vector3() : x(0), y(0), z(0) {}
    //custom constructor - values specified.
    Vector3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
    //copy constructor.
    Vector3(const Vector3<T>& vec3) : x(vec3.x), y(vec3.y), z(vec3.z) {}
    //destructor.
    ~Vector3() {}

    //set x,y and z axis to 0.
    virtual void fillZero() override { x = 0; y = 0; z = 0; }
    //normalise the vector3 - each axis / magnitude.
    virtual void normalise() override 
    {
        T mag = magnitude();
        x = x/mag;
        y = y/mag;
        z = z/mag;
    }
    //return magnitude of vector3 - sqrt(x*x+y*y+z*z)
    virtual T magnitude() const override { return (std::sqrt((x*y) + (y*y) + (z*z))); }

     //overload + operator - add passed vector3 to current vector3 and return a new vector3.
    Vector3<T> operator+ (const Vector3<T>& vec3) { return Vector3<T>((x + vec3.x), (y + vec3.y), (z + vec3.z)); }
    //overload - operator - subtract passed vector3 to current vector3 and return a new vector3.
    Vector3<T> operator- (const Vector3<T>& vec3) { return Vector3<T>((x - vec3.x), (y - vec3.y), (z - vec3.z)); }
    //overload * operator - multiply passed vector3 to current vector3 and return a new vector3.
    Vector3<T> operator* (const Vector3<T>& vec3) { return Vector3<T>((x * vec3.x), (y * vec3.y), (z * vec3.z)); }
    //overload * operator - multiple current vector3 by a passed scalar values
    Vector3<T> operator* (const T scalar) { return Vector3<T>((x * scalar), (y * scalar), (z * scalar)); }
    //overload / operator - divide passed vector3 to current vector3 and return a new vector3.
    Vector3<T> operator/ (const Vector3<T>& vec3) { return Vector3<T>((x / vec3.x), (y / vec3.y), (z / vec3.z)); }

    //overload += operator - add passed vector3 to current vector3 and assign values.
    Vector3<T> operator+=(const Vector3<T>& vec3) { x += vec3.x; y += vec3.y; z += vec3.z; return *this; }
    //overload -= operator - subtract passed vector3 to current vector3 and assign values.
    Vector3<T> operator-=(const Vector3<T>& vec3) { x -= vec3.x; y -= vec3.y; z -= vec3.z; return *this; }
    //overload *= operator - multiply passed vector3 to current vector3 and assign values.
    Vector3<T> operator*=(const Vector3<T>& vec3) { x *= vec3.x; y *= vec3.y; z *= vec3.z; return *this; }
    //overload *= operator - multiply current vector3 by passed scalar.
    Vector3<T> operator*=(const T scalar) { x *= scalar; y *= scalar; z *= scalar; return *this; }
    //overload /= operator - divide passed vector3 to current vector3 and assign values.
    Vector3<T> operator/=(const Vector3<T>& vec3) { x /= vec3.x; y /= vec3.y; z /= vec3.z; return *this; }

    //overload == operator - compare if x and y equals passed vector3's x and y.
    bool operator==(const Vector3<T>& vec3) { return (x == vec3.x && y == vec3.y && z == vec3.z) ? true : false; }
    //overload != operator - compare if x and y doesnt equal passed vector3's x and y.
    bool operator!=(const Vector3<T>& vec3) { return (!operator==(vec3)); }
    //overload >= operator - compare if x and y is greater than or equal to passed vector3's x and y.
    bool operator>=(const Vector3<T>& vec3) { return (x >= vec3.x && y >= vec3.y && z >= vec3.z) ? true : false; }
    //overload >= operator - compare if x and y is less than or equal to passed vector3's x and y.
    bool operator<=(const Vector3<T>& vec3) { return (x <= vec3.x && y <= vec3.y && z <= vec3.z) ? true : false; }
    //overload >= operator - compare if x and y is greater  to passed vector3's x and y.
    bool operator> (const Vector3<T>& vec3) { return (x > vec3.x && y > vec3.y && z > vec3.z) ? true : false; }
    //overload >= operator - compare if x and y is less than or equal to passed vector3's x and y.
    bool operator< (const Vector3<T>& vec3) { return (x < vec3.x && y < vec3.y && z < vec3.z) ? true : false; }

    //assignment operator
    Vector3<T> operator= (const Vector3<T>& vec3) { x = vec3.x; y = vec3.y; z = vec3.z; return *this; }
    

};

}
}

#endif