#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

enum class TransactionType {
    DEPOSIT,
    WITHDRAWAL,
    BALANCE_CHECK
};

class Transaction {
private:
    TransactionType type;
    double amount;
    double balanceAfter;
    std::time_t timestamp;

public:
    Transaction(TransactionType transType, double transAmount, double resultingBalance);
    
    TransactionType getType() const;
    double getAmount() const;
    double getBalanceAfter() const;
    std::time_t getTimestamp() const;
    
    std::string getTypeString() const;
    std::string getFormattedTimestamp() const;
};

#endif // TRANSACTION_H 