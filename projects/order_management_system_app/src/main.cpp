#include "order_management_system.hpp"
#include "product.hpp"
#include "order.hpp"

int main()
{
    Order myOrder;

    myOrder.addProduct(std::make_unique<Product>("Laptop", 35000));
    myOrder.addProduct(std::make_unique<Product>("Mouse", 1200));
    myOrder.addProduct(std::make_unique<Product>("Keyboard", 2500));

    myOrder.showOrder();

    myOrder.removeProduct("Мишка");

    myOrder.showOrder();

    return 0;
}