#include "../include/template_example.hpp"

#include <algorithm>

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main() {
    int a1[] = {1, 2, 3, 4, 5};
    int sz = sizeof(a1)/sizeof(a1[0]);

    auto min1 = std::min_element(a1, a1 + sz);
    cout << *min1 << endl;

    {
    int min, max;
        min_max(a1, sz, min, max);
        cout << "Min:" << min << endl << "Max:" << max << endl;
    }

    double sum = SumOfSquares(a1, sz);
    double root = RootOfSquares(a1, sz);
    cout << "Sum:" << sum << endl << "Root:" << root << endl;
}

