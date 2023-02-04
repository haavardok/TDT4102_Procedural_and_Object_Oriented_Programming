#include "std_lib_facilities.h"
#include "utilities.hpp"

// Problem 5b and 5c
int randomWithLimits(int lowerLimit, int upperLimit)
{
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(lowerLimit,upperLimit);
    int number = distribution(generator);
    return number;
}
