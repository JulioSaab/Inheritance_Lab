/***********************************************************************
 * File: SavingsAccount.h
 * Author: Julio Saab
 * Date: 2025-10-13
 * Purpose: Defines the SavingsAccount class that inherits from BankAccount.
 *          Adds interest calculation functionality.
 * Assignment: Inheritance Lab
 *
 * Logic:
 * - Inherits all attributes of BankAccount.
 * - interestRate applied to balance for interest calculation.
 * - calculateInterest() adds interest to the account balance.
 ***********************************************************************/

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "BankAccount.h"

class SavingsAccount : public BankAccount {
private:
    double interestRate; // in decimal, e.g., 0.05 = 5%

public:
    SavingsAccount(const std::string& accNum, const std::string& accHolder, double bal, double rate);

    void calculateInterest(); // Add interest to balance
    void display() const override;
};

#endif
