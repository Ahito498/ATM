#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() : Account() {}

SavingsAccount::SavingsAccount(const string& uName, const string& pin, double initial)
    : Account(uName, pin, initial) {}
