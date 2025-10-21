/***********************************************************************
 * File: Transaction.h
 * Author: Julio Saab
 * Date: 2025-10-20
 * Purpose: Defines the Transaction class used for BankAccount composition.
 * Assignment: Inheritance + Composition Lab
 *
 * Logic:
 * - Represents a single transaction record.
 * - Stores transaction type, amount, and timestamp.
 * - Used by BankAccount as part of a composition relationship.
 ***********************************************************************/

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
public:
    std::string type;       // e.g. "Deposit", "Withdraw", "Interest Added"
    double amount;          // Amount of money involved
    std::string timestamp;  // Time when the transaction occurred

    // Constructor
    Transaction(const std::string& type, double amount, const std::string& timestamp)
            : type(type), amount(amount), timestamp(timestamp) {}

    // Default constructor (for vector use)
    Transaction() : type(""), amount(0.0), timestamp("") {}
};

#endif
