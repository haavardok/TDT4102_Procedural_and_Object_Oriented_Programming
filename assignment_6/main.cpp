
#include "std_lib_facilities.h"
#include "fileUtilities.hpp"

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
    std::cout << "Capitals:" << std::endl;
    for (pair<const string, const string> elem : capitalsMap) {
        cout << getCapital(elem.first) << std::endl;
    }

    return 0;
}

//------------------------------------------------------------------------------
