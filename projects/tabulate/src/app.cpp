#include <iostream>
#include <iomanip>
#include "../include/tabulate.hpp"

using namespace std;

int main()
{
    cout << fixed << setprecision(4);

    cout << " y = f(x),  h=0.1,  x in [-3, 5] " << "\n\n";
    tabulate1D(-3.0, 5.0, 0.1);

    cout << "z = |y^3 - 2x| / (x+2),  hx=0.2  x in [-1,3],  hy=0.1  y in [-2,2] " << "\n\n";
    tabulate2D(-1.0, 3.0, 0.2, -2.0, 2.0, 0.1);

    return 0;
}