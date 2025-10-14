/***********************************************************************
 * File: main.cpp
 * Author: Julio Saab
 * Date: 2025-10-13
 * Purpose: Demonstrates polymorphism and inheritance using BankAccount,
 *          CheckingAccount, and SavingsAccount classes.
 * Assignment: Inheritance Lab
 *
 * Logic:
 * - Stores accounts in a vector of unique_ptr<BankAccount>.
 * - Demonstrates polymorphic deposit and withdraw methods.
 * - Demonstrates SavingsAccount-specific calculateInterest() method.
 ***********************************************************************/

#include <iostream>
#include <vector>
#include <memory>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

int main() {
    std::vector<std::unique_ptr<BankAccount>> accounts;

    // Create accounts
    accounts.push_back(std::make_unique<CheckingAccount>("C001", "John Doe", 1000.0, 2.5));
    accounts.push_back(std::make_unique<SavingsAccount>("S001", "Jane Smith", 2000.0, 0.03));

    // Demonstrate polymorphism
    for (auto& acc : accounts) {
        acc->display();
        acc->deposit(500);   // Deposit $500
        acc->withdraw(200);  // Withdraw $200
        std::cout << "\n";
    }

    // Call calculateInterest only for SavingsAccount
    SavingsAccount* savings = dynamic_cast<SavingsAccount*>(accounts[1].get());
    if (savings) {
        savings->calculateInterest();
        savings->display();
    }

    return 0;
}
