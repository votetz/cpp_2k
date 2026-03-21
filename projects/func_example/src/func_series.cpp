#include <iostream>
#include "../include/func_series.hpp"
#include <cmath>

using namespace std;

int main()
{
    cout << fixed;
    cout.precision(7);

    double h = (B - A) / (K - 1);
    cout << "=== N = " << N << " ===" << endl;
    cout << "x\t\tSum\t\tControl\t\tTolerance" << endl;

    for (int i = 0; i < K; i++)
    {
        double x = A + i * h;
        double S = 0.0, an = 1.0;

        for (int n = 0; n < N; n++)
        {
            S += an;
            an *= q(x, n);
        }

        S = pow(x, 3) - S;
        double y   = func(x);
        double tol = fabs(S - y);

        cout << x << "\t\t" << S << "\t\t" << y << "\t\t" << tol << endl;
    }

    cout << "\n=== EPS = " << EPS << " ===" << endl;
    cout << "x\t\tSum\t\tControl\t\tTolerance\tN_terms" << endl;

    for (int i = 0; i < K; i++)
    {
        double x = A + i * h;
        double S = 0.0, an = 1.0;
        int n = 0;

        while (fabs(an) >= EPS)
        {
            S += an;
            an *= q(x, n);
            n++;
        }

        S = pow(x, 3) - S;
        double y   = func(x);
        double tol = fabs(S - y);

        cout << x << "\t\t" << S << "\t\t" << y << "\t\t" << tol << "\t\t" << n << endl;
    }

    return 0;
}