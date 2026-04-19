#pragma once
#include "restaurant/item_info.hpp"
#include <string>
#include <iostream>

namespace restaurant {

class DrinkInfo : public ItemInfo {
protected:
    bool is_iced;

public:
    DrinkInfo(double volume_ml, bool iced);
    virtual ~DrinkInfo() = default;

    [[nodiscard]] bool get_is_iced() const { return is_iced; }
    void set_is_iced(bool iced) { is_iced = iced; }
};

enum class CoffeeSort {
    ARABICA,
    ROBUSTA,
    AMERICANO,
    CAPPUCCINO,
    ESPRESSO,
    MOCHA,
    LATTE
};

enum class MilkType {
    WHOLE_MILK,
    REDUCED_FAT_MILK,
    LOW_FAT_MILK,
    FAT_FREE_MILK,
    NONE
};

std::string to_string(CoffeeSort sort);
std::string to_string(MilkType milk);

class CoffeeInfo : public DrinkInfo {
private:
    CoffeeSort coffee_sort;
    MilkType milk_type;

public:
    CoffeeInfo(double volume_ml, bool iced, CoffeeSort sort, MilkType milk);

    void print_details(std::ostream& os) const override;

    [[nodiscard]] CoffeeSort get_coffee_sort() const { return coffee_sort; }
    void set_coffee_sort(CoffeeSort sort) { coffee_sort = sort; }

    [[nodiscard]] MilkType get_milk_type() const { return milk_type; }
    void set_milk_type(MilkType milk) { milk_type = milk; }
};

enum class TeaType {
    GREEN,
    BLACK,
    HERBAL,
    FRUIT
};

std::string to_string(TeaType type);

class TeaInfo : public DrinkInfo {
private:
    TeaType tea_type;

public:
    TeaInfo(double volume_ml, bool iced, TeaType type);

    void print_details(std::ostream& os) const override;

    [[nodiscard]] TeaType get_tea_type() const { return tea_type; }
    void set_tea_type(TeaType type) { tea_type = type; }
};

enum class ColdDrinkType {
    LEMONADE,
    SMOOTHIE,
    SODA
};

std::string to_string(ColdDrinkType type);

class ColdDrinkInfo : public DrinkInfo {
private:
    ColdDrinkType cold_drink_type;

public:
    ColdDrinkInfo(double volume_ml, bool iced, ColdDrinkType type);

    void print_details(std::ostream& os) const override;

    [[nodiscard]] ColdDrinkType get_cold_drink_type() const { return cold_drink_type; }
    void set_cold_drink_type(ColdDrinkType type) { cold_drink_type = type; }
};

}
