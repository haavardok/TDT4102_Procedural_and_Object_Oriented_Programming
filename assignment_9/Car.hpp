#pragma once
#include <cassert>

class Car
{
    private:
        int freeSeats;
    public:
        Car(int number);

        bool hasFreeSeats() const;
        void reserveFreeSeat();
};
