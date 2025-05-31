#include "Admin.h"
#include <iostream>
using namespace std;

Admin::Admin() {
    adminPassword = "m@sterKey";
    customerSystem = nullptr;
}

void Admin::setCustomerSystem(Customer* clientRef) {
    customerSystem = clientRef;
}

void Admin::run() {
    string inputKey;
    int tries = 0;

    while (tries < 3) {
        cout << "\n Enter Manager PIN: ";
        cin >> inputKey;

        if (inputKey == adminPassword) {
            int managerOption = 0;
            while (managerOption != 3) {
                cout << "\n[Manager Tools]\n";
                cout << "1. Create New User\n";
                cout << "2. Remove Existing User\n";
                cout << "3. Exit to Main\n";
                cout << "Choose task: ";
                cin >> managerOption;

                switch (managerOption) {
                    case 1: addAccount(); break;
                    case 2: deleteAccount(); break;
                    case 3: cout << "Returning to Main Interface...\n"; break;
                    default: cout << " Invalid choice.\n"; break;
                }
            }
            return;
        } else {
            cout << " Incorrect PIN. Access denied.\n";
            tries++;
        }
    }

    cout << " Too many failed attempts. Logging out...\n";
}

void Admin::addAccount() {
    if (customerSystem == nullptr) {
        cout << "System error: No linked customer module.\n";
        return;
    }

    string newUserID, newPIN;
    int typeChoice;
    cout << "\n--- Create Account ---\n";
    cout << "Select type:\n1. Primary Account\n2. Reserve Account\n>> ";
    cin >> typeChoice;

    while (typeChoice != 1 && typeChoice != 2) {
        cout <<"Invalid Choice.\n Enter a valid one: ";
        cin >> typeChoice;
    }

    cout << "Assign Username: ";
    cin >> newUserID;
    cout << "Set Access PIN: ";
    cin >> newPIN;

    if (typeChoice == 1) {
        CheckingAccount newClient(newUserID, newPIN);
        addCheckingAccount(newClient);
        customerSystem->addCheckingAccount(newClient);
        cout << " Checking account created.\n";
    } else if (typeChoice == 2) {
        SavingsAccount newClient(newUserID, newPIN);
        addSavingsAccount(newClient);
        customerSystem->addSavingsAccount(newClient);
        cout << " Savings account created.\n";
    } else {
        cout << " Invalid type selection.\n";
    }
}

void Admin::deleteAccount() {
    if (customerSystem == nullptr) {
        cout << "Error: Cannot access customer data.\n";
        return;
    }

    cout << "\n Registered Accounts:\n";
    for (int i = 0; i < checkingAccountCount; i++) {
        cout << " " << checkingAccounts[i].getUsername() << " (Primary)\n";
    }
    for (int i = 0; i < savingsAccountCount; i++) {
        cout << " " << savingsAccounts[i].getUsername() << " (Reserve)\n";
    }

    cout << "Enter username to remove: ";
    string targetID;
    cin >> targetID;

    bool removed = false;

    for (int i = 0; i < checkingAccountCount; i++) {
        if (checkingAccounts[i].getUsername() == targetID) {
            for (int j = i; j < checkingAccountCount - 1; j++) {
                checkingAccounts[j] = checkingAccounts[j + 1];
            }
            checkingAccountCount--;
            cout << " Primary account removed.\n";
            removed = true;
            break;
        }
    }

    if (!removed) {
        for (int i = 0; i < savingsAccountCount; i++) {
            if (savingsAccounts[i].getUsername() == targetID) {
                for (int j = i; j < savingsAccountCount - 1; j++) {
                    savingsAccounts[j] = savingsAccounts[j + 1];
                }
                savingsAccountCount--;
                cout << " Reserve account removed.\n";
                removed = true;
                break;
            }
        }
    }

    if (!removed) {
        cout << " No such user found.\n";
    }
}
