#include "ATM.h"
using namespace std;

ATM::ATM() {
    checkingAccountCount = 0;
    savingsAccountCount = 0;
    adminPassword = "m@sterKey"; // Default admin password
}

void ATM::addCheckingAccount(const CheckingAccount& account) {
    if (checkingAccountCount < MAX_USERS) {
        checkingAccounts[checkingAccountCount++] = account;
    }
}

void ATM::addSavingsAccount(const SavingsAccount& account) {
    if (savingsAccountCount < MAX_USERS) {
        savingsAccounts[savingsAccountCount++] = account;
    }
}
