/***********************************************************************
 * File: SavingsAccount.cpp
 * Author: Julio Saab
 * Date: 2025-10-13
 * Purpose: Implements the SavingsAccount class functions.
 ***********************************************************************/

#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(const std::string& accNum, const std::string& accHolder, double bal, double rate)
        : BankAccount(accNum, accHolder, bal), interestRate(rate) {}

void SavingsAccount::calculateInterest() {
    double interest = balance * interestRate;
    balance += interest;
    recordTransaction("Interest Added", interest);
    std::cout << "Interest of $" << interest << " added.\n";
}

void SavingsAccount::display() const {
    BankAccount::display();
    std::cout << "Interest Rate: " << interestRate * 100 << "%\n";
}
