#include "point_3d.hpp"
#include <cmath>

Point3D::Point3D(double x, double y, double z)
    : x_(x), y_(y), z_(z) {
}

double Point3D::get_x() const {
    return x_;
}

double Point3D::get_y() const {
    return y_;
}

double Point3D::get_z() const {
    return z_;
}

double Point3D::distance(const Point3D& other) const {
    return std::hypot(x_ - other.x_, y_ - other.y_, z_ - other.z_);
}
