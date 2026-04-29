#include "lower_triangular_matrix.hpp"
#include <iomanip>

LowerTriangularMatrix::LowerTriangularMatrix(int size)
    : n(size), data(size * (size + 1) / 2, 0.0) {}

void LowerTriangularMatrix::set(int i, int j, double val) {
    if (i >= j && i < n && j >= 0) {
        data[i * (i + 1) / 2 + j] = val;
    } else if (val != 0) {
        std::cerr << "Warning: Cannot set non-zero value above the diagonal in LowerTriangularMatrix\n";
    }
}

double LowerTriangularMatrix::get(int i, int j) const {
    if (i >= j && i < n && j >= 0) {
        return data[i * (i + 1) / 2 + j];
    }
    return 0.0;
}

void LowerTriangularMatrix::display() const {
    std::cout << "Lower Triangular Matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(4) << get(i, j) << " ";
        }
        std::cout << "\n";
    }
}
