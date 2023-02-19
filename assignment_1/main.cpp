// This is my solution to assignment 1

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------'

// Task 2a
int maxOfTwo(int a, int b)
{
    if(a > b) {
        cout << "A is greater than or equal to B\n";
        return a;
    }
    else {
        cout << "B is greater than or equal to A\n";
        return b;
    }
}

// Task 2c
int fibonacci(int n)
{
    int a = 0;
    int b = 1;
    cout << "Fibonacci numbers:\n";

    for(int x=1; x < n+1; x++) {
        cout << x << " " << b << endl;
        int temp = b;
        b += a;
        a = temp;
    }
    cout << "----\n";
    return b;
}

// Task 2d
int squareNumberSum(int n)
{
    int totalSum = 0;
    for(int i = 1; i < n+1; i++) {
        totalSum += i*i;
        cout << (i*i) << " " << endl;
    }
    cout << totalSum << endl;
    return totalSum;
}

//Task 2e
void triangleNumbersBelow(int n)
{
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below " << n << ":" << endl;
    
    while(acc < n) {
        cout << acc << endl;
        acc += num;
        num += 1;
    }
}

// Task 2f
bool isPrime(int n)
{
    for(int j = 2; j < n; j++) {
        if(n%j == 0) {
            return false;
        }
    }
    return true;
}

// Task 2g
void naivePrimeNumberSearch(int n)
{
    for(int number = 2; number < n; number++) {
        if(isPrime(number)) {
            cout << number << " is a prime" << endl;
        }
    }
}

// Task 2h
int findGreatestDivisor(int n)
{
    for(int divisor = n-1; divisor > 0; divisor--) {
        if(n%divisor == 0) {
            return divisor;
        }
    }
    return 1;
}

// C++ programs start by executing the function main
int main() {
    // Task 1a
    /* def isFibonacciNumber(n):
        a = 0
        b = 1
        while b < n:
            temp = b
            b += a
            a = temp
        
        return b == n */

    cout << "\nOppgave 2a)" << endl;
    cout << maxOfTwo(5, 6) << endl;

    cout << "\nOppgave 2c)" << endl;
    cout << fibonacci(5) << endl;
    
    cout << "\nOppgave 2d)" << endl;
    cout << squareNumberSum(5) << endl;

    cout << "\nOppgave 2e)" << endl;
    triangleNumbersBelow(10);

    cout << "\nOppgave 2f og 2g)" << endl;
    naivePrimeNumberSearch(14);

    cout << "\nOppgave 2h)" << endl;
    cout << findGreatestDivisor(14) << endl;
    cout << findGreatestDivisor(13) << endl;


    // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
    // did not encounter any errors
    return 0;
}

//------------------------------------------------------------------------------

