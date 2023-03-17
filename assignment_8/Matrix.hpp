#pragma once
#include <cassert>
#include <iostream>
#include <utility>

class Matrix
{
private:
    int rows{0};
    int columns{0};
    double **matrixData;
public:
    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    Matrix(const Matrix &rhs);
    ~Matrix();

    Matrix &operator=(Matrix rhs);
    Matrix &operator+=(const Matrix &rhs);
    Matrix operator+(const Matrix &rhs);

    double get(int row, int col) const;
    void set(int row, int col, double value);

    int getRows() const;
    int getColumns() const;
};

std::ostream& operator<< (std::ostream &os, const Matrix &element);
