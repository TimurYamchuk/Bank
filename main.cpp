#include <iostream>
#include <string>
#include <ctime>
#include "bank.h"

using namespace std;

int main() {
    srand(time(0));

    double initialBalance = rand() % 9000 + 1000;
    string accountNumber = "12345";  
    string pin = "1234";             

    BankAccount account(accountNumber, pin, initialBalance);

    cout << "Welcome to the ATM!" << endl;

    string enteredPin;
    cout << "Please enter your PIN: ";
    cin >> enteredPin;

    if (!account.validatePin(enteredPin)) {
        cout << "Invalid PIN. Access denied." << endl;
        return 1;  // Exit with an error code
    }

    cout << "Login successful!" << endl;

    while (true) {
        cout << "Select an operation:" << endl;
        cout << "1. Check balance" << endl;
        cout << "2. Withdraw money" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Your balance: " << account.getBalance() << " USD." << endl;
                break;

            case 2:
                cout << "Select the sum to withdraw:" << endl;
                cout << "1. $100" << endl;
                cout << "2. $200" << endl;
                cout << "3. $500" << endl;
                cout << "4. $1000" << endl;

                int withdrawChoice;
                cin >> withdrawChoice;

                int withdraw;

                switch (withdrawChoice) {
                    case 1:
                        withdraw = 100;
                        break;
                    case 2:
                        withdraw = 200;
                        break;
                    case 3:
                        withdraw = 500;
                        break;
                    case 4:
                        withdraw = 1000;
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        continue;
                }

                if (account.withdraw(withdraw)) {
                    cout << "Withdrawn: $" << withdraw << " USD." << endl;
                    cout << "Account Summary:\n" << account.toString() << endl;
                } else {
                    cout << "Insufficient funds." << endl;
                }
                break;

            case 3:
                cout << "Exiting the ATM. Thank you for using!" << endl;
                return 0;
            default:
                cout << "Invalid command. Please try again." << endl;
        }
    }

    return 0;
}
