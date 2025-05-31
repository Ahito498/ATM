#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <Transaction.h>
#include <ctime>
using namespace std;

class Account {
protected:
    Transaction transaction[100];
    int transactionCount;
    string username;
    string pinCode;
    double wallet;

public:
    Account();
    Account(const string& uName, const string& pin, double initial = 0.0);
    virtual ~Account() {}

    virtual void deposit(double transactionValue);
    virtual void withdraw(double transactionValue);
    double getWallet() const;
    string getUsername() const;
    bool verifyPin(const string& pin) const;
    void resetPin(const string& newPinCode);
    void showHistory() const;

};

#endif
