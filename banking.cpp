#include <iostream>
using namespace std;

void deposit(int* balance) {
    int amount;
    cout << "Enter deposit amount: ";
    cin >> amount;                          
    *balance = *balance + amount;           
}

void withdraw(int* balance) {
    int amount;
    cout << "Enter withdrawal amount: ";
    cin >> amount;                          
    if (amount > *balance) {               
        cout << "Insufficient funds\n";
    } else {
        *balance = *balance - amount;
    }
}

int main() {
    int balance = 5000;
    cout << "--------------------------------------"<< "\n";
    cout << "Current balance: R " << balance << "\n";

    deposit(&balance);
    cout << "Balance after deposit:    R" << balance << "\n";
    cout << "-----------"<< "\n";

    withdraw(&balance);
    cout << "Balance after withdrawal: R " << balance << "\n";
    cout << "-----------"<< "\n";

    withdraw(&balance);
    cout << "Balance after withdrawal: R " << balance << "\n";
    cout << "--------------------------------------"<< "\n";

    return 0;
}
