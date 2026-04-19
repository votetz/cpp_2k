#include "restaurant/burger.hpp"
#include <iostream>

namespace restaurant {

std::string to_string(BurgerType type) {
    switch (type) {
        case BurgerType::CHICKEN: return "CHICKEN";
        case BurgerType::CHEESE: return "CHEESE";
        case BurgerType::FARMER: return "FARMER";
        case BurgerType::CRISPY: return "CRISPY";
        case BurgerType::DELUXE: return "DELUXE";
        case BurgerType::HAMBURGER: return "HAMBURGER";
        case BurgerType::FISH: return "FISH";
        default: return "UNKNOWN BURGER_TYPE";
    }
}

std::string to_string(BurgerDoneness doneness) {
    switch (doneness) {
        case BurgerDoneness::RARE: return "RARE";
        case BurgerDoneness::MEDIUM_RARE: return "MEDIUM_RARE";
        case BurgerDoneness::MEDIUM: return "MEDIUM";
        case BurgerDoneness::WELL_DONE: return "WELL_DONE";
        default: return "UNKNOWN BURGER_DONENESS";
    }
}

BurgerInfo::BurgerInfo(double weight, int calories, BurgerType type, BurgerDoneness doneness)
    : FoodInfo(weight, calories), burger_type(type), burger_doneness(doneness) {}

void BurgerInfo::print_details(std::ostream& os) const {
    os << " | Burger type: " << to_string(burger_type);
    os << " | Burger Doneness: " << to_string(burger_doneness);
    os << " | Calories: " << calories;
    }
}
