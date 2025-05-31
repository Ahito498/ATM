#include "Account.h"
#include <iostream>
using namespace std;

Account::Account() : username(""), pinCode(""), wallet(0.0),transactionCount(0) {}

Account::Account(const string& uName, const string& pin, double initial)
    : username(uName), pinCode(pin), wallet(initial) {}

void Account::deposit(double transactionValue) {
    if (transactionValue > 0) {
        wallet += transactionValue;


        // Record transaction
        if (transactionCount < 100) {
            time_t now = time(0);
            string timestamp = ctime(&now);
            timestamp.pop_back(); // remove newline
            transaction[transactionCount++] = Transaction("Deposit", transactionValue, timestamp);
        }
        cout << " Successfully deposited: " << transactionValue << endl;
    } else {
        cout << " Invalid deposit value.\n";
    }
}

void Account::withdraw(double transactionValue) {
    if (transactionValue > 0 && wallet >= transactionValue) {
        wallet -= transactionValue;

        // Record transaction
        if (transactionCount < 100) {
            time_t now = time(0);
            string timestamp = ctime(&now);
            timestamp.pop_back();
            transaction[transactionCount++] = Transaction("Withdraw", transactionValue, timestamp);
        }

        cout << " Withdrawal complete: " << transactionValue << endl;
    } else {
        cout << " Insufficient funds or invalid input.\n";
    }
}

double Account::getWallet() const {
    return wallet;
}

string Account::getUsername() const {
    return username;
}

bool Account::verifyPin(const string& pin) const {
    return pinCode == pin;
}

void Account::resetPin(const string& newPinCode) {
    pinCode = newPinCode;
    cout << " PIN updated successfully.\n";
}


    void Account::showHistory() const {
        if (transactionCount == 0) {
            cout << "No transactions available.\n";
            return;
        }

        cout << "\n Transaction History:\n";
        for (int i = 0; i < transactionCount; i++) {
            cout << "- " << transaction[i].getDetails() << endl;
        }
    }


