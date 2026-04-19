#include "restaurant/order.hpp"
#include <iostream>
#include <iomanip>

namespace restaurant
{
    void Order::add_item(std::shared_ptr<MenuItem> item)
    {
        if (item)
        {
            items.push_back(std::move(item));
        }
    }

    void Order::apply_discount(std::shared_ptr<const DiscountCard> discount_card)
    {
        discount = std::move(discount_card);
    }

    double Order::calculate_total() const
    {
        double total = 0.0;
        for (const auto& item : items)
        {
            total += item->get_price() * item->get_quantity();
        }
        
        if (discount)
        {
            total = discount->apply(total);
        }
        
        return total;
    }

    void Order::print_receipt() const
    {
        std::cout << "\nRECEIPT " << std::endl;
        double subtotal = 0.0;
        for (const auto& item : items)
        {
            item->print_full_info();
            subtotal += item->get_price() * item->get_quantity();
        }

        std::cout << "Subtotal: " << std::fixed << std::setprecision(2) << subtotal << std::endl;
        
        if (discount)
        {
            double total = discount->apply(subtotal);
            std::cout << "Discount applied!" << std::endl;
            std::cout << "TOTAL: " << total << std::endl;
        }
        else
        {
            std::cout << "TOTAL: " << subtotal << std::endl;
        }
    }
}