#include<bits/stdc++.h>
using namespace std;

// if struct is there then why do we have classes?
// A class is basically an improved version of struct
// real world objects have:
// data + behavior
// Example: A Bank Account has:
// Data: accountNumber, balance, ownerName
// Behavior: deposit(), withdraw(), getBalance()
// A class combines both data and behavior into a single entity, allowing for better organization and encapsulation of related functionalities.
class BankAccount {
private:
    string accountNumber;
    double balance;
    string ownerName;

public:
    // Constructor
    BankAccount(string accNum, double bal, string owner) {
        accountNumber = accNum;
        balance = bal;
        ownerName = owner;
    }

    // Methods
    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account("12345", 1000.0, "Prince Maurya");
    account.deposit(500.0);
    account.withdraw(200.0);
    cout << "Current balance: " << account.getBalance() << endl;
    return 0;
}