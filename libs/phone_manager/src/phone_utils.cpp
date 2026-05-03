#include "phone_utils.hpp"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <stdexcept>

void printPhone(const Phone& p) {
    std::cout << std::left
              << std::setw(22) << p.model
              << "  year: "     << std::setw(6) << p.year
              << "  RAM: "     << std::setw(4) << p.ram     << " GB"
              << "  Storage: " << std::setw(5) << p.storage << " GB"
              << "  Price: "    << std::fixed   << std::setprecision(0)
              << p.price << " USD\n";
}

void printAll(const std::vector<Phone>& phones) {
    for (const auto& p : phones) printPhone(p);
}

double averagePrice(const std::vector<Phone>& phones) {
    if (phones.empty()) return 0.0;

    double total = std::accumulate(
        phones.begin(), phones.end(), 0.0,
        [](double sum, const Phone& p) { return sum + p.price; }
    );
    return total / static_cast<double>(phones.size());
}

const Phone& firstPhone(const std::vector<Phone>& phones) {
    if (phones.empty())
        throw std::runtime_error("Vector is empty");
    return phones.front();
}
std::vector<Phone> filterByPriceRange(const std::vector<Phone>& phones,
                                      double minPrice,
                                      double maxPrice) {
    std::vector<Phone> result;
    std::copy_if(
        phones.begin(), phones.end(),
        std::back_inserter(result),
        [minPrice, maxPrice](const Phone& p) {
            return p.price >= minPrice && p.price <= maxPrice;
        }
    );
    return result;
}

long countByYear(const std::vector<Phone>& phones, int year) {
    return std::count_if(
        phones.begin(), phones.end(),
        [year](const Phone& p) { return p.year == year; }
    );
}

std::vector<Phone> sortedByPrice(const std::vector<Phone>& phones) {
    std::vector<Phone> sorted = phones;
    std::sort(
        sorted.begin(), sorted.end(),
        [](const Phone& a, const Phone& b) { return a.price < b.price; }
    );
    return sorted;
}
