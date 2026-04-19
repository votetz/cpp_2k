#include "restaurant/discount.hpp"

namespace restaurant
{
    PercentDiscount::PercentDiscount(double percent)
        : factor(1.0 - percent / 100.0)
    {}

    double PercentDiscount::apply(double total) const
    {
        return total * factor;
    }
}