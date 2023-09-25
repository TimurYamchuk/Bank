
#ifndef BANK_H
#define BANK_H
#include <string>

using namespace std;
class BankAccount {
private:
    string accountNumber;
    string pin;
    double balance;

public:
    BankAccount(const string& accNumber, const string& pin, double initialBalance);

    bool validatePin(const string& enteredPin) const;

    bool withdraw(double amount);

    double getBalance() const;
};

#endif
