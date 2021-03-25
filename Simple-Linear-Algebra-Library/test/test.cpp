#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../include/Atom/SLAL/Vector2.hpp"
#include "../include/Atom/SLAL/Vector3.hpp"
#include "../include/Atom/SLAL/Vector4.hpp"
#include "../include/Atom/SLAL/VectorMath.hpp"
#include "../test/Atom/Test/TestVector2.hpp"

using namespace atom;

int main()
{
    slal::Vector2<char> firstVec(10,15);
    slal::Vector2<char> secVec(20,8);

    int dotProd = slal::dotProduct({firstVec,secVec});
    float angle = slal::angle(firstVec,secVec);

    std::cout << "Dot Prod: " << dotProd << "\n";
    std::cout << "Angle: " << angle << "\n";

    return 0;
}