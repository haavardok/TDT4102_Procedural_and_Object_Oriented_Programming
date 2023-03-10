#include "Animal.hpp"

// Problem 1b
/**
 * @brief Member function of Animal that writes animal name and age to terminal
 * @return std::string
 */
std::string Animal::toString()
{
    return "Animal: " + name + ", " + to_string(age);
}

//Problem 1c
/**
 * @brief Member function of Cat that writes animal name and age to terminal
 * @return std::string 
 */
std::string Cat::toString()
{
    return "Cat: " + name + ", " + to_string(age);
}
/**
 * @brief Member function of Dog that writes animal name and age to terminal
 * @return std::string 
 */
std::string Dog::toString()
{
    return "Dog: " + name + ", " + to_string(age);
}

// Problem 1d
/**
 * @brief Function that instantiaties several animal classes and prints to terminal
 */
void testAnimal()
{
    std::vector<std::unique_ptr<Animal>> animals;

    animals.emplace_back(new Cat("Cat1", 9));
    animals.emplace_back(new Cat("Cat2", 9));
    animals.emplace_back(new Dog("Dog1", 7));
    animals.emplace_back(new Dog("Dog2", 7));

    for (unsigned int i = 0; i < animals.size(); i++) {
        std::cout << animals.at(i)->toString() << std::endl;
    }
}