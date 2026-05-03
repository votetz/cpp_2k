#pragma once

#include <vector>

#include "phone.hpp"
#include <vector>

void printPhone(const Phone& p);

void printAll(const std::vector<Phone>& phones);

double  averagePrice(const std::vector<Phone>& phones);

const Phone& firstPhone(const std::vector<Phone>& phones);


std::vector<Phone> filterByPriceRange(const std::vector<Phone>& phones,
                                      double minPrice,
                                      double maxPrice);

long countByYear(const std::vector<Phone>& phones, int year);

std::vector<Phone> sortedByPrice(const std::vector<Phone>& phones);