#include "bank_account.hpp"

void BankAccount::printInfo() const {
    std::cout << " Owner   : " << owner.get_name() << "\n"
              << " Account : " << account.get_account_number() << "\n"
              << " Balance : " << account.get_balance() << " grn" << std::endl;
}

void BankAccount::setAccountDetails(const std::string& num, double bal) {
    account.set_account_number(num);
    account.set_balance(bal);
}