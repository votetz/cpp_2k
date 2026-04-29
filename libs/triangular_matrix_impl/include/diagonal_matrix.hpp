#pragma once

#include "triangular_matrix.hpp"

class DiagonalMatrix {
private:
    int n;
    std::vector<double> data;

public:
    explicit DiagonalMatrix(int size);

    void set(int i, int j, double val);

    [[nodiscard]] double get(int i, int j) const;

    void display() const;
};