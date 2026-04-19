#include "restaurant/salad.hpp"
#include <iostream>

namespace restaurant {

std::string to_string(SaladType type) {
    switch (type) {
        case SaladType::CEASAR: return "CEASAR";
        case SaladType::CAPRESE: return "CAPRESE";
        case SaladType::ITALIAN: return "ITALIAN";
        case SaladType::CHEF: return "CHEF";
        case SaladType::ISRAELI: return "ISRAELI";
        case SaladType::PANZANELLA: return "PANZANELLA";
        case SaladType::SOUTHWEST: return "SOUTHWEST";
        default: return "UNKNOWN SALAD_TYPE";
    }
}

std::string to_string(SaladDressing dressing) {
    switch (dressing) {
        case SaladDressing::OLIVE_OIL: return "OLIVE_OIL";
        case SaladDressing::MAYONNAISE: return "MAYONNAISE";
        default: return "UNKNOWN SALAD_DRESSING";
    }
}

SaladInfo::SaladInfo(double weight, int calories, SaladType type, SaladDressing dressing, bool vegan)
    : FoodInfo(weight, calories), salad_type(type), salad_dressing(dressing), is_vegan(vegan) {}

    void SaladInfo::print_details(std::ostream& os) const {
        os << " | Salad type: " << to_string(salad_type);
        os << " | Salad Dressing: " << to_string(salad_dressing);
        os << " | is_vegan: " << (is_vegan ? "true" : "false");
    }
}