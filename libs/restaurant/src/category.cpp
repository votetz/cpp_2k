#include "restaurant/category.hpp"
#include <utility>

namespace restaurant {

MenuCategory::MenuCategory(std::string name)
    : category_name(std::move(name)) {}

}
