#include "upper_triangular_matrix.hpp"

UpperTriangularMatrix::UpperTriangularMatrix(int n)
    : size(n), data(n * (n + 1) / 2, 0.0) {}

void UpperTriangularMatrix::setValue(int row, int col, double value) {
    if (row <= col) {
        int index = row * size - row * (row - 1) / 2 + (col - row);
        data[index] = value;
    } else if (value != 0) {
        std::cerr << "Warning: Cannot set non-zero value in the lower part of UpperTriangularMatrix\n";
    }
}

double UpperTriangularMatrix::getValue(int row, int col) const {
    if (row <= col) {
        int index = row * size - row * (row - 1) / 2 + (col - row);
        return data[index];
    }
    return 0.0;
}

void UpperTriangularMatrix::display() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(4) << getValue(i, j) << " ";
        }
        std::cout << "\n";
    }
}