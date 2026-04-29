#include "geometry_2d.hpp"

int main() {
    Circle myCircle(5.0);

    std::cout << "Radius circle: " << myCircle.get_radius() << std::endl;
    std::cout << "Area circle: " << myCircle.getArea() << std::endl;

    return 0;
}