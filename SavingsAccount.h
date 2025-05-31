#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"
using namespace std;

class SavingsAccount : public Account {
public:
    SavingsAccount();
    SavingsAccount(const string& uName, const string& pin, double initial = 0.0);
};

#endif
