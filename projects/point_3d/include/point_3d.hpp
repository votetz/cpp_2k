#pragma once

class Point3D
{
private:
    double x_;
    double y_;
    double z_;

public:
    Point3D(double x, double y, double z);

    double get_x() const;
    double get_y() const;
    double get_z() const;

    double distance(const Point3D& other) const;
};
