#include "triangular_matrix.hpp"

int main() {
    int size = 3;

    DiagonalMatrix dm(size);
    dm.set(0, 0, 5); dm.set(1, 1, 8); dm.set(2, 2, 3);
    dm.display();

    std::cout << "\nSymmetric Matrix:\n";
    SymmetricMatrix sm(size);

    sm(0, 1) = 7;
    sm(0, 0) = 1;
    sm(1, 1) = 2;
    sm(2, 2) = 3;

    std::cout << sm;

    return 0;
}