/***********************************************************************
 * File: CheckingAccount.cpp
 * Author: Julio Saab
 * Date: 2025-10-13
 * Purpose: Implements the CheckingAccount class functions.
 * Assignment: Inheritance Lab
 *
 * Logic:
 * - withdraw() deducts amount + transaction fee from balance.
 * - display() prints account info along with the transaction fee.
 ***********************************************************************/

#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(const std::string& accNum, const std::string& accHolder, double bal, double fee)
        : BankAccount(accNum, accHolder, bal), transactionFee(fee) {}

void CheckingAccount::withdraw(double amount) {
    double totalAmount = amount + transactionFee;
    if (totalAmount <= balance) {
        balance -= totalAmount;
        std::cout << "Withdrawal of $" << amount << " plus transaction fee of $"
                  << transactionFee << " successful.\n";
    } else {
        std::cout << "Insufficient funds including transaction fee.\n";
    }
}

void CheckingAccount::display() const {
    BankAccount::display();
    std::cout << "Transaction Fee: $" << transactionFee << "\n";
}