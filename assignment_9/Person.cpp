#include "Person.hpp"

Person::Person(const std::string &name, const std::string &email, std::unique_ptr<Car> car)
    : name{name}, email{email}, car{std::move(car)} {}

std::string Person::getName() const
{
    return name;
}

std::string Person::getEmail() const
{
    return email;
}

void Person::setEmail(const std::string &emailAddress)
{
    this->email = emailAddress;
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
    os << person.name << ", " << person.email;

    return os;
}
