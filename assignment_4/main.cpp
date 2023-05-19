
#include "std_lib_facilities.h"
#include "utilities.hpp"
#include "tests.hpp"
#include "game.hpp"
#include "masterVisual.h"

//------------------------------------------------------------------------------

// Problem 1a
/*
    When the code is run, the value of v0 will be 25 since the function
    incrementByValueNumTimes increments 10 times by 2 to the startValue 5.
*/

// Problem 1e
/*
    The function swapNumbers() should use pass-by-reference since we are not
    returning any value from the function but simply swapping the two numbers.
    If the number grew very large making a copy of the variables would be resource
    heavy, so pass-by-value does not apply well in this case.

    If using pass-by-const-reference we signal that the values of the to variables
    are not to change in the function, which strictly contradicts the intention of
    the function.
*/

// Problem 2e
/*
    The error message "error: redefinition of 'Student'" comes from including
    utilities.h in both main.cpp and tests.h. Since there is no "#pragma once"
    statement in utilities.h, the struct Student is tried declared two times
    which is prohibited. Declaration can only be done once in a program.
*/

// Problem 1c
void menu(void)
{
    int menu_choice{-1};

    while (1) {
		cout << "\nMenu\n"
			 << "0)\tExit menu\n"
			 << "1)\ttestCallByValue\n"
             << "2)\ttestCallByReference\n"
             << "3)\ttestSwapNumbers\n"
             << "4)\ttestString\n"
             << "5)\tPlay Mastermind\n"
             << "6)\tPlay visual Mastermind\n"
			 << "Choose option (0-6): ";

		cin >> menu_choice;

    switch (menu_choice)
		{
		case 1:
			testCallByValue();
			break;
        case 2:
            testCallByReference();
            break;
        case 3:
            testSwapNumbers();
            break;
        case 4:
            testString();
            break;
        case 5:
            playMastermind();
            break;
        case 6:
            playMastermindVisual();
            break;

		default:
            cout << "Closing menu ..." << endl;
			return; // quit program
			break;
		}
    }
}


// C++ programs start by executing the function main
int main() {

    // Problem 2d
    //Student student{"HOK", "MITK", 25};
    //cout << isInProgram(student, "MTTK") << endl;

    menu();

    // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
    // did not encounter any errors
    return 0;
}

//------------------------------------------------------------------------------
