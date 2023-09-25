#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string pin;
    double balance;

public:
    BankAccount(double initialBalance)
        :balance(initialBalance) {}

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const {
        return balance;
    }

    string toString() const {
        string accountInfo = "Account Number: " + accountNumber + "\n";
        accountInfo += "Balance: $" + to_string(balance) + " USD\n";
        return accountInfo;
    }
};
