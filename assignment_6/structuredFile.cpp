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

void tempStats(std::vector<Temps> temperatureVector)
{
    float maxTemp{0.0};
    float minTemp{100.0};
    int dayOfMaxTemp{0};
    int dayOfMinTemp{0};

    for (unsigned int i = 1; i < temperatureVector.size(); i++) {
        if (temperatureVector.at(i).min < minTemp) {
            minTemp = temperatureVector.at(i).min;
            dayOfMinTemp = static_cast<int>(i);
        }
        if (temperatureVector.at(i).max > maxTemp) {
            maxTemp = temperatureVector.at(i).max;
            dayOfMaxTemp = static_cast<int>(i);
        }
    }

    std::cout << "The lowest tempreature was on day " << dayOfMinTemp << " with " << minTemp << " degrees." << std::endl;
    std::cout << "The highest tempreature was on day " << dayOfMaxTemp << " with " << maxTemp << " degrees." << std::endl;
}