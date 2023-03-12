#include "DynamicMemoryAllocation.hpp"
#include "Matrix.hpp"
#include "Dummy.hpp"

/*
    ----Theory problems----

    Problem 3a
    When running the given code, it seems to me that the output would be:
    a: 4
    b: 4
    c: some memory address
    a: 4
    b: 3
    c: 5

    Problem 3b
    It seems my initial guess was wrong. When writing to terminal it is clear
    that by simply taking c = a; gives unexpected results. The effect is that *num
    in Dummy c indeed takes the value of *num in Dummy a, but changing *c.num = 5
    makes *a.num = 5 also. This has to due with c pointing to the same memory address
    as pointer a is pointing to. I.e. *a.num and *c.num are both pointers to the same
    instance of the dynamically allocated integer. c = a; is a binary copy, thus it
    makes a copy of the pointer, not the memory address.
        The crashing of the program probably has to do with the destructor of the class.
    When a's destructor is called, it deletes the allocated memory space for *a.num.
    Since *a.num and *c.num are pointing to the same memory space (shallow copy problem)
    c's pointer be meaningless.

    Problem 3c
    Yes, the program does indeed write something else out to the terminal. In the second
    iteration b: 3. This is expected as now we have made an copy constructor for Dummy.

    Problem 3d
    The program now finishes as wanted. The values being written to the terminal coincides
    with what is to be expected.
*/

//------------------------------------------------------------------------------

int main() {

    // Problem 1
    // createFibonacci();

    // Problem 2
    // Matrix matrix(2,4);
    // std::cout << "matrix:\n" << matrix << std::endl;
    // matrix.set(1,3, 1.0);
    // std::cout << "Edited matrix:\n" << matrix << std::endl;

    // Matrix squareMatrix(3);
    // std::cout << "Last element in squareMatrix: " << squareMatrix.get(2,2) << "\n" << std::endl;
    // std::cout << "squareMatrix:\n" << squareMatrix << std::endl;

    // Problem 3b
    dummyTest();

    return 0;
}

//------------------------------------------------------------------------------
