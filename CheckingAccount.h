/***********************************************************************
 * File: CheckingAccount.h
 * Author: Julio Saab
 * Date: 2025-10-13
 * Purpose: Defines the CheckingAccount class that inherits from BankAccount.
 *          Adds a transaction fee and overrides the withdraw method.
 * Assignment: Inheritance Lab
 *
 * Logic:
 * - Inherits all attributes of BankAccount.
 * - transactionFee applied on every withdrawal.
 * - Overrides withdraw() to deduct both amount and fee.
 ***********************************************************************/

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "BankAccount.h"

class CheckingAccount : public BankAccount {
private:
    double transactionFee;

public:
    CheckingAccount(const std::string& accNum, const std::string& accHolder, double bal, double fee);

    void withdraw(double amount) override; // Override to include transaction fee
    void display() const override;
};

#endif
