#include <iostream>
#include <string>
#include <map>
#include <limits>
#include "../include/account.h"

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void displayMenu() {
    std::cout << "\n=== ATM Menu ===\n";
    std::cout << "1. Check Balance\n";
    std::cout << "2. Deposit\n";
    std::cout << "3. Withdraw\n";
    std::cout << "4. Transaction History\n";
    std::cout << "5. Change PIN\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option: ";
}

void displayTransactionHistory(const Account& account) {
    std::cout << "\n=== Transaction History ===\n";
    for (const auto& transaction : account.getTransactionHistory()) {
        std::cout << transaction.getFormattedTimestamp() << " - "
                  << transaction.getTypeString() << ": $"
                  << transaction.getAmount() << " (Balance: $"
                  << transaction.getBalanceAfter() << ")\n";
    }
}

int main() {
    // Initialize a sample account (in a real system, this would be loaded from a database)
    std::map<std::string, Account> accounts;
    accounts.emplace("1234567890", Account("1234567890", "1234", 1000.0));

    std::string cardNumber, pin;
    Account* currentAccount = nullptr;

    while (true) {
        if (!currentAccount) {
            clearScreen();
            std::cout << "=== Welcome to ATM ===\n";
            std::cout << "Enter card number (or 'exit' to quit): ";
            std::cin >> cardNumber;

            if (cardNumber == "exit") {
                break;
            }

            auto it = accounts.find(cardNumber);
            if (it == accounts.end()) {
                std::cout << "Invalid card number!\n";
                continue;
            }

            std::cout << "Enter PIN: ";
            std::cin >> pin;

            if (!it->second.validatePin(pin)) {
                std::cout << "Invalid PIN!\n";
                continue;
            }

            currentAccount = &it->second;
            std::cout << "Login successful!\n";
        }

        displayMenu();
        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        double amount;
        std::string newPin, confirmPin;

        switch (choice) {
            case 1: // Check Balance
                std::cout << "Current balance: $" << currentAccount->getBalance() << "\n";
                break;

            case 2: // Deposit
                std::cout << "Enter amount to deposit: $";
                std::cin >> amount;
                if (currentAccount->deposit(amount)) {
                    std::cout << "Deposit successful!\n";
                } else {
                    std::cout << "Invalid amount!\n";
                }
                break;

            case 3: // Withdraw
                std::cout << "Enter amount to withdraw: $";
                std::cin >> amount;
                if (currentAccount->withdraw(amount)) {
                    std::cout << "Withdrawal successful!\n";
                } else {
                    std::cout << "Invalid amount or insufficient funds!\n";
                }
                break;

            case 4: // Transaction History
                displayTransactionHistory(*currentAccount);
                break;

            case 5: // Change PIN
                std::cout << "Enter current PIN: ";
                std::cin >> pin;
                std::cout << "Enter new PIN: ";
                std::cin >> newPin;
                std::cout << "Confirm new PIN: ";
                std::cin >> confirmPin;

                if (newPin != confirmPin) {
                    std::cout << "PINs do not match!\n";
                } else if (currentAccount->changePin(pin, newPin)) {
                    std::cout << "PIN changed successfully!\n";
                } else {
                    std::cout << "Invalid current PIN!\n";
                }
                break;

            case 6: // Exit
                currentAccount = nullptr;
                break;

            default:
                std::cout << "Invalid option!\n";
        }
    }

    std::cout << "Thank you for using our ATM. Goodbye!\n";
    return 0;
} 