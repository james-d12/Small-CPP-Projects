/*---------------------------------------------------------------------
    'Standard.h' is part of Atom.Core, and defines macros for determining
    if C++ is in use, and if so what version.
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

#ifndef _STANDARD_H
#define _STANDARD_H

#if defined(__cplusplus)
    #define ATOM_PREDEF_STANDARD_CPP
    #if (__cplusplus == 199711L)
        #define ATOM_PREDEF_STANDARD_CPP98
    #endif
    #if (__cplusplus >= 201103L)
        #define ATOM_PREDEF_STANDARD_CPP11
    #endif
    #if (__cplusplus >= 201402L)
        #define ATOM_PREDEF_STANDARD_CPP14
    #endif
    #if (__cplusplus >= 201703L)
        #define ATOM_PREDEF_STANDARD_CPP17
    #endif
#else
    #error "Atom requires C++"
#endif

#endif