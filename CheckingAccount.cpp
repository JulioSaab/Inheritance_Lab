/***********************************************************************
 * File: CheckingAccount.cpp
 * Author: Julio Saab
 * Date: 2025-10-13
 * Purpose: Implements the CheckingAccount class functions.
 ***********************************************************************/

#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(const std::string& accNum, const std::string& accHolder, double bal, double fee)
        : BankAccount(accNum, accHolder, bal), transactionFee(fee) {}

void CheckingAccount::withdraw(double amount) {
    double total = amount + transactionFee;
    if (total > 0 && total <= balance) {
        balance -= total;
        recordTransaction("Withdraw (incl. fee)", total);
    } else {
        std::cout << "Insufficient funds for withdrawal + fee.\n";
    }
}

void CheckingAccount::display() const {
    BankAccount::display();
    std::cout << "Transaction Fee: $" << transactionFee << "\n";
}