#pragma once
#include <string>
#include <iostream>

class Product {
public:
    std::string name;
    double price;

public:
    Product(std::string name, double price);
    ~Product();

    [[nodiscard]] std::string get_name() const
    {
        return name;
    }

    void set_name(const std::string& name)
    {
        this->name = name;
    }

    [[nodiscard]] double get_price() const
    {
        return price;
    }

    void set_price(const double price)
    {
        this->price = price;
    }
};