/*---------------------------------------------------------------------
    'Vector2.hpp' is part of Atom.SLAL, and is a generic vector of 2
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

#ifndef _VECTOR2_HPP
#define _VECTOR2_HPP

#include "BaseVector.hpp"

namespace atom{
namespace slal{

template<typename T>
struct Vector2 : public Base_Vector<T>
{
    T x;
    T y;

    //default constructor
    Vector2() : x(0), y(0) {}
    //custom constructor - x / y values specified.
    explicit Vector2(T _x, T _y) : x(_x), y(_y) {}
    //copy constructor.
    Vector2(const Vector2<T>& vec2) : x(vec2.x), y(vec2.y) {}
    //destructor.
    ~Vector2() {}

    //set both x and y to 0.
    virtual void fillZero() override { x = 0; y = 0; }
    //normalise the vector - each axis / magnitude.
    virtual void normalise() override { float mag = magnitude(); x = (x / mag); y = (y / mag); }
    //return sqrt of x*x + y*y.
    virtual T magnitude() const override { return sqrt((x * x) + (y * y)); }

    //overload + operator - add passed vector2 to current vector2 and return a new vector2.
    Vector2<T> operator+ (const Vector2<T>& vec2) { return Vector2<T>((x + vec2.x), (y + vec2.y)); }
    //overload - operator - subtract passed vector2 to current vector2 and return a new vector2.
    Vector2<T> operator- (const Vector2<T>& vec2) { return Vector2<T>((x - vec2.x), (y - vec2.y)); }
    //overload * operator - multiply passed vector2 to current vector2 and return a new vector2.
    Vector2<T> operator* (const Vector2<T>& vec2) { return Vector2<T>((x * vec2.x), (y * vec2.y)); }
    //overload * operator - multiple current vector2 by a passed scalar values
    Vector2<T> operator* (const T scalar) { return Vector2<T>((x * scalar), (y * scalar)); }
    //overload / operator - divide passed vector2 to current vector2 and return a new vector2.
    Vector2<T> operator/ (const Vector2<T>& vec2) { return Vector2<T>((x / vec2.x), (y / vec2.y)); }

    //overload += operator - add passed vector2 to current vector2 and assign values.
    Vector2<T> operator+=(const Vector2<T>& vec2) { x += vec2.x; y += vec2.y; return *this; }
    //overload -= operator - subtract passed vector2 to current vector2 and assign values.
    Vector2<T> operator-=(const Vector2<T>& vec2) { x -= vec2.x; y -= vec2.y; return *this; }
    //overload *= operator - multiply passed vector2 to current vector2 and assign values.
    Vector2<T> operator*=(const Vector2<T>& vec2) { x *= vec2.x; y *= vec2.y; return *this; }
    //overload *= operator - multiply current vector2 by passed scalar.
    Vector2<T> operator*=(const T scalar) { x *= scalar; y *= scalar; return *this; }
    //overload /= operator - divide passed vector2 to current vector2 and assign values.
    Vector2<T> operator/=(const Vector2<T>& vec2) { x /= vec2.x; y /= vec2.y; return *this; }

    //overload == operator - compare if x and y equals passed vector2's x and y.
    bool operator==(const Vector2<T>& vec2) { return (x == vec2.x && y == vec2.y) ? true : false; }
    //overload != operator - compare if x and y doesnt equal passed vector2's x and y.
    bool operator!=(const Vector2<T>& vec2) { return (!operator==(vec2)); }
    //overload >= operator - compare if x and y is greater than or equal to passed vector2's x and y.
    bool operator>=(const Vector2<T>& vec2) { return (x >= vec2.x && y >= vec2.y) ? true : false; }
    //overload >= operator - compare if x and y is less than or equal to passed vector2's x and y.
    bool operator<=(const Vector2<T>& vec2) { return (x <= vec2.x && y <= vec2.y) ? true : false; }
    //overload >= operator - compare if x and y is greater  to passed vector2's x and y.
    bool operator> (const Vector2<T>& vec2) { return (x > vec2.x && y > vec2.y) ? true : false; }
    //overload >= operator - compare if x and y is less than or equal to passed vector2's x and y.
    bool operator< (const Vector2<T>& vec2) { return (x < vec2.x && y < vec2.y) ? true : false; }
    
    //assignment operator
    Vector2<T> operator= (const Vector2<T>& vec2) { x = vec2.x; y = vec2.y; return *this; }
    
};

}
}

#endif