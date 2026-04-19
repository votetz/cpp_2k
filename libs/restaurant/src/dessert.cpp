#include "restaurant/dessert.hpp"
#include <iostream>

namespace restaurant {

std::string to_string(DessertType type) {
    switch (type) {
        case DessertType::CHEESECAKE: return "CHEESECAKE";
        case DessertType::APPLE_PIE: return "APPLE_PIE";
        case DessertType::TIRAMISU: return "TIRAMISU";
        case DessertType::DONUTS: return "DONUTS";
        case DessertType::CUPCAKE: return "CUPCAKE";
        case DessertType::BROWNIE: return "BROWNIE";
        default: return "UNKNOWN DESSERT_TYPE";
    }
}

DessertInfo::DessertInfo(double weight, int calories, DessertType type, bool nuts)
    : FoodInfo(weight, calories), dessert_type(type), contains_nuts(nuts) {}

    void DessertInfo::print_details(std::ostream& os) const {
        os << " | Dessert type: " << to_string(dessert_type);
        os << " | Calories: " << calories;
        if (contains_nuts) {
            os << " Caution! Nuts for dessert ";
        }
    }
}
