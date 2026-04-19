#pragma once

#include <vector>
#include <memory>
#include "restaurant/menu_item.hpp"
#include "restaurant/discount.hpp"

namespace restaurant
{
    class Order
    {
    private:
        std::vector<std::shared_ptr<MenuItem>> items;
        std::shared_ptr<const DiscountCard> discount;

    public:
        void add_item(std::shared_ptr<MenuItem> item);

        void apply_discount(std::shared_ptr<const DiscountCard> discount_card);

        [[nodiscard]] double calculate_total() const;

        void print_receipt() const;
    };
}