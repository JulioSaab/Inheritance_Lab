/***********************************************************************
 * File: BankAccount.h
 * Author: Julio Saab
 * Date: 2025-10-13
 * Purpose: Defines the base BankAccount class for a banking system.
 *          Includes member variables and virtual methods for deposits,
 *          withdrawals, and account information display.
 * Assignment: Inheritance Lab
 *
 * Logic:
 * - Encapsulates account data (number, holder name, balance).
 * - Provides getters and setters for member variables.
 * - Uses virtual methods to allow polymorphic behavior for derived classes.
 * - Virtual destructor ensures proper cleanup when derived objects are deleted.
 ***********************************************************************/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <iostream>

class BankAccount {
protected:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount(); // Default constructor
    BankAccount(const std::string& accNum, const std::string& accHolder, double bal); // Parameterized constructor

    virtual ~BankAccount(); // Virtual destructor

    // Accessors
    std::string getAccountNumber() const;
    std::string getAccountHolderName() const;
    double getBalance() const;

    // Mutators
    void setAccountNumber(const std::string& accNum);
    void setAccountHolderName(const std::string& accHolder);
    void setBalance(double bal);

    // Virtual functions for polymorphism
    virtual void deposit(double amount);
    virtual void withdraw(double amount);

    virtual void display() const; // Display account info
};

#endif
