#pragma once
#include <string>
#include <memory>
#include "restaurant/category.hpp"
#include "restaurant/item_info.hpp"

namespace restaurant {

class MenuItem {
private:
    std::string name;
    double price;
    int quantity;
    std::shared_ptr<MenuCategory> category;
    std::unique_ptr<ItemInfo> info;

public:
    MenuItem(std::string name, double price, int quantity, 
             std::shared_ptr<MenuCategory> category,
             std::unique_ptr<ItemInfo> info);

    void print_full_info() const;

        [[nodiscard]] std::string get_name() const
        {
            return name;
        }

        [[nodiscard]] double get_price() const
        {
            return price;
        }

        [[nodiscard]] int get_quantity() const
        {
            return quantity;
        }

        [[nodiscard]] std::shared_ptr<MenuCategory> get_category() const
        {
            return category;
        }
    };
}
