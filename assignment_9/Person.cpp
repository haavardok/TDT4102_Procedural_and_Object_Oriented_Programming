#include "Person.hpp"

Person::Person(std::string name, std::string email)
    : name{name}, email{email}, car{nullptr} {}

std::string Person::getName() const
{
    return name;
}

std::string Person::getEmail() const
{
    return email;
}

void Person::setEmail(std::string emailAddress)
{
    email = emailAddress;
}

bool Person::hasAvailableSeats() const
{
    if (car.get() != nullptr && car->hasFreeSeats()) {
        return true;
    }
    else {
        return false;
    }
}

std::ostream &operator<< (std::ostream &os, const Person &person)
{
    os << person.getName() << ", " << person.getEmail();

    return os;
}
