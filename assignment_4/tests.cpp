#include "std_lib_facilities.h"
#include "tests.hpp"
#include "utilities.hpp"

// Problem 1c
void testCallByValue(void) {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result << endl;
}

// Problem 1d
void testCallByReference(void)
{
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << v0 << endl;
}

// Problem 1e
void testSwapNumbers(void)
{
    int n1 = 15;
    int n2 = 30;
    cout << "n1: " << n1 << " n2: " << n2 << endl;
    swapNumbers(n1, n2);
    cout << "n1: " << n1 << " n2: " << n2 << endl;
}

// Problem 3a
void testString(void)
{
    // Problem 3c
    string grades = randomizeString(8, 'A', 'F');
    cout << grades << endl;

    // Problem 3f
    vector<int> gradeCount(6);
    int averageGrade{0};
    char averageGradeInLetter{' '};

    for (int i = 0; i < static_cast<int>(gradeCount.size()); i++) {
        gradeCount.at(i) = countChar(grades, 'A' + i);
        averageGrade += gradeCount.at(i) * (5-i);
    }

    averageGrade = averageGrade / 6;
    averageGradeInLetter = 70 - static_cast<char>(averageGrade); 

    cout << averageGradeInLetter << endl;
}