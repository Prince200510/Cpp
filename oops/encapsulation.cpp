#include<bits/stdc++.h>
using namespace std;

// Encapsulation is a fundamental concept in object-oriented programming (OOP) that refers to the bundling of data (attributes) and methods (functions) that operate on that data into a single unit, typically a class. It restricts direct access to some of the object's components, which can prevent the accidental modification of data and promote data integrity. Encapsulation is achieved through access specifiers (public, private, protected) that control the visibility of class members.
// Data + Methods
// Inside one unit and hiding internal details.
// Three access specifiers: private, public, protected
// Encapsulation hides complexity, presenting users with only what they need to know. 
// Bad approach:
class BankAccount {
    public:
    double balance;
}
// Anyone can do: acc.balance = -1000; // Invalid operation, but allowed due to public access
// Not safe.

// Good approach:
class BankAccount2 {
    private:
    double balance;

    public:
    // Constructor
    BankAccount2(double initialBalance) {
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0; // Set to 0 if initial balance is negative
        }
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
    }

    // Method to get the current balance
    double getBalance() const {
        return balance;
    }
};
int main() {
    BankAccount2 acc(1000.0); // Create a bank account with an initial balance of 1000.0
    acc.deposit(500.0);       // Deposit 500.0
    acc.withdraw(200.0);      // Withdraw 200.0
    cout << "Current balance: " << acc.getBalance() << endl; // Print the current balance
    return 0;
}