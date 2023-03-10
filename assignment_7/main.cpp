#include "std_lib_facilities.h"
#include "Animal.hpp"

/*
    ----Theory problems----

    Problem 1a
    Public, private and protected are keywords for specifying the scope of a variable
    for example in a class (or other user-defined types). Public gives the user access
    to all variables, where private keeps variables and function unavailable for direct
    access by the user. Private variables and functions can be accessed through get and
    set methods. Protected means that whatever is decleared here can only be used
    directly from classes derived from the class. I.e. protected ensures a user don't
    make base classes directly, but instead make sub classes from them.

    Problem 1d
    If one removes 'virtual' in front of 'toString()' in the 'Animal' class, then the
    redefinition of 'toString' in the sub classes would not be used. The result in the
    terminal is 'Animal:' being printed instead of 'Cat:' and 'Dog:'.

    Problem 5b
    I chose to inherit from EmptyFace instead of SmilingFace because the similarities
    between smiling and sad is everything about the emoji except the mouth.

    Problem 5e
    I chose to inherit from EmptyFace instead of Smilingface because inheriting from
    SmilingFace would result in the same as inheriting from EmptyFace because of the
    'override' statement in the class declaration. Thus I chose to inherit from EmptyFace
    due to clarity.
*/

//------------------------------------------------------------------------------

// int main() {
    
//     // Problem 1d
//     testAnimal();

//     // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
//     // did not encounter any errors
//     return 0;
// }

//------------------------------------------------------------------------------
