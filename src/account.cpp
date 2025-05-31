#include "../include/account.h"
#include <stdexcept>

Account::Account(const std::string& cardNum, const std::string& pinCode, double initialBalance)
    : cardNumber(cardNum), pin(pinCode), balance(initialBalance) {
    if (initialBalance < 0) {
        throw std::invalid_argument("Initial balance cannot be negative");
    }
}

bool Account::validatePin(const std::string& inputPin) const {
    return pin == inputPin;
}

bool Account::changePin(const std::string& oldPin, const std::string& newPin) {
    if (validatePin(oldPin)) {
        pin = newPin;
        return true;
    }
    return false;
}

double Account::getBalance() const {
    return balance;
}

bool Account::deposit(double amount) {
    if (amount <= 0) {
        return false;
    }
    
    balance += amount;
    addTransaction(Transaction(TransactionType::DEPOSIT, amount, balance));
    return true;
}

bool Account::withdraw(double amount) {
    if (amount <= 0 || amount > balance) {
        return false;
    }
    
    balance -= amount;
    addTransaction(Transaction(TransactionType::WITHDRAWAL, amount, balance));
    return true;
}

const std::vector<Transaction>& Account::getTransactionHistory() const {
    return transactions;
}

void Account::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
}

std::string Account::getCardNumber() const {
    return cardNumber;
} 