/*---------------------------------------------------------------------
    'OS.h' is part of Atom.Core, and defines macros for determining
    the current operating system.
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

#ifndef _OS_H
#define _OS_H

#define ATOM_PREDEF_OS

#if defined(_WIN16)
    #define ATOM_PREDEF_OS_WIN16 
#elif defined(_WIN32)
    #define ATOM_PREDEF_OS_WIN32 
#elif (_WIN64)
    #define ATOM_PREDEF_OS_WIN64 
#elif (__linux__)
    #define ATOM_PREDEF_OS_LINUX 
#else
    #undef ATOM_PREDEF_OS
    #error "Current OS not supported"
#endif

#endif