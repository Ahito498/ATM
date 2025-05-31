#include "CheckingAccount.h"
#include <iostream>
using namespace std;

CheckingAccount::CheckingAccount() : Account() {}

CheckingAccount::CheckingAccount(const string& uName, const string& pin, double initial)
    : Account(uName, pin, initial) {}

void CheckingAccount::transfer(CheckingAccount& receiver, double transactionValue) {
    if (transactionValue > 0 && wallet >= transactionValue) {
        wallet -= transactionValue;
        receiver.deposit(transactionValue);
        cout << " Transferred " << transactionValue << " to " << receiver.getUsername() << endl;
    } else {
        cout << " Transfer failed due to insufficient funds or invalid amount.\n";
    }
}
