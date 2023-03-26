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
        Person(const std::string &name, const std::string &email, std::unique_ptr<Car> car = nullptr); // Using default arguments

        std::string getName() const;
        std::string getEmail() const;
        void setEmail(const std::string &emailAddress);
        bool hasAvailableSeats() const;

        friend std::ostream &operator<<(std::ostream &os, const Person &person);
};
