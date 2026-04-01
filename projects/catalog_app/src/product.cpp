#include <iostream>
#include "product.hpp"

namespace product_catalog {

    std::ostream& operator<<(std::ostream& os, const Product& product) {

        os << product.name << " " << product.value << " " << product.amount;
        return os;
    }
}