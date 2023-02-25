
#include "std_lib_facilities.h"
#include "fileUtilities.hpp"
#include "courseCatalog.hpp"
#include "structuredFile.hpp"

/*
    ----Theory problems----

    Problem 3d
    When adding the course name "C++" to the course code "TDT4102" before removing the
    previous one beforehand, no changes to the course map happens. If using operator[]
    to insert a new element in a map, whatever argument was given inside "[]" will make
    a new element in the map. If the element exist with the same key as given inside "[]"
    that element will be overwritten. Using the .insert() method instead will never
    overwrite the element if it already exists, as proven by the test code in main.
    The best way to update elements in a map is probably to use .swap() instead.
*/

// Problem 2b
const map<string, string> capitalsMap {
        {"Norway", "Oslo"},
        {"Sweden", "Stockholm"},
        {"Denmark", "Copenhagen"}
    };

    string getCapital(const string& country) {
        return capitalsMap.at(country);
    }
/*
    The error message comes from the [] operation we try to do on the map. Since
    the map is defined as a const map, one cannot add elements to the map after
    declaration. Changing to .at(country) solves the issue trying to read the
    capitals from the countries.
*/

//------------------------------------------------------------------------------

int main() {

    // Problem 2b
    // std::cout << "Capitals:" << std::endl;
    // for (pair<const string, const string> elem : capitalsMap) {
    //     cout << getCapital(elem.first) << std::endl;
    // }

    // Problem 3c
    // CourseCatalog courseCatalog;
    // courseCatalog.addCourse("TDT4110", "Information Technology, Introduction");
    // courseCatalog.addCourse("TDT4102", "Procedural and Object Oriented Programming");
    // courseCatalog.addCourse("TMA4100", "Mathematics 1 - Single variable calculus");
    // std::cout << courseCatalog;

    // Problem 3d
    // courseCatalog.addCourse("TDT4102", "C++");
    // std::cout << courseCatalog;

    // Problem 3e
    // CourseCatalog courseCatalog;
    // courseCatalog.loadCoursesFromFile("NTNU_courses.txt");
    // std::cout << courseCatalog;
    // courseCatalog.addCourse("TTK4130", "Modelling and Simulation");
    // std::cout << courseCatalog;
    // courseCatalog.saveCoursesToFile("NTNU_courses_new.txt");
    
    // Problem 4c and 4d
    // vector<Temps> temperatureVector;
    // temperatureVector = readTemps("temperatures.txt");
    // tempStats(temperatureVector);


    return 0;
}

//------------------------------------------------------------------------------
