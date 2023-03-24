#include "Car.hpp"

Car::Car(int number) : freeSeats{number}
{
    assert(number >= 0);
}

bool Car::hasFreeSeats() const
{
    if (freeSeats > 0) return true;
    else return false;
}

void Car::reserveFreeSeat()
{
    freeSeats--;
}
