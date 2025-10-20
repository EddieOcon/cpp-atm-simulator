#include <iostream>
using namespace std;

// Function prototypes
void displayMenu();
double checkBalance(double balance);
void deposit(double &balance, double amount);
void withdraw(double &balance, double amount);

int main() {
    double balance = 0.0;
    int choice;
    double amount;

    cout << "==============================\n";
    cout << "   Welcome to the ATM System  \n";
    cout << "==============================\n";

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Your current balance is: $" << checkBalance(balance) << endl;
                break;

            case 2:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                deposit(balance, amount);
                break;

            case 3:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                withdraw(balance, amount);
                break;

            case 4:
                cout << "Thank you for using our ATM. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
        cout << endl;

    } while (choice != 4);

    return 0;
}

// Function definitions
void displayMenu() {
    cout << "==============================\n";
    cout << "           ATM Menu           \n";
    cout << "==============================\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Exit\n";
}

double checkBalance(double balance) {
    return balance; // Pass-by-value (returns a copy of balance)
}

void deposit(double &balance, double amount) {
    if (amount <= 0) {
        cout << " Invalid deposit amount. Please enter a positive number.\n";
    } else {
        balance += amount;
        cout << " Successfully deposited $" << amount << ". New balance: $" << balance << endl;
    }
}

void withdraw(double &balance, double amount) {
    if (amount <= 0) {
        cout << " Invalid withdrawal amount. Please enter a positive number.\n";
    } else if (amount > balance) {
        cout << " Insufficient funds. Withdrawal canceled.\n";
    } else {
        balance -= amount;
        cout << " Successfully withdrew $" << amount << ". Remaining balance: $" << balance << endl;
    }
}
