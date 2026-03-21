#include "../include/tabulate.hpp"

using namespace std;


//   -2x^3 + 4x^2 + x,  if x <= -1
//   5x^3 + x^2 - 1,    if -1 < x < 3
//   x^3 + 2x - 3,      if x >= 3

double func1(double x)
{
    if (x <= -1)
        return -2*x*x*x + 4*x*x + x;
    else if (x < 3)
        return 5*x*x*x + x*x - 1;
    else
        return x*x*x + 2*x - 3;
}

double func2(double x, double y)
{
    return fabs(y*y*y - 2*x) / (x + 2);
}

double round_to(double x)
{
    double r = round(x * 1e9) / 1e9;
    return fabs(r) < 1e-9 ? 0 : r;
}

void tabulate1D(double a, double b, double h)
{
    double min_val = NAN, max_val = NAN;
    const int w = 10;

    cout << string(w + 2, '-') << string(w, '-') << "\n";
    cout << setw(6) << "X" << setw(w) << "Y = f(x)" << "\n";
    cout << string(w + 2, '-') << string(w, '-') << "\n";

    for (double x = a; x <= b + 1e-9; x += h)
    {
        double rx = round_to(x);
        double y  = func1(rx);

        if (isnan(min_val) || y < min_val) min_val = y;
        if (isnan(max_val) || y > max_val) max_val = y;

        cout << setw(6)  << rx
             << setw(w)  << y << "\n";
    }

    cout << string(w + 2, '-') << string(w, '-') << "\n";
    cout << "Minimum: " << min_val << "\n";
    cout << "Maximum: " << max_val << "\n\n";
}

void tabulate2D(double a, double b, double hx, double c, double d, double hy)
{
    double min_val = NAN, max_val = NAN;
    const int w = 9;

    cout << setw(5) << "Y\\X";
    for (double x = a; x <= b + 1e-9; x += hx)
        cout << setw(w) << round_to(x);
    cout << "\n";

    for (double y = c; y <= d + 1e-9; y += hy)
    {
        cout << setw(5) << round_to(y);
        for (double x = a; x <= b + 1e-9; x += hx)
        {
            double z = func2(round_to(x), round_to(y));

            if (isnan(min_val) || z < min_val) min_val = z;
            if (isnan(max_val) || z > max_val) max_val = z;

            cout << setw(w) << z;
        }
        cout << "\n";
    }
    cout << "\nMinimum: " << min_val << "\n";
    cout << "Maximum: " << max_val << "\n";
}