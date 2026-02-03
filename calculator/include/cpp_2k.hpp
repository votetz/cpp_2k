#pragma once
#include <cmath>

class Calculator {
    const double a_;
    const double b_;
public:
    Calculator(const double& a, const double& b) : a_(a), b_(b) {}

    const double calculate(const double& x) const {
        return std::tan(2 * a_ - std::sin(b_ * x)) / (x * std::log(std::abs(2 - x)));
    }

    const double operator()(const double& x) const { return this->calculate(x); }
};