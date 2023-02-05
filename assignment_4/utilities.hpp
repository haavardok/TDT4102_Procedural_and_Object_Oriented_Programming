#pragma once

// Problem 1b
int incrementByValueNumTimes(int startValue, int increment, int numTimes);

// Problem 1d
void incrementByValueNumTimesRef(int& startValue, const int& increment, const int& numTimes);

// Problem 1e
void swapNumbers(int& number1, int& number2);

// Problem 2a
struct Student{
    string name;
    string studyProgram;
    int age;
};

// Problem 2b
void printStudent(const Student& student);

// Problem 2c
bool isInProgram(const Student& student, const string& studyProgram);

// Problem 3b
string randomizeString(const int& stringLength, const char& lowerChar, const char& upperChar);

// Problem 3d
// Function takes in single letters from terminal to form a string. Letters
// must comply with limits. Returns the string in lower case letters.
string readInputToString(const int& stringLength, const char& lowerLimit, const char& upperLimit);

// Problem 3e
int countChar(const string& string, const char& letter);
