#include "symmetric_matrix.hpp"
#include <iomanip>

SymmetricMatrix::SymmetricMatrix(int size)
    : n(size), data(size * (size + 1) / 2, 0.0) {}

double& SymmetricMatrix::operator()(int i, int j) {
    if (i < j) std::swap(i, j);
    return data[i * (i + 1) / 2 + j];
}

double SymmetricMatrix::operator()(int i, int j) const {
    if (i < j) std::swap(i, j);
    return data[i * (i + 1) / 2 + j];
}

std::ostream& operator<<(std::ostream& os, const SymmetricMatrix& mat) {
    for (int i = 0; i < mat.n; ++i) {
        for (int j = 0; j < mat.n; ++j) {
            os << std::setw(4) << mat(i, j) << " ";
        }
        os << "\n";
    }
    return os;
}