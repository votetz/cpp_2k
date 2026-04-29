#pragma once

#include "triangular_matrix.hpp"

class LowerTriangularMatrix {
private:
    int n;
    std::vector<double> data;

public:
    explicit LowerTriangularMatrix(int size);

    void set(int i, int j, double val);

    [[nodiscard]] double get(int i, int j) const;

    void display() const;
};