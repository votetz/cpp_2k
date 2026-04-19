#pragma once
#include "restaurant/item_info.hpp"
#include <string>

namespace restaurant {

enum class PizzaType {
    MARGHERITA,
    PEPPERONI,
    MUSHROOM,
    VEGETARIANA,
    MEXICAN
};

enum class CrustType {
    THIN,
    CLASSIC,
    THICK,
    CHEESE_STUFFED
};

std::string to_string(PizzaType type);
std::string to_string(CrustType type);

class PizzaInfo : public FoodInfo {
private:
    PizzaType pizza_type;
    CrustType pizza_crust_type;
    int diameter;

public:
    PizzaInfo(double weight, int calories, PizzaType type, CrustType crust, int diameter);

    void print_details(std::ostream& os) const override;

        [[nodiscard]] PizzaType get_pizza_type() const
        {
            return pizza_type;
        }

        void set_pizza_type(const PizzaType pizza_type)
        {
            this->pizza_type = pizza_type;
        }

        [[nodiscard]] CrustType get_pizza_crust_type() const
        {
            return pizza_crust_type;
        }

        void set_pizza_crust_type(const CrustType pizza_crust_type)
        {
            this->pizza_crust_type = pizza_crust_type;
        }

        [[nodiscard]] int get_diameter() const
        {
            return diameter;
        }

        void set_diameter(const int diameter)
        {
            this->diameter = diameter;
        }
    };
}
