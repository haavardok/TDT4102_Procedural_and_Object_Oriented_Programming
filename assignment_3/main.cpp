
#include "std_lib_facilities.h"
#include "cannonball.hpp"

#define errorLimit 0.0001

//------------------------------------------------------------------------------'

// Problem 3a
/*
    The program compiles successfully as expected.
*/

// Problem 3b
void testDeviation(double compareOperand, double toOperand,
                   double maxError, string name)
{
    bool testResult = false;
    testResult = (abs(compareOperand - toOperand) <= maxError);

    if(testResult == true) {
        cout << name << " is valid." << endl;
    }
    else {
        cout << name << " is not valid, expected " << toOperand << ", got " << compareOperand << "!" << endl;
    }
}

// C++ programs start by executing the function main
int main() {
    // Problem 3c
    testDeviation(posX(0.0,50.0,5.0), 250.000, errorLimit, "posX(0.0,50.0,5.0)");
    testDeviation(posY(0.0,50.0,5.0), 127.375, errorLimit, "posY(0.0,50.0,5.0)");
    testDeviation(velY(50.0,5.0), 0.95, errorLimit, "velY(50.0,50.0)");
    testDeviation(flightTime(50.0), 10.19368, errorLimit, "flightTime(50.0)");

    //vector<double> testvector = getVelocityVector(27.5, 15.64);
    //cout << testvector.at(0) << "\t" << testvector.at(1) << endl;

    // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
    // did not encounter any errors
    return 0;
}

//------------------------------------------------------------------------------
