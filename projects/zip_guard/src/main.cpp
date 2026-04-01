#include "../include/zip.hpp"

int main() {
    ZipCountry ukraine("Ukraine", "\\d{5}", 5);

    std::string zip;

    std::cout << "Enter ZIP code: ";
    std::cin >> zip;

    std::cout << "Country: " << ukraine.country_name() << "\n";
    std::cout << "Pattern: " << ukraine.pattern1() << "\n";
    std::cout << "Length:  " << ukraine.length1() << "\n";

    if (ukraine.validate(zip))
        std::cout << "Valid ZIP\n";
    else
        std::cout << "Invalid ZIP\n";

    return 0;
}