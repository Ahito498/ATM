#ifndef ATM_H
#define ATM_H

#include "CheckingAccount.h"
#include "SavingsAccount.h"

#define MAX_USERS 100

class ATM {
protected:
    CheckingAccount checkingAccounts[MAX_USERS];
    int checkingAccountCount;

    SavingsAccount savingsAccounts[MAX_USERS];
    int savingsAccountCount;

    string adminPassword;

public:
    ATM();

    virtual void run() = 0;

    void addCheckingAccount(const CheckingAccount& account);
    void addSavingsAccount(const SavingsAccount& account);
};

#endif
