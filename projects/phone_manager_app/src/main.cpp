#include <iostream>
#include <ostream>
#include <vector>

#include "phone.hpp"
#include "phone_utils.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
    std::vector<Phone> phones = {
        {"iPhone 12", 2020, 4, 64, 399.99},
        {"Samsung Galaxy S21", 2021, 8, 128, 599.99},
        {"Google Pixel 5", 2020, 8, 128, 699.99},
        {"OnePlus 9", 2021, 12, 256, 729.99},
        {"Xiaomi Mi 11", 2021, 8, 256, 749.99}
    };

    cout << "All Phones:\n";
    printAll(phones);

    cout << "\nAverage Price: " << averagePrice(phones) << " USD\n";

    cout << "\nFirst Phone:\n";
    printPhone(firstPhone(phones));

    double minPrice = 700.0;
    double maxPrice = 800.0;
    cout << "\nPhones in Price Range (" << minPrice << " - " << maxPrice << " USD):\n";
    auto filteredPhones = filterByPriceRange(phones, minPrice, maxPrice);
    printAll(filteredPhones);

    int year = 2021;
    cout << "\nNumber of Phones Released in " << year << ": " << countByYear(phones, year) << endl;

    cout << "\nPhones Sorted by Price:\n";
    auto sortedPhones = sortedByPrice(phones);
    printAll(sortedPhones);

    return 0;
}