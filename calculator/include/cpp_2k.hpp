#pragma once
#include <cmath>
#include <iostream>

class Calculator {
    const double a_;
    const double b_;
public:
    Calculator(const double& a, const double& b) : a_(a), b_(b) {}

    const double calculate(const double& x) const {
        const double arg_sin = b_ * x;
        const double val_sin = std::sin(arg_sin);

        const double arg_tan = 2 * a_ - val_sin;
        const double numerator = std::tan(arg_tan);

        const double log_arg = std::abs(2 - x);
        const double val_log = std::log(log_arg);

        const double denominator = x * val_log;

        const double result = numerator / denominator;

        return result;
    }

    const double operator()(const double& x) const { return this->calculate(x); }
};