#include "order.hpp"
#include <algorithm>
#include <memory>
#include <string>
#include <iostream>


void Order::addProduct(std::unique_ptr<Product> product) {
    if (product) {
        std::cout << " Added: " << product->name << " (" << product->price << " UAH)\n";
        products.push_back(std::move(product));
    }
}

void Order::removeProduct(const std::string& name) {
    auto it = std::remove_if(products.begin(), products.end(),
        [&name](const std::unique_ptr<Product>& p) {
            return p->name == name;
        });

    if (it != products.end()) {
        products.erase(it, products.end());
        std::cout << "Product \"" << name << "\" successfully removed from the order.\n";
    } else {
        std::cout << "Product \"" << name << "\" not found.\n";
    }
}

void Order::showOrder() const {
    std::cout << "\n Order Details \n";
    double total = 0;
    for (const auto& item : products) {
        std::cout << "- " << item->name << ": " << item->price << " UAH\n";
        total += item->price;
    }
    std::cout << " Total Amount: " << total << " USD\n";
}