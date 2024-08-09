#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Structure to store account information
struct Account {
    int accountNumber;
    string lastName;
    string firstName;
    double totalBalance;
};

// Function to add a new account to the file
void addAccount(const string& filename, const Account& account) {
    ofstream outFile(filename, ios::binary | ios::app); // Open file in binary append mode
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    outFile.write(reinterpret_cast<const char*>(&account), sizeof(Account));
    outFile.close();
}

// Function to update an existing account in the file
void updateAccount(const string& filename, int accountNumber, const Account& updatedAccount) {
    fstream file(filename, ios::binary | ios::in | ios::out);
    if (!file) {
        cerr << "Error opening file for updating." << endl;
        return;
    }

    Account account;
    while (file.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
        if (account.accountNumber == accountNumber) {
            file.seekp(-static_cast<long>(sizeof(Account)), ios::cur);
            file.write(reinterpret_cast<const char*>(&updatedAccount), sizeof(Account));
            file.close();
            return;
        }
    }

    cerr << "Account not found." << endl;
    file.close();
}

// Function to delete an account from the file
void deleteAccount(const string& filename, int accountNumber) {
    ifstream inFile(filename, ios::binary);
    ofstream outFile("temp.dat", ios::binary);

    if (!inFile || !outFile) {
        cerr << "Error opening file for deleting." << endl;
        return;
    }

    Account account;
    while (inFile.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
        if (account.accountNumber != accountNumber) {
            outFile.write(reinterpret_cast<const char*>(&account), sizeof(Account));
        }
    }

    inFile.close();
    outFile.close();
    remove(filename.c_str());  // Delete the original file
    rename("temp.dat", filename.c_str());  // Rename temp file to original file name
}

// Function to display all accounts from the file
void displayAccounts(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    Account account;
    cout << left << setw(15) << "Account Number" << setw(15) << "Last Name" << setw(15) << "First Name" << setw(15) << "Balance" << endl;
    cout << "-------------------------------------------------" << endl;

    while (inFile.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
        cout << setw(15) << account.accountNumber 
             << setw(15) << account.lastName 
             << setw(15) << account.firstName 
             << setw(15) << fixed << setprecision(2) << account.totalBalance 
             << endl;
    }

    inFile.close();
}

int main() {
    string filename = "accounts.dat";

    // Example account records
    Account acc1 = {1001, "Smith", "John", 5000.00};
    Account acc2 = {1002, "Doe", "Jane", 6000.00};

    // Add records
    addAccount(filename, acc1);
    addAccount(filename, acc2);

    // Display all accounts
    cout << "All accounts:" << endl;
    displayAccounts(filename);

    // Update account
    Account updatedAcc1 = {1001, "Smith", "John", 5500.00};
    updateAccount(filename, 1001, updatedAcc1);

    // Display all accounts after update
    cout << "\nAll accounts after update:" << endl;
    displayAccounts(filename);

    // Delete an account
    deleteAccount(filename, 1002);

    // Display all accounts after deletion
    cout << "\nAll accounts after deletion:" << endl;
    displayAccounts(filename);

    return 0;
}
