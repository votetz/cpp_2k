#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <ostream>

#include "product.hpp"
#include "product_catalog.hpp"

namespace product_catalog {
    class ProductCatalog {
        private:
            std::vector<std::shared_ptr<Product>> products;
        public:
            void add_product(const Product::Ptr& product) {
                products.push_back(product);
        }

        void show_catalog() {
            for (const Product::Ptr& product : products) {
                std::cout << *product << std::endl;
            }
        }
    };
}