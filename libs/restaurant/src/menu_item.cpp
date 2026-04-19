#include "restaurant/menu_item.hpp"
#include <iostream>
#include <utility>

namespace restaurant {

MenuItem::MenuItem(std::string name, double price, int quantity, 
                   std::shared_ptr<MenuCategory> category,
                   std::unique_ptr<ItemInfo> info)
    : name(std::move(name)), price(price), quantity(quantity),
      category(std::move(category)), info(std::move(info)) {}

void MenuItem::print_full_info() const {
    std::cout << name << " | Price: " << price << " | Qty: " << quantity;
    if (info) {
        info->print_details(std::cout);
    }
    std::cout << std::endl;
    }
}