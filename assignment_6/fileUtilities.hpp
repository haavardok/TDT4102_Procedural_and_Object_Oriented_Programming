#pragma once
#include "std_lib_facilities.h"

// Problem 1a
/**
 * @brief Reads words from the user and writes total input to a file
 */
void readInputAndWriteToFile(void);

// Problem 1b
/**
 * @brief Reads data from a file to make copy of file with line numbers
 * 
 * @param std::string fileToCopy
 */
void makeFileCopyWithLineNumber(const std::string& fileToCopy);

// Problem 2a
/**
 * @brief Unordered_map of letters in english alfabet with corresponding int value
 */
const std::unordered_map<std::string, unsigned int> letterMap {
    {"a", 1},
    {"b", 2},
    {"c", 3},
    {"d", 4},
    {"e", 5},
    {"f", 6},
    {"g", 7},
    {"h", 8},
    {"i", 9},
    {"j", 10},
    {"k", 11},
    {"l", 12},
    {"m", 12},
    {"n", 13},
    {"o", 14},
    {"p", 15},
    {"q", 16},
    {"r", 17},
    {"s", 18},
    {"t", 19},
    {"u", 20},
    {"v", 21},
    {"w", 22},
    {"x", 23},
    {"y", 24},
    {"z", 25},
};

/***
 * @brief Counts occurences of each letter in file. Writes results to terminal.
*/
void letterStatisticsInFile(const std::string& fileName);
