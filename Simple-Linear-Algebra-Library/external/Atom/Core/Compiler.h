/*---------------------------------------------------------------------
    'Compiler.h' is part of Atom.Core, and defines macros for determining
    the current installed/used C++ Compiler.
    Copyright (C) 2019  James Durban

    Atom.Core is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License,
    any later version.

    Atom.Core is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Atom.Core.  If not, see <https://www.gnu.org/licenses/>.

---------------------------------------------------------------------*/

#ifndef _COMPILER_H
#define _COMPILER_H

//Define compiler
#define ATOM_PREDEF_COMPILER

#if defined(__GNUC__)
    #define ATOM_PREDEF_COMPILER_GNUC
#elif defined(__MINGW32__)
    #define ATOM_PREDEF_COMPILER_MINGW32
#elif defined(__MINGW64__)
    #define ATOM_PREDEF_COMPILER_MINGW64
#elif defined(__clang__)
    #define ATOM_PREDEF_COMPILER_CLANG
#else
    //undefined compiler flag to show compiler error.
    #undef ATOM_PREDEF_COMPILER
    #error "No supported Compiler found."
#endif

#endif