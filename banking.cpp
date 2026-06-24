#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct User {
    string name;
    string lastName;
    int pin;
    int accountNumber;
    int balance;
};


void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void signUp(vector<User>& users) {
    User newUser;
    cout << "Enter your first name: ";
    cin >> newUser.name;
    cout << "Enter your last name: ";
    cin >> newUser.lastName;

    cout << "Enter your PIN: ";
    while (!(cin >> newUser.pin)) {
        cout << "Invalid PIN. Please enter numbers only: ";
        clearInput();
    }

    newUser.accountNumber = 1000 + users.size();
    newUser.balance = 0;

    users.push_back(newUser);
    cout << "Account created successfully! Your account number is: " << newUser.accountNumber << "\n";
}

void deposit(User& user) {
    int amount;
    cout << "Enter deposit amount: ";
    while (!(cin >> amount)) {
        cout << "Invalid amount. Please enter numbers only: ";
        clearInput();
    }
    user.balance = user.balance + amount;
    cout << "Balance after deposit: R " << user.balance << "\n";
}

void withdraw(User& user) {
    int amount;
    cout << "Enter withdrawal amount: ";
    while (!(cin >> amount)) {
        cout << "Invalid amount. Please enter numbers only: ";
        clearInput();
    }
    if (amount > user.balance) {
        cout << "Insufficient funds\n";
    } else {
        user.balance = user.balance - amount;
        cout << "Balance after withdrawal: R " << user.balance << "\n";
    }
}

void viewBalance(User& user) {
    cout << "Current balance: R " << user.balance << "\n";
}

void userMenu(User& user) {
    int choice;

    do {
        cout << "--------------------------------------\n";
        cout << "Welcome, " << user.name << "!\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. View balance\n";
        cout << "4. Log out\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            clearInput();
            continue;
        }

        switch (choice) {
            case 1:
                deposit(user);
                break;
            case 2:
                withdraw(user);
                break;
            case 3:
                viewBalance(user);
                break;
            case 4:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }

    } while (choice != 4);
}

void signIn(vector<User>& users) {
    string name;
    int pin;

    cout << "Enter your first name: ";
    cin >> name;

    cout << "Enter your PIN: ";
    while (!(cin >> pin)) {
        cout << "Invalid PIN. Please enter numbers only: ";
        clearInput();
    }

    for (int i = 0; i < users.size(); i++) {
        if (users[i].name == name && users[i].pin == pin) {
            cout << "Welcome back, " << users[i].name << "!\n";
            userMenu(users[i]);
            return;
        }
    }

    cout << "Incorrect name or PIN.\n";
}

int main() {
    vector<User> users = {
        {"Mike", "Smith", 2003, 1001, 5000},
        {"John", "Doe", 2000, 1002, 5000},
        {"Sarah", "Johnson", 1985, 1003, 5000},
        {"Anna", "Williams", 1200, 1004, 5000},
        {"Tom", "Brown", 8121, 1005, 5000}
    };

    int choice;

    do {
        cout << "--------------------------------------\n";
        cout << "1. Sign up\n";
        cout << "2. Sign in\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            clearInput();
            continue;
        }

        switch (choice) {
            case 1:
                signUp(users);
                break;
            case 2:
                signIn(users);
                break;
            case 3:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
