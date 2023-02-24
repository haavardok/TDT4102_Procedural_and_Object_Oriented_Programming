#include "structuredFile.hpp"

// Problem 4b
/**
 * @brief Operator overloading for writing input data from file to Temps struct
 */
std::istream& operator>>(std::istream& is, Temps& t)
{
    return is >> t.max >> t.min;
}

// Problem 4c
/**
 * @brief Takes max and min temperature data from file and returns a temperature vector
 * 
 * @param const std::string& fileName 
 * @return vector<Temps> 
 */
vector<Temps> readTemps(const std::string& fileName)
{
    vector<Temps> temperatureVector;
    Temps t;
    std::string line{""};

    std::ifstream inputStream{fileName};
    if (!inputStream) {
        error("Can't open input file ", fileName);
    }

    for (Temps t; inputStream >> t;) {
        temperatureVector.push_back(t);
    }

    return temperatureVector;
}

// Problem 4d

void tempStats(vector<Temps> temperatureVector)
{
    
}