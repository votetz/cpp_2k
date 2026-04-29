#pragma once

#include "triangular_matrix.hpp"

class UpperTriangularMatrix {
private:
    int size;
    std::vector<double> data;

public:
    explicit UpperTriangularMatrix(int n);

    void setValue(int row, int col, double value);
    [[nodiscard]] double getValue(int row, int col) const;

    void display() const;
};