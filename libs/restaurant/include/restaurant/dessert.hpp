#pragma once
#include "restaurant/item_info.hpp"
#include <string>

namespace restaurant {

enum class DessertType {
    CHEESECAKE,
    APPLE_PIE,
    TIRAMISU,
    DONUTS,
    CUPCAKE,
    BROWNIE
};

std::string to_string(DessertType type);

class DessertInfo : public FoodInfo {
private:
    DessertType dessert_type;
    bool contains_nuts;

public:
    DessertInfo(double weight, int calories, DessertType type, bool nuts);

    void print_details(std::ostream& os) const override;

        [[nodiscard]] DessertType get_dessert_type() const
        {
            return dessert_type;
        }

        [[nodiscard]] bool is_contains_nuts() const
        {
            return contains_nuts;
        }
    };
}
