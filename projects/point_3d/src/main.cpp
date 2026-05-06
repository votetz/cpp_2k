#include "point_3d.hpp"
#include <iostream>
#include <iomanip>

int main() {
    Point3D point_a(1.0, 2.0, 3.0);
    Point3D point_b(4.0, 6.0, 8.0);

    double dist = point_a.distance(point_b);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Point A: (" << point_a.get_x() << ", " 
              << point_a.get_y() << ", " << point_a.get_z() << ")\n";
    std::cout << "Point B: (" << point_b.get_x() << ", " 
              << point_b.get_y() << ", " << point_b.get_z() << ")\n";
    std::cout << "Distance: " << dist << "\n";

    return 0;
}
