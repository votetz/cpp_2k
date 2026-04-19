#pragma once
#include <string>

namespace restaurant {

class MenuCategory {
private:
    std::string category_name;

public:
    explicit MenuCategory(std::string name);

    [[nodiscard]] std::string get_category_name() const
    {
        return category_name;
    }

    void set_category_name(const std::string& category_name)
    {
        this->category_name = category_name;
    }
};

}
