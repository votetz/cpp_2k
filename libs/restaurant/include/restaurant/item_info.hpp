#pragma once
#include <iostream>

namespace restaurant {

class ItemInfo {
protected:
    double value;
    int calories;

public:
    ItemInfo(double value, int calories);
    virtual ~ItemInfo() = default;

    virtual void print_details(std::ostream& os) const = 0;

    [[nodiscard]] double get_value() const
    {
        return value;
    }

    void set_value(double value)
    {
        this->value = value;
    }

    [[nodiscard]] int get_calories() const
    {
        return calories;
    }

    void set_calories(int calories)
    {
        this->calories = calories;
    }
};

class FoodInfo : public ItemInfo {
public:
    using ItemInfo::ItemInfo;
    };
}