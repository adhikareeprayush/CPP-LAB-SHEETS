#include <iostream>
using namespace std;

// Inline function to calculate and display net payment after tax
inline void displayNetPayment(double salary) {
    const double TAX_RATE = 0.10; // 10% income tax
    double netPayment = salary - (salary * TAX_RATE);
    cout << "Net payment to the employee: $" << netPayment << endl;
}

int main() {
    // Ask user to enter the employee salary
    double salary;
    cout << "Enter the employee salary: $";
    cin >> salary;

    // Display the net payment using the inline function
    displayNetPayment(salary);

    return 0;
}
