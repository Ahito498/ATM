#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"
using namespace std;

class CheckingAccount : public Account {
public:
    CheckingAccount();
    CheckingAccount(const string& uName, const string& pin, double initial = 0.0);
    void transfer(CheckingAccount& receiver, double transactionValue);
};

#endif
