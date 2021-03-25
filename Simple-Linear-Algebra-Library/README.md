# Atom.SLAL
## Atom
Atom is my first large c++ project aimed for mostly learning and personal use purposes, but to also publish my work for critic and review by others. It aims to provide both generic and type defined implementations for a wide range of features such as math, graphics, data structures, and more. It takes heavy inspiration in the 'boost' library, but does not and will not be able to compete with it at any level, reiterating my point on Atom being a large personal project. 

Atom's structure aims to have each component (e.g. Atom.SLAL) to be as independent as possible, and because of this, some code may be 'copied' or already seen in other libraries, however this is only when necessary, in order to ensure that the user can select just one aspect, without having to deal with dependency issues.

## Atom.SLAL
Atom.SLAL is the 'Simple Linear Algebra Library' for Atom. It aims to provide a broad use of simple linear algebra opertations and structures such as vectors, matrices, linear equations and functions, and more. It aims to provide both generic and type defined implementations of said features for increased user customisation.

## Installation

### Visual Studio Code

**Header only - Generic**:
1. Firstly, either download or clone the repository.
2. Next, extract the repository to a location where it will be used - such as a project you are developing.
3. Open up your project and include these files from the specified location. Code could look like this:
```cpp
#include "{extractedlocation}/include/Atom/SLAL/file"
// rest of code
```
4. You are done, as all files are .hpp or .h, no compilation is required, only linking.

**CPP and Header files - Compilation**:
1. Firstly, either download or clone the repository.
2. Next, extract the repository to a location where it will be used - such as a project you are developing.
3. Open up your project and include these files from a specified location. Code could look like this
```cpp
#include "{extractedlocation}/include/Atom/SLAL/file"
//rest of code
```
4. Now, a few options for compilation are available.
  - Use a c++ compiler such as GNU, G++, MINGW64, CLANG, etc, and include the directories as input files.
  - Run the 'build.sh' script (Linux)
  - (FUTURE METHODS SOON!)

## Usage

```cpp
#include <iostream>
// include the source file - 'Vector2.hpp'
#include "{extractedLocation}/include/Atom/SLAL/Vector2.hpp

template<typename T>
void printVec2(const atom::slal::Vector2<T> vec2){
  std::cout << "Vector2 x: " << vec2.x << "\n;
  std::cout << "Vector2 y: " << vec2.y << "\n; 
}


int main()
{
  //create a vector 2 with values 5 and 4 (x,y)
  atom::slal::Vector2<int> f_vec2Int(5,4);
  //create another vector2 int with values 10 and 15 (x,y)
  atom::slal::Vector2<int> s_vec2Int(10,15);
  
  //add vectors and store result
  atom::slal::Vector2<int> result = f_vec2Int + s_vec2Int;
  
  //output the vector2
  printVec2(result);
  return 0;
}

```
