#pragma once
#include "restaurant/item_info.hpp"
#include <string>

namespace restaurant {

enum class BurgerType {
    CHICKEN,
    CHEESE,
    FARMER,
    CRISPY,
    DELUXE,
    HAMBURGER,
    FISH
};

enum class BurgerDoneness {
    RARE,
    MEDIUM_RARE,
    MEDIUM,
    WELL_DONE
};

std::string to_string(BurgerType type);
std::string to_string(BurgerDoneness doneness);

class BurgerInfo : public FoodInfo {
private:
    BurgerType burger_type;
    BurgerDoneness burger_doneness;

public:
    BurgerInfo(double weight, int calories, BurgerType type, BurgerDoneness doneness);

    void print_details(std::ostream& os) const override;

        [[nodiscard]] BurgerType get_burger_type() const
        {
            return burger_type;
        }

        void set_burger_type(BurgerType burger_type)
        {
            this->burger_type = burger_type;
        }

        [[nodiscard]] BurgerDoneness get_burger_doneness() const
        {
            return burger_doneness;
        }

        void set_burger_doneness(BurgerDoneness burger_doneness)
        {
            this->burger_doneness = burger_doneness;
        }
    };
}
