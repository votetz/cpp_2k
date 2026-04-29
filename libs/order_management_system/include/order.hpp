#pragma once
#include "order_management_system.hpp"
#include "product.hpp"

class Order {
private:
    std::vector<std::unique_ptr<Product>> products;

public:
    Order() = default;

    void addProduct(std::unique_ptr<Product> product);
    void removeProduct(const std::string& name);
    void showOrder() const;
};
