/***********************************************************************
 * File: BankAccount.cpp
 * Author: Julio Saab
 * Date: 2025-10-20
 * Purpose: Implements the BankAccount class functions and transaction history.
 * Assignment: Inheritance + Composition Lab
 ***********************************************************************/

#include "BankAccount.h"
#include <ctime>
#include <iomanip>

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

// Virtual methods
void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        recordTransaction("Deposit", amount);
    }
}

void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        recordTransaction("Withdraw", amount);
    } else {
        std::cout << "Insufficient funds.\n";
    }
}

void BankAccount::display() const {
    std::cout << "Account Number: " << accountNumber
              << ", Name: " << accountHolderName
              << ", Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
}

// Composition methods
void BankAccount::recordTransaction(const std::string& type, double amount) {
    // Generate current timestamp
    time_t now = time(nullptr);
    std::string timestamp = ctime(&now);
    timestamp.pop_back(); // remove newline
    transactionHistory.emplace_back(type, amount, timestamp);
}

void BankAccount::printHistory() const {
    std::cout << "\nTransaction History for Account " << accountNumber << ":\n";
    if (transactionHistory.empty()) {
        std::cout << "  No transactions recorded.\n";
        return;
    }
    for (const auto& t : transactionHistory) {
        std::cout << "  [" << t.timestamp << "] " << t.type << " of $" << std::fixed
                  << std::setprecision(2) << t.amount << "\n";
    }
}
