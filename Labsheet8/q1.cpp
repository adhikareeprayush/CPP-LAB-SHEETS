#include <iostream>
#include <iomanip> // For std::setw, std::setprecision, std::fixed
#include <string>
using namespace std;

// Function to print the header
void printHeader() {
    cout << left << setw(30) << "Item" 
         << setw(10) << "Quantity" 
         << setw(15) << "Price per Unit" 
         << setw(15) << "Total Price" 
         << endl;
    cout << setfill('-') << setw(70) << "" << endl;
    cout << setfill(' '); // Reset fill character
}

// Function to print the item details
void printItem(const string& itemName, int quantity, double pricePerUnit) {
    double totalPrice = quantity * pricePerUnit;
    cout << left << setw(30) << itemName
         << setw(10) << quantity
         << setw(15) << fixed << setprecision(2) << pricePerUnit
         << setw(15) << totalPrice 
         << endl;
}

int main() {
    // Example items for the bill
    string items[] = {"Laptop", "Headphones", "Mouse", "Keyboard"};
    int quantities[] = {1, 2, 3, 1};
    double prices[] = {999.99, 49.95, 19.99, 29.95};

    // Print invoice header
    printHeader();

    // Print each item in the invoice
    for (int i = 0; i < 4; ++i) {
        printItem(items[i], quantities[i], prices[i]);
    }

    // Print the total
    double totalAmount = 0.0;
    for (int i = 0; i < 4; ++i) {
        totalAmount += quantities[i] * prices[i];
    }
    
    cout << setfill('-') << setw(70) << "" << endl;
    cout << setfill(' '); // Reset fill character
    cout << left << setw(55) << "Grand Total" 
         << setw(15) << fixed << setprecision(2) << totalAmount 
         << endl;

    return 0;
}
