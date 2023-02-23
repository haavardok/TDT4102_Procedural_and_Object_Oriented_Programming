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
/***
 * @brief Counts occurences of each letter in file. Writes results to terminal.
*/
void letterStatisticsInFile(const std::string& fileName);
