#include <iostream>
#include "Admin.h"
#include "Customer.h"
using namespace std;

int main() {
    Admin controlUnit;
    Customer clientModule;

    controlUnit.setCustomerSystem(&clientModule);

    CheckingAccount builtInUser("Shahien", "123", 800.0);
    controlUnit.addCheckingAccount(builtInUser);
    clientModule.addCheckingAccount(builtInUser);

    int userOption = 0;

    cout << "===============================\n";
    cout << "   Welcome to CashX System \n";
    cout << "===============================\n";

    while (true) {
        cout << "\nMain Control:\n";
        cout << "[1] Manager Access\n";
        cout << "[2] Client Login\n";
        cout << "[3] Terminate Session\n";
        cout << "Choose your action: ";
        cin >> userOption;

        if (userOption == 1) {
            controlUnit.run();
        } else if (userOption == 2) {
            clientModule.run();
        } else if (userOption == 3) {
            cout << " Exiting system. Take care!\n";
            break;
        } else {
            cout << " Invalid input. Try again.\n";
        }
    }

    return 0;
}
