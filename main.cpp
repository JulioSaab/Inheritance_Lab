/***********************************************************************
 * File: main.cpp
 * Author: Julio Saab
 * Date:  2025-10-20
 * Purpose: Demonstrates inheritance, polymorphism, and composition.
 * Assignment: Inheritance + Composition Lab
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
        acc->deposit(500);   // Deposit
        acc->withdraw(200);  // Withdraw
        std::cout << "\n";
    }

    // Calculate interest for savings
    SavingsAccount* savings = dynamic_cast<SavingsAccount*>(accounts[1].get());
    if (savings) {
        savings->calculateInterest();
        savings->display();
    }

    // Print transaction histories
    std::cout << "\n=== TRANSACTION HISTORIES ===\n";
    for (const auto& acc : accounts) {
        acc->printHistory();
        std::cout << "\n";
    }

    return 0;
}
