#include "../include/transaction.h"
#include <ctime>
#include <iomanip>
#include <sstream>

Transaction::Transaction(TransactionType transType, double transAmount, double resultingBalance)
    : type(transType), amount(transAmount), balanceAfter(resultingBalance) {
    timestamp = std::time(nullptr);
}

TransactionType Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

double Transaction::getBalanceAfter() const {
    return balanceAfter;
}

std::time_t Transaction::getTimestamp() const {
    return timestamp;
}

std::string Transaction::getTypeString() const {
    switch (type) {
        case TransactionType::DEPOSIT:
            return "Deposit";
        case TransactionType::WITHDRAWAL:
            return "Withdrawal";
        case TransactionType::BALANCE_CHECK:
            return "Balance Check";
        default:
            return "Unknown";
    }
}

std::string Transaction::getFormattedTimestamp() const {
    std::tm* timeinfo = std::localtime(&timestamp);
    std::ostringstream oss;
    oss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S");
    return oss.str();
} 