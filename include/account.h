#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "transaction.h"

class Account {
private:
    std::string cardNumber;
    std::string pin;
    double balance;
    std::vector<Transaction> transactions;

public:
    Account(const std::string& cardNum, const std::string& pinCode, double initialBalance = 0.0);
    
    bool validatePin(const std::string& inputPin) const;
    bool changePin(const std::string& oldPin, const std::string& newPin);
    
    double getBalance() const;
    bool deposit(double amount);
    bool withdraw(double amount);
    
    const std::vector<Transaction>& getTransactionHistory() const;
    void addTransaction(const Transaction& transaction);
    
    std::string getCardNumber() const;
};

#endif // ACCOUNT_H 