#include "box_class.hpp"

int main() {
    Box small_box(10, 10, 5);
    Box large_box(20, 15, 10);

    Box combined_box = small_box + large_box;

    std::cout << "First: " << small_box << "\n";
    std::cout << "Second: " << large_box << "\n";
    std::cout << "Result: " << combined_box << "\n";

    return 0;
}