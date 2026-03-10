#include <iostream>
#include <cmath>

const double A = -2.0;
const double B = 2.0;
const double K = 5;
const int N = 20;
const double EPS = 0.0001;

// f(x) = x^3 - cos(2x)
inline double func(double x)
{
    return pow(x, 3) - cos(2.0 * x);
}
// q_n = -4x^2 / ((2n+2)(2n+1))
inline double q(double x, int n)
{
    return -4.0 * x * x / (2*n + 2) / (2*n + 1);
}