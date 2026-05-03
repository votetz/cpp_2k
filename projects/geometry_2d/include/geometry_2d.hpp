#pragma once
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

class Shape2D
{
public:
    virtual ~Shape2D() {}

    virtual double getArea() const = 0;
};

class Circle : public Shape2D
{
private:
    double radius;

public:
    explicit Circle(const double radius)
        : radius(radius)
    {}

    double getArea() const override {
        return M_PI * std::pow(radius, 2);
    }

    [[nodiscard]] double get_radius() const
    {
        return radius;
    }

    void set_radius(const double radius)
    {
        this->radius = radius;
    }
};