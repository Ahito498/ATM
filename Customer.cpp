#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer() {}

void Customer::run() {
    string loginID, loginPIN;
    int authAttempts = 0;

    while (authAttempts < 3) {
        cout << "\n Client Login Portal\n";
        cout << "Username: ";
        cin >> loginID;
        cout << "PIN Code: ";
        cin >> loginPIN;

        bool userFound = false;

        for (int i = 0; i < checkingAccountCount; i++) {
            if (checkingAccounts[i].getUsername() == loginID &&
                checkingAccounts[i].verifyPin(loginPIN)) {

                userFound = true;
                cout << "\n Welcome, " << loginID << "!\n";

                while (true) {
                    int menuSelection;
                    cout << "\n Available Actions:\n";
                    cout << "1. Deposit Funds\n";
                    cout << "2. Withdraw Money\n";
                    cout << "3. View Account Balance\n";
                    cout << "4. Change PIN\n";
                    cout << "5. Transfer to Another User\n";
                    cout << "6. View Transactions history\n";
                    cout << "7. Log Out\n";
                    cout << "Pick an option: ";
                    cin >> menuSelection;

                    double inputValue;

                    if (menuSelection == 1) {
                        cout << "Enter amount to deposit: ";
                        cin >> inputValue;
                        checkingAccounts[i].deposit(inputValue);
                    } else if (menuSelection == 2) {
                        cout << "Enter withdrawal amount: ";
                        cin >> inputValue;
                        checkingAccounts[i].withdraw(inputValue);
                    } else if (menuSelection == 3) {
                        cout << "Your current balance is: " << checkingAccounts[i].getWallet() << " credits.\n";
                    } else if (menuSelection == 4) {
                        string newPIN;
                        cout << "Enter your new PIN: ";
                        cin >> newPIN;
                        checkingAccounts[i].resetPin(newPIN);
                    } else if (menuSelection == 5) {
                        string recipientID;
                        cout << "Enter recipient's username: ";
                        cin >> recipientID;

                        bool targetFound = false;
                        for (int j = 0; j < checkingAccountCount; j++) {
                            if (checkingAccounts[j].getUsername() == recipientID) {
                                targetFound = true;
                                cout << "Enter amount to transfer: ";
                                cin >> inputValue;
                                checkingAccounts[i].transfer(checkingAccounts[j], inputValue);
                                break;
                            }
                        }

                        if (!targetFound) {
                            cout << " Recipient not found.\n";
                        }
                    }else if (menuSelection == 6) {
                            checkingAccounts[i].showHistory();
                        }
                    else if (menuSelection == 7) {
                        cout << "Logging out... See you again!\n";
                        break;
                    } else {
                        cout << " Invalid option. Please try again.\n";
                    }
                }
                return;
            }
        }

        cout << "Login failed. Please check credentials.\n";
        authAttempts++;
    }

    cout << " Too many failed attempts. Returning to home screen...\n";
}
