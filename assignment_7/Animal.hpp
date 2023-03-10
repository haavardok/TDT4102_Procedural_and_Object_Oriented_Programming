#pragma once
#include "std_lib_facilities.h"

class Animal
{
protected:
    std::string name{""};
    int age{0};
public:
    virtual std::string toString() = 0; // Making the Animal class pure virtual
    Animal(const std::string &name, const int &age) : name{name}, age{age} {};

    virtual ~Animal() {};
};

class Cat : public Animal
{
public:
    std::string toString() override;
    Cat(const std::string &name, const int &age) : Animal{name, age} {};
};

class Dog : public Animal
{
public:
    std::string toString() override;
    Dog(const std::string &name, const int &age) : Animal{name, age} {};
};

void testAnimal();