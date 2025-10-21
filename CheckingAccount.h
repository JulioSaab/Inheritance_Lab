/***********************************************************************
 * File: CheckingAccount.h
 * Author: Julio Saab
 * Date: 2025-10-13
 * Purpose: Defines the CheckingAccount class that inherits from BankAccount.
 *          Adds a transaction fee and overrides the withdraw method.
 ***********************************************************************/

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "BankAccount.h"

class CheckingAccount : public BankAccount {
private:
    double transactionFee;

public:
    CheckingAccount(const std::string& accNum, const std::string& accHolder, double bal, double fee);

    void withdraw(double amount) override;
    void display() const override;
};

#endif
