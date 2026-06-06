#include <iostream>
using namespace std;

int Pin[5] = {2003, 2000, 1985, 1200, 8121};
string Names[5] = {"Mike", "John", "Sarah", "Anna", "Tom"};
int AccountNumber[5] = {12345, 67890, 54321, 98765, 13579};
double Balance[5] = {1000.50, 2500.75, 500.25, 1500.00, 3000.00};

int main()
{
    int userPin;
    bool found = false; 

    cout << "Welcome to World Bank\n";
    cout << "Enter your PIN: ";
    cin >> userPin;

    for (int i = 0; i < 5; i++)
    {
        if (userPin == Pin[i])
        {
            found = true;

            cout << "\nAccess Granted!\n";
            cout << "-----------------------------\n";
            cout << "Name:           " << Names[i] << "\n";
            cout << "Account Number: " << AccountNumber[i] << "\n";
            cout << "Balance:        R" << Balance[i] << "\n";
            cout << "-----------------------------\n";

            break; // ← stop searching once found
        }
    }

    if (!found)
    {
        cout << "Access Denied — PIN not recognised.\n";
    }

    return 0;
}