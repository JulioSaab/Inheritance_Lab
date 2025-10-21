/***********************************************************************
 * File: BankAccount.h
 * Author: Julio Saab
 * Date: 2025-10-20
 * Purpose: Defines the base BankAccount class for a banking system.
 *          Includes member variables, virtual methods, and composition.
 * Assignment: Inheritance + Composition Lab
 *
 * Logic:
 * - Encapsulates account data (number, holder name, balance).
 * - Provides polymorphic deposit/withdraw/display.
 * - Maintains a transaction history using composition.
 ***********************************************************************/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <iostream>
#include <vector>
#include "Transaction.h"

class BankAccount {
protected:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

    // Composition: BankAccount "has-a" vector of Transactions
    std::vector<Transaction> transactionHistory;

public:
    BankAccount();
    BankAccount(const std::string& accNum, const std::string& accHolder, double bal);
    virtual ~BankAccount();

    // Accessors
    std::string getAccountNumber() const;
    std::string getAccountHolderName() const;
    double getBalance() const;

    // Mutators
    void setAccountNumber(const std::string& accNum);
    void setAccountHolderName(const std::string& accHolder);
    void setBalance(double bal);

    // Virtual methods
    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    virtual void display() const;

    // Composition methods
    void printHistory() const;

protected:
    void recordTransaction(const std::string& type, double amount);
};

#endif
