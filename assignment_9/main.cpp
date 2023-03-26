#include "Car.hpp"
#include "Person.hpp"

/*
    ---- Theory problems ----

    Problem 2d
    The operator should be decleared with a 'const' parameter since we wish not to
    change the content of Person, we only want to write it to the terminal. A case
    where we might not want to use the 'const' parameter is when we do indeed wish
    to manipulate the contents of Person.
*/

//------------------------------------------------------------------------------

int main() {

    // Problem 2e
    std::unique_ptr<Car> fullCar{new Car{0}};
    std::unique_ptr<Car> car{new Car{5}};

    std::shared_ptr<Person> person1{new Person{"Ola", "ola@nordmann.no"}};
    std::shared_ptr<Person> person2{new Person{"Kari", "kari@nordmann.no", std::move(car)}};
    Person person3("Otto", "otto@normalverbrauker.de");

    std::cout << person2->hasAvailableSeats() << std::endl;
    person3.setEmail("otto@medelsvendson.se");

    std::cout << *person1 << std::endl;
    std::cout << *person2 << std::endl;
    std::cout << person3 << std::endl;
    
    return 0;
}

//------------------------------------------------------------------------------
