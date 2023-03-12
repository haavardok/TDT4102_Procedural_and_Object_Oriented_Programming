#include "DynamicMemoryAllocation.hpp"

// Problem 1a
/**
 * @brief Function that calculates 'length' numbers of the Fibonacci sequence and saves the value to '*result'
 * 
 * @param result 
 * @param length 
 */
void fillInFibonacciNumbers(int *result, int length)
{
    if (length <= 0) {
        return;
    }
    else if (length == 1) {
        result[0] = 0;
        return;
    }
    else {
        result[0] = 0;
        result[1] = 1;

        for (int i = 2; i < length; i++) {
            result[i] = result[i-1] + result[i-2];
        }
    }
}

// Problem 1b
/**
 * @brief Function that writes 'length' elements of array to terminal
 * 
 * @param arr 
 * @param length 
 */
void printArray(int *arr, int length)
{
    std::cout << "The " << length << " first Fibonacci numbers is: ";
    for (int i = 0; i < length; i++) {
        std::cout << arr[i];
        if (i < length-1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

void createFibonacci()
{
    int fibonacciLength{0};

    std::cout << "Length of Fibonacci sequence: ";
    std::cin >> fibonacciLength;
    int *fibonacciSequence = new int[static_cast<unsigned int>(fibonacciLength)] {};

    fillInFibonacciNumbers(fibonacciSequence, fibonacciLength);

    printArray(fibonacciSequence, fibonacciLength);

    delete[] fibonacciSequence;
    fibonacciSequence = nullptr;
}
