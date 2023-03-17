#include "Matrix.hpp"

Matrix::Matrix(int nRows, int nColumns) : rows{nRows}, columns{nColumns}, matrixData{nullptr}
{
    assert(nRows >= 1);
    assert(nColumns >= 1);

    matrixData = new double*[static_cast<unsigned int>(rows)];
    for (int i = 0; i < rows; i++) {
        matrixData[i] = new double[static_cast<unsigned int>(columns)];
        for (int j = 0; j < columns; j++) {
            matrixData[i][j] = 0.0;
        }
    }
}

Matrix::Matrix(int nRows) : Matrix{nRows, nRows}
{
    assert(nRows >= 1);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (j == i) {
                matrixData[i][j] = 1.0;
            }
        }
    }
}

Matrix::Matrix(const Matrix &rhs) : rows{rhs.rows}, columns{rhs.columns}, matrixData{nullptr}
{
    matrixData = new double*[static_cast<unsigned int>(rows)];
    for (int i = 0; i < rows; i++) {
        matrixData[i] = new double[static_cast<unsigned int>(columns)];
        for (int j = 0; j < columns; j++) {
            matrixData[i][j] = rhs.matrixData[i][j];
        }
    }

}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++) {
        delete[] matrixData[i];
        matrixData[i] = nullptr;
    }

    delete[] matrixData;
    matrixData = nullptr;

    rows = 0;
    columns = 0;
}

Matrix &Matrix::operator=(Matrix rhs)
{
    std::swap(this->rows, rhs.rows);
    std::swap(this->columns, rhs.columns);
    std::swap(matrixData, rhs.matrixData);

    return *this;
}

Matrix &Matrix::operator+=(const Matrix &rhs)
{
    assert(this->rows == rhs.rows && this->columns == rhs.columns);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            this->matrixData[i][j] += rhs.matrixData[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator+(const Matrix &rhs)
{
    assert(this->rows == rhs.rows && this->columns == rhs.columns);

    Matrix summedMatrix{*this};
    summedMatrix += rhs;

	return summedMatrix;
}

double Matrix::get(int row, int col) const
{
    return matrixData[row][col];
}

void Matrix::set(int row, int col, double value)
{
    matrixData[row][col] = value;
}

int Matrix::getRows() const
{
    return rows;
}

int Matrix::getColumns() const
{
    return columns;
}

std::ostream &operator<< (std::ostream &os, const Matrix &matrix)
{
    for (int i = 0; i < matrix.getRows(); i++) {
        os << "| ";
        for (int j = 0; j < matrix.getColumns(); j++) {
            os << matrix.get(i, j) << " ";
        }
        os << "|" << std::endl;
    }

    return os;
}
