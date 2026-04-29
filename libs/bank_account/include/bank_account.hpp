#pragma once

#include <iostream>
#include <utility>
#include <string>

class Owner
{
private:
    std::string name;

public:
    explicit Owner(std::string name)
        : name(std::move(name))
    {}

    [[nodiscard]] std::string get_name() const
    {
        return name;
    }

    void set_name(std::string name)
    {
        this->name = std::move(name);
    }
};

class Account
{
private:
    std::string account_number;
    double balance;
    std::string details;

public:
    Account(const Owner& owner, std::string account_number = "0000", double balance = 0.0)
         : account_number(std::move(account_number)), balance(balance)
    {}

    [[nodiscard]] std::string get_account_number() const
    {
        return account_number;
    }

    void set_account_number(const std::string& account_number)
    {
        this->account_number = account_number;
    }

    [[nodiscard]] double get_balance() const
    {
        return balance;
    }

    void set_balance(double balance)
    {
        this->balance = balance;
    }

    [[nodiscard]] std::string get_details() const
    {
        return details;
    }

    void set_details(const std::string& details)
    {
        this->details = details;
    }
};

class BankAccount
{
private:
    Owner owner;
    Account account;

public:
    BankAccount(const std::string& owner_name, const std::string& acc_num, double bal)
         : owner(owner_name), account(owner, acc_num, bal)
    {}

    [[nodiscard]] Owner get_owner() const
    {
        return owner;
    }

    void set_owner(const Owner& owner)
    {
        this->owner = owner;
    }

    [[nodiscard]] Account get_account() const
    {
        return account;
    }

    void set_account(const Account& account)
    {
        this->account = account;
    }

    void printInfo() const;
    void setAccountDetails(const std::string& num, double bal);
};