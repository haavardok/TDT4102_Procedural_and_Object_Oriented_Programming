#pragma once
#include <string>
#include <memory>
#include <iostream>
#include "Car.hpp"

class Person
{
    private:
        std::string name;
        std::string email;
        std::unique_ptr<Car> car;
    public:
        Person(std::string name, std::string email);

        std::string getName() const;
        std::string getEmail() const;
        void setEmail(std::string emailAddress);
        bool hasAvailableSeats() const;

        
};

std::ostream &operator<<(std::ostream &os, const Person &person);
