#include <iostream>
#include <memory>

#include "product.hpp"
#include "product_catalog.hpp"


using std::cout;
using std::cin;
using std::endl;
using std::fixed;

using product_catalog::Product;
using product_catalog::ProductCatalog;

int main() {
    ProductCatalog myCatalog;

    auto p1 = std::make_shared<Product>("Apple", 50.5, 10);
    auto p2 = std::make_shared<Product>("Banana", 60.25, 4);

        myCatalog.add_product(p1);
        myCatalog.add_product(p2);

    myCatalog.show_catalog();
    return 0;
}