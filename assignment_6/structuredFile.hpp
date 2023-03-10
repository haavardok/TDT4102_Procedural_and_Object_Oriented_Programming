#pragma once
#include "std_lib_facilities.h"

struct Temps {
    float min{0.0};
    float max{0.0};
};

std::istream& operator>>(std::istream& is, Temps& t);

std::vector<Temps> readTemps(const std::string& fileName);

void tempStats(std::vector<Temps> temperatureVector);