#include "diagonal_matrix.hpp"

DiagonalMatrix::DiagonalMatrix(int size)
    : n(size), data(size, 0.0) {}

void DiagonalMatrix::set(int i, int j, double val) {
    if (i == j && i >= 0 && i < n) {
        data[i] = val;
    } else if (val != 0) {
        std::cerr << "Warning: Cannot set non-zero value outside the diagonal in DiagonalMatrix\n";
    }
}

double DiagonalMatrix::get(int i, int j) const {
    if (i == j && i >= 0 && i < n) {
        return data[i];
    }
    return 0.0;
}

void DiagonalMatrix::display() const {
    std::cout << "Diagonal Matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(4) << get(i, j) << " ";
        }
        std::cout << "\n";
    }
}