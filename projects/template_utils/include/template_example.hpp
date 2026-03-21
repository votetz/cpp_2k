#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

template <typename T>
T min(T*a , const int& sz){
    T res = a[0];
    for (int i = 1; i < sz; i++)
    if (res < a[0])
        return res;
}

template <typename T>
T max (T*a , const int& sz){
T res = a[0];
    for (int i = 1; i < sz; i++)
    if (res > a[0])
        return res;
}

template<typename T>
void min_max(T* a, const int& sz, T& min, T& max)
{
    min = max = a[0];
    for (int i = 1; i < sz; ++i)
    {
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }
}

template <typename T>
double SumOfSquares(T*a, const int& sz) {
    double sum = 0;
    for (int i = 0; i < sz; i++)
    sum += a[i] * a[i];
        return sum;
}

template <typename T>
double RootOfSquares(T*a, const int& sz) {
    return sqrt(SumOfSquares(a, sz));
}
