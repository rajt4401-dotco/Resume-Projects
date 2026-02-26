#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // for setprecision
using namespace std;

// Global variables
float balance = 10000.0;                    // Starting balance
vector<string> history;                     // Transaction history
const int correctPIN = 4401;                // Predefined PIN

// Function to check balance
void checkBalance() {
    cout << fixed << setprecision(2);
    cout << "\n[Balance] Current balance: ₹" << balance << endl;
}

// Function to deposit money
void deposit() {
    float amount;
    cout << "\n[Deposit] Enter amount to deposit: ₹";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        cout << "₹" << amount << " deposited successfully." << endl;
        history.push_back("Deposited ₹" + to_string(amount));
        checkBalance();
    } else {
        cout << "Invalid amount! Please enter a positive value." << endl;
    }
}

// Function to withdraw money
void withdraw() {
    float amount;
    cout << "\n[Withdraw] Enter amount to withdraw: ₹";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount!" << endl;
    } else if (amount > balance) {
        cout << "Insufficient balance!" << endl;
    } else {
        balance -= amount;
        cout << "₹" << amount << " withdrawn successfully." << endl;
        history.push_back("Withdrew ₹" + to_string(amount));
        checkBalance();
    }
}

// Function to show transaction history
void showHistory() {
    cout << "\n[Transaction History]" << endl;
    if (history.empty()) {
        cout << "No transactions yet." << endl;
    } else {
        for (int i = 0; i < history.size(); i++) {
            cout << i + 1 << ". " << history[i] << endl;
        }
    }
}

// Function to handle PIN authentication
bool authenticatePIN() {
    int enteredPIN, attempts = 0;
    while (attempts < 3) {
        cout << "Enter your 4-digit PIN: ";
        cin >> enteredPIN;
        if (enteredPIN == correctPIN) {
            cout << "\nAccess granted. Welcome to the ATM!\n";
            return true;
        } else {
            attempts++;
            cout << "Incorrect PIN! Attempts left: " << (3 - attempts) << endl;
        }
    }
    cout << "\nToo many incorrect attempts. Exiting program.\n";
    return false;
}

int main() {
    // Authenticate PIN before showing ATM menu
    if (!authenticatePIN()) {
        return 0;
    }

    int choice;
    bool exitProgram = false;

    cout << "-------------------------------" << endl;
    cout << "         Simple ATM Menu       " << endl;
    cout << "-------------------------------" << endl;

    // Main ATM menu loop
    do {
        cout << "\nSelect an option:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. View Transaction History" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                showHistory();
                break;
            case 5:
                cout << "\nThank you for using the ATM. Goodbye!\n";
                exitProgram = true;
                break;
            default:
                cout << "\nInvalid choice! Please select between 1 to 5." << endl;
        }

    } while (!exitProgram);

    return 0;
}