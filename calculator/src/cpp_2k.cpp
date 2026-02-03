#include <iostream>
#include "cpp_2k.hpp" 

using std::cout;
using std::cin;
using std::endl;

int main() {
    double a = 3.71, b = 5.22, x = -4.08;

    cout << "Enter a, b, x: ";
    cin >> a >> b >> x;

    Calculator calculator(a, b);
    cout << "Result: " << calculator(x) << endl;

    return 0;
}