#include "product.hpp"

Product::Product(std::string name, double price)
    : name(std::move(name)), price(price) {}

Product::~Product() {
    std::cout << "Product \"" << name << "\" removed from memory.\n";
}