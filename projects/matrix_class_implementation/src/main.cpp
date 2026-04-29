#include "matrix.hpp"

int main() {
    try {
        Matrix m1(2, 2);
        m1(0, 0) = 1.0; m1(0, 1) = 2.0;
        m1(1, 0) = 3.0; m1(1, 1) = 4.0;

        Matrix m2 = m1 * 2.0;
        Matrix sum = m1 + m2;

        std::cout << "Matrix 1:\n" << m1;
        std::cout << "Matrix 2 (m1 * 2):\n" << m2;
        std::cout << "Sum:\n" << sum;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}