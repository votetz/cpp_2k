#include "restaurant/drinks.hpp"
#include <iostream>

namespace restaurant {

DrinkInfo::DrinkInfo(double volume_ml, bool iced)
    : ItemInfo(volume_ml, 0), is_iced(iced) {}

std::string to_string(CoffeeSort sort) {
    switch (sort) {
        case CoffeeSort::ARABICA: return "ARABICA";
        case CoffeeSort::ROBUSTA: return "ROBUSTA";
        case CoffeeSort::AMERICANO: return "AMERICANO";
        case CoffeeSort::CAPPUCCINO: return "CAPPUCCINO";
        case CoffeeSort::ESPRESSO: return "ESPRESSO";
        case CoffeeSort::MOCHA: return "MOCHA";
        case CoffeeSort::LATTE: return "LATTE";
        default: return "UNKNOWN COFFEE_SORT";
    }
}

std::string to_string(MilkType milk) {
    switch (milk) {
        case MilkType::WHOLE_MILK: return "WHOLE_MILK";
        case MilkType::REDUCED_FAT_MILK: return "REDUCED_FAT_MILK";
        case MilkType::LOW_FAT_MILK: return "LOW_FAT_MILK";
        case MilkType::FAT_FREE_MILK: return "FAT_FREE_MILK";
        case MilkType::NONE: return "NONE";
        default: return "UNKNOWN MILK_TYPE";
    }
}

CoffeeInfo::CoffeeInfo(double volume_ml, bool iced, CoffeeSort sort, MilkType milk)
    : DrinkInfo(volume_ml, iced), coffee_sort(sort), milk_type(milk) {}

void CoffeeInfo::print_details(std::ostream& os) const {
    os << " | Coffee Sort: " << to_string(coffee_sort);
    os << " | Milk Type: " << to_string(milk_type);
}

std::string to_string(TeaType type) {
    switch (type) {
        case TeaType::GREEN: return "GREEN";
        case TeaType::BLACK: return "BLACK";
        case TeaType::HERBAL: return "HERBAL";
        case TeaType::FRUIT: return "FRUIT";
        default: return "UNKNOWN TEA_TYPE";
    }
}

TeaInfo::TeaInfo(double volume_ml, bool iced, TeaType type)
    : DrinkInfo(volume_ml, iced), tea_type(type) {}

void TeaInfo::print_details(std::ostream& os) const {
    os << " | Tea Sort: " << to_string(tea_type);
}

std::string to_string(ColdDrinkType type) {
    switch (type) {
        case ColdDrinkType::LEMONADE: return "LEMONADE";
        case ColdDrinkType::SMOOTHIE: return "SMOOTHIE";
        case ColdDrinkType::SODA: return "SODA";
        default: return "UNKNOWN COLD_DRINK_TYPE";
    }
}

ColdDrinkInfo::ColdDrinkInfo(double volume_ml, bool iced, ColdDrinkType type)
    : DrinkInfo(volume_ml, iced), cold_drink_type(type) {}

void ColdDrinkInfo::print_details(std::ostream& os) const {
    os << " | Cold Drink Type: " << to_string(cold_drink_type);
    os << "   Iced Drink " << (is_iced ? "true" : "false");
    }
}
