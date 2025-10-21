/***********************************************************************
 * File: SavingsAccount.h
 * Author: Julio Saab
 * Date: 2025-10-13
 * Purpose: Defines the SavingsAccount class that inherits from BankAccount.
 *          Adds interest calculation functionality.
 ***********************************************************************/

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "BankAccount.h"

class SavingsAccount : public BankAccount {
private:
    double interestRate; // e.g., 0.05 = 5%

public:
    SavingsAccount(const std::string& accNum, const std::string& accHolder, double bal, double rate);

    void calculateInterest();
    void display() const override;
};

#endif
