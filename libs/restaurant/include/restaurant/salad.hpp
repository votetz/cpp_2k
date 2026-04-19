#pragma once
#include "restaurant/item_info.hpp"
#include <string>

namespace restaurant {

enum class SaladType {
    CEASAR,
    CAPRESE,
    ITALIAN,
    CHEF,
    ISRAELI,
    PANZANELLA,
    SOUTHWEST
};

enum class SaladDressing {
    OLIVE_OIL,
    MAYONNAISE
};

std::string to_string(SaladType type);
std::string to_string(SaladDressing dressing);

class SaladInfo : public FoodInfo {
private:
    SaladType salad_type;
    SaladDressing salad_dressing;
    bool is_vegan;

public:
    SaladInfo(double weight, int calories, SaladType type, SaladDressing dressing, bool vegan);

    void print_details(std::ostream& os) const override;

        [[nodiscard]] SaladType get_salad_type() const
        {
            return salad_type;
        }

        void set_salad_type(const SaladType salad_type)
        {
            this->salad_type = salad_type;
        }

        [[nodiscard]] SaladDressing get_salad_dressing() const
        {
            return salad_dressing;
        }

        void set_salad_dressing(const SaladDressing salad_dressing)
        {
            this->salad_dressing = salad_dressing;
        }

        [[nodiscard]] bool is_is_vegan() const
        {
            return is_vegan;
        }

        void set_is_vegan(const bool is_vegan)
        {
            this->is_vegan = is_vegan;
        }
    };
}
