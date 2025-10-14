/***********************************************************************
 * File: BankAccount.cpp
 * Author: Julio Saab
 * Date: 2025-10-13
 * Purpose: Implements the BankAccount class functions.
 * Assignment: Inheritance Lab
 *
 * Logic:
 * - Implements constructors, destructor, and member functions.
 * - deposit() adds amount to balance.
 * - withdraw() subtracts amount from balance if sufficient funds exist.
 * - display() prints account details.
 ***********************************************************************/

#include "BankAccount.h"

// Constructors
BankAccount::BankAccount() : accountNumber(""), accountHolderName(""), balance(0.0) {}

BankAccount::BankAccount(const std::string& accNum, const std::string& accHolder, double bal)
        : accountNumber(accNum), accountHolderName(accHolder), balance(bal) {}

// Destructor
BankAccount::~BankAccount() {}

// Accessors
std::string BankAccount::getAccountNumber() const { return accountNumber; }
std::string BankAccount::getAccountHolderName() const { return accountHolderName; }
double BankAccount::getBalance() const { return balance; }

// Mutators
void BankAccount::setAccountNumber(const std::string& accNum) { accountNumber = accNum; }
void BankAccount::setAccountHolderName(const std::string& accHolder) { accountHolderName = accHolder; }
void BankAccount::setBalance(double bal) { balance = bal; }

// Virtual functions
void BankAccount::deposit(double amount) {
    if (amount > 0) balance += amount;
}

void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance)
        balance -= amount;
    else
        std::cout << "Insufficient funds.\n";
}

void BankAccount::display() const {
    std::cout << "Account Number: " << accountNumber
              << ", Name: " << accountHolderName
              << ", Balance: $" << balance << "\n";
}
