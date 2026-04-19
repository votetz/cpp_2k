#include "restaurant/pizza.hpp"
#include <iostream>

namespace restaurant {

std::string to_string(PizzaType type) {
    switch (type) {
        case PizzaType::MARGHERITA: return "MARGHERITA";
        case PizzaType::PEPPERONI: return "PEPPERONI";
        case PizzaType::MUSHROOM: return "MUSHROOM";
        case PizzaType::VEGETARIANA: return "VEGETARIANA";
        case PizzaType::MEXICAN: return "MEXICAN";
        default: return "UNKNOWN PIZZA_TYPE";
    }
}

std::string to_string(CrustType type) {
    switch (type) {
        case CrustType::THIN: return "THIN";
        case CrustType::CLASSIC: return "CLASSIC";
        case CrustType::THICK: return "THICK";
        case CrustType::CHEESE_STUFFED: return "CHEESE_STUFFED";
        default: return "UNKNOWN CRUST_TYPE";
    }
}

PizzaInfo::PizzaInfo(double weight, int calories, PizzaType type, CrustType crust, int diameter)
    : FoodInfo(weight, calories), pizza_type(type), pizza_crust_type(crust), diameter(diameter) {}

    void PizzaInfo::print_details(std::ostream& os) const {
        os << " | Type: " << to_string(pizza_type);
        os << " | Crust type: " << to_string(pizza_crust_type);
        os << " | Diameter: " << diameter << "SM";
    }
}
