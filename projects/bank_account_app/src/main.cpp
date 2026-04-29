#include "bank_account.hpp"

int main() {
    BankAccount myAccount("Bogdan", "UA987654321", 2000.00);
    myAccount.setAccountDetails("UA987654321", 2000.00);
    myAccount.printInfo();

    return 0;
}