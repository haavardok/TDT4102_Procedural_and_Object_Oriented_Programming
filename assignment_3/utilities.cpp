#include <random>
#include "std_lib_facilities.h"
#include "utilities.hpp"

random_device rd;
default_random_engine generator(rd());

// Problem 5a
double randomNumber()
{
    double number = generator();
    return number;
}