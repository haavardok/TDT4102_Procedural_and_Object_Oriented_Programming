#include "DynamicMemoryAllocation.hpp"
#include "Matrix.hpp"

//------------------------------------------------------------------------------

int main() {

    // Problem 1
    // createFibonacci();

    // Problem 2
    Matrix matrix(2,4);
    std::cout << "matrix:\n" << matrix << std::endl;
    matrix.set(1,3, 1.0);
    std::cout << "Edited matrix:\n" << matrix << std::endl;

    Matrix squareMatrix(3);
    std::cout << "Last element in squareMatrix: " << squareMatrix.get(2,2) << "\n" << std::endl;
    std::cout << "squareMatrix:\n" << squareMatrix << std::endl;

    return 0;
}

//------------------------------------------------------------------------------
