#pragma once

#include <string>
#include <memory>

namespace product_catalog {

    class Product{
    private:
        std::string name;
        double value;
        int amount;

    public:
        using Ptr = std::shared_ptr<Product>;

        Product() = default;

        Product(const std::string& name,
                const double& value,
                const int& amount)
            : name{name},
            value{value},
            amount{amount} {
        }

        [[nodiscard]] std::string get_name() const {
            return name;
        }

        void set_name(const std::string &name) {
            this->name = name;
        }

        [[nodiscard]] double get_value() const {
            return value;
        }

        void set_value(const double value) {
            this->value = value;
        }

        [[nodiscard]] int get_amount() const {
            return amount;
        }

        void set_amount(const int amount) {
            this->amount = amount;
        }


        friend std::ostream& operator<<(std::ostream& os, const Product& p);
    };


    std::ostream& operator<<(std::ostream& os, const Product& p);
}
