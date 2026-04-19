#include <iostream>
#include <memory>
#include <vector>

#include "app.hpp"

using namespace restaurant;

int main()
{
    auto main_dishes = std::make_shared<MenuCategory>("Main Dishes");
    auto desserts = std::make_shared<MenuCategory>("Desserts");
    auto drinks = std::make_shared<MenuCategory>("Drinks");

    auto pizza_info = std::make_unique<PizzaInfo>(450.0, 850, PizzaType::PEPPERONI, CrustType::THIN, 30);
    auto pepperoni_pizza = std::make_shared<MenuItem>("Pepperoni Pizza", 250.0, 1, main_dishes, std::move(pizza_info));

    auto burger_info = std::make_unique<BurgerInfo>(350.0, 600, BurgerType::CHEESE, BurgerDoneness::MEDIUM);
    auto cheese_burger = std::make_shared<MenuItem>("Cheese Burger", 180.0, 2, main_dishes, std::move(burger_info));

    auto salad_info = std::make_unique<SaladInfo>(250.0, 150, SaladType::CEASAR, SaladDressing::OLIVE_OIL, false);
    auto ceasar_salad = std::make_shared<MenuItem>("Ceasar Salad", 120.0, 1, main_dishes, std::move(salad_info));

    auto coffee_info = std::make_unique<CoffeeInfo>(250.0, false, CoffeeSort::ARABICA, MilkType::WHOLE_MILK);
    auto latte = std::make_shared<MenuItem>("Latte", 65.0, 1, drinks, std::move(coffee_info));

    Order my_order;
    my_order.add_item(pepperoni_pizza);
    my_order.add_item(cheese_burger);
    my_order.add_item(ceasar_salad);
    my_order.add_item(latte);

    std::cout << "\nOrder without discount " << std::endl;
    my_order.print_receipt();

    auto discount = std::make_shared<PercentDiscount>(15.0);
    my_order.apply_discount(discount);

    std::cout << "\nFinal Order with 15% discount " << std::endl;
    my_order.print_receipt();

    return 0;
}
