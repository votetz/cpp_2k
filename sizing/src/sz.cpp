#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::left << std::setw(20) << "Data Type" << "Size (in bytes)" << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    std::cout << std::setw(20) << "signed char" << sizeof(signed char) << std::endl;
    std::cout << std::setw(20) << "signed short" << sizeof(signed short) << std::endl;
    std::cout << std::setw(20) << "signed int" << sizeof(signed int) << std::endl;
    std::cout << std::setw(20) << "signed long" << sizeof(signed long) << std::endl;
    std::cout << std::setw(20) << "signed long long" << sizeof(signed long long) << std::endl;

    return 0;
}