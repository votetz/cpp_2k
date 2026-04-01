// #pragma once
//
// #include <string>
// #include <stdexcept>
//
// namespace product_catalog {
//     struct xInvalidProduct :
//     std::runtime_error {
//     xInvalidProduct(const std::string& msg) : std::runtime_error(msg) {}
//     };
//
//     class ProductValidator {
//     public:
//         static void validate(const std::string& name, int value, int amount) {
//             if (name.empty()) {
//                 throw xInvalidProduct("Error: Name cannot be empty");
//             }
//             if (value < 0) {
//                 throw xInvalidProduct("Error: Price cannot be negative");
//             }
//             if (amount < 0) {
//                 throw xInvalidProduct("Error: Amount cannot be negative");
//             }
//         }
//     };
// }