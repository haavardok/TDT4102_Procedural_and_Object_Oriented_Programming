#include "std_lib_facilities.h"
#include "utilities.hpp"

// Problem 1b
int incrementByValueNumTimes(int startValue, int increment, int numTimes)
{
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

// Problem 1d
void incrementByValueNumTimesRef(int& startValue, const int& increment, const int& numTimes)
{
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
}

// Problem 1e
void swapNumbers(int& number1, int& number2)
{
    int temp = number1;
    number1 = number2;
    number2 = temp;
}

// Problem 2b
void printStudent(const Student& student)
{
    cout << student.name << ", "
         << student.age << ", "
         << student.studyProgram
         << endl;
}

// Problem 2c
bool isInProgram(const Student& student, const string& studyProgram)
{
    if (student.studyProgram == studyProgram) {
        return true;
    }
    else {
        return false;
    }
}

// Problem 3b
string randomizeString(const int& stringLength, const char& lowerChar, const char& upperChar)
{
    string randomString{""};
    random_device seed;
    default_random_engine randomGenerator(seed());
    uniform_int_distribution<char> letterDistribution(lowerChar, upperChar);

    for (int i = 0; i < stringLength; i++) {
        char letter = letterDistribution(randomGenerator);
        randomString += letter;
    }

    return randomString;
}

// Problem 3d
string readInputToString(const int& stringLength, const char& lowerLimit, const char& upperLimit)
{
    string stringInput{""};
    char letterInput{' '};

    for (int i = 0; i < stringLength; i++) {
        cout << "Insert letter " << i+1 << ": ";
        cin >> letterInput;

        while (letterInput < lowerLimit) {
            cout << "Too small letter. Try again: ";
            cin >> letterInput;
        }
        while (letterInput > upperLimit) {
            cout << "Too large letter. Try again: ";
            cin >> letterInput;
        }
        if (islower(letterInput)) {
            letterInput = static_cast<char>(toupper(letterInput));
        }
        stringInput += letterInput;
    }

    return stringInput;
}

// Problem 3e
int countChar(const string& string, const char& letter)
{
    int count{0};

    for (unsigned int i = 0; i < static_cast<unsigned int>(string.size()); i++) {
        if (string.at(i) == letter) {
            count++;
        }
    }

  return count;
}
