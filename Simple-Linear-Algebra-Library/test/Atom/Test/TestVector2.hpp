/*---------------------------------------------------------------------
    'TestVector2.hpp' is part of Atom.SLAL and Atom.TEST, containing test 
    class for testing 2 dimensional vectors.
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

#ifndef _TESTVECTOR2_HPP
#define _TESTVECTOR2_HPP

#include "TestHelper.hpp"
#include "../../../include/Atom/SLAL/Vector.hpp"
#include "../../../include/Atom/SLAL/Vector2.hpp"
#include "../../../include/Atom/SLAL/Vector3.hpp"
#include "../../../include/Atom/SLAL/Vector4.hpp"

using namespace atom::slal;

namespace atom{
namespace test{

template<typename T,
typename = std::enable_if_t<std::is_arithmetic<T>::value>>
struct TestVector2
{
    bool testOperator01(int test, int iterations)
    {
        bool pass = true;
        
        T frandX;
        T frandY;
        T srandX;
        T srandY;

        for(int i = 0; i < iterations; i++)
        {
            frandX = generateRandomMax<T>();
            frandY = generateRandomMax<T>();
            srandX = generateRandomMax<T>();
            srandY = generateRandomMax<T>();

            Vector2<T> firstVec(frandX,frandY);
            Vector2<T> secondVec(srandX,srandY);

            T x;
            T y;
            Vector2<T> result;

            switch (test)
            {
            case 1:
                x = frandX + srandX;
                y = frandY + srandY;
                result = firstVec + secondVec;
                break;
            case 2:
                x = frandX - srandX;
                y = frandY - srandY;
                result = firstVec - secondVec;
                break;
            case 3:
                x = frandX * srandX;
                y = frandY * srandY;
                result = firstVec * secondVec;
                break;
            case 4:
                x = frandX / srandX;
                y = frandY / srandY;
                result = firstVec / secondVec;
                break;
            default:
                break;
            }

            if(result.x != x || result.y != y){
                pass = false;
                std::cout << "Iteration: " << i << " test failed!\n";
            }
            else
            {
                std::cout << "Iteration: " << i << " test passed!\n";
            }
        }
        return pass;
    }

    bool testOperator02(int test, int iterations)
    {
        bool pass = true;
        
        T frandX;
        T frandY;
        T srandX;
        T srandY;
        T x;
        T y;

        for(int i = 0; i < iterations; i++)
        {
            frandX = generateRandomMax<T>();
            frandY = generateRandomMax<T>();
            srandX = generateRandomMax<T>();
            srandY = generateRandomMax<T>();

            Vector2<T> firstVec(frandX,frandY);
            Vector2<T> result(srandX,srandY);

            switch (test)
            {
            case 1:
                x = frandX + srandX;
                y = frandY + srandY;
                result += firstVec;
                break;
            case 2:
                x = frandX - srandX;
                y = frandY - srandY;
                result -= firstVec;
                break;
            case 3:
                x = frandX * srandX;
                y = frandY * srandY;
                result *= firstVec;
                break;
            case 4:
                x = frandX / srandX;
                y = frandY / srandY;
                result /= firstVec;
                break;
            default:
                break;
            }

            if(result.x != x || result.y != y){
                pass = false;
                std::cout << "Iteration: " << i << " test failed!\n";
            }
        }
        return pass;
    }

    void runTests(int iterations)
    {
        bool add1 = testOperator01(1,iterations);
        bool sub1 = testOperator01(2,iterations);
        bool mult1 = testOperator01(3,iterations);
        bool div1 = testOperator01(4,iterations);

        bool firstStage = add1 && sub1 && mult1 && div1;

        bool add2 = testOperator02(1,iterations);
        bool sub2 = testOperator02(2,iterations);
        bool mult2 = testOperator02(3,iterations);
        bool div2 = testOperator02(4,iterations);

        bool secondStage = add2 && sub2 && mult2 && div2;

        if(firstStage && secondStage){
            std::cout << "Tests Passed!\n";
        }
        else
        {
            std::cout << "Tests Failed!\n";
        }

        std::cout << "--------------------------------------------------------------\n";

    }
};

}
}


#endif