#pragma once

#include <algorithm>
#include "triangular_matrix.hpp"

class SymmetricMatrix {
private:
    int n;
    std::vector<double> data;
public:
    SymmetricMatrix(int size);

    double& operator()(int i, int j);
    double operator()(int i, int j) const;

    friend std::ostream& operator<<(std::ostream& os, const SymmetricMatrix& mat);
};