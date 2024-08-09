#include <iostream>
using namespace std;

// Function with no arguments
double convertToInches() {
    double feet = 0;
    cout << "Enter feet: ";
    cin >> feet;
    return feet * 12;
}

// Function with one argument (pass-by-value)
double convertToInches(double feet) {
    return feet * 12;
}

// Function with two arguments (pass-by-reference)
void convertToInches(double feet, double& inches) {
    inches = feet * 12;
}

int main() {
    // Using function with no arguments
    double inches1 = convertToInches();
    cout << "Converted value (no arguments): " << inches1 << " inches" << endl;

    // Using function with one argument
    double feet2 = 5.5;
    double inches2 = convertToInches(feet2);
    cout << "Converted value (one argument): " << feet2 << " feet = " << inches2 << " inches" << endl;

    // Using function with two arguments (pass-by-reference)
    double feet3 = 6.0;
    double inches3 = 0;
    convertToInches(feet3, inches3);
    cout << "Converted value (two arguments): " << feet3 << " feet = " << inches3 << " inches" << endl;

    return 0;
}
