#include <iostream>
#include <iomanip> // For std::setw, std::fixed
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Friend function to overload << operator for output
    friend ostream& operator<<(ostream& os, const Complex& c);

    // Friend function to overload >> operator for input
    friend istream& operator>>(istream& is, Complex& c);
};

// Overload << operator to display complex number
ostream& operator<<(ostream& os, const Complex& c) {
    os << fixed << setprecision(2); // Set precision for display
    os << c.real;
    if (c.imag >= 0)
        os << " + " << c.imag << "i";
    else
        os << " - " << -c.imag << "i";
    return os;
}

// Overload >> operator to read complex number
istream& operator>>(istream& is, Complex& c) {
    // Read real part and imaginary part from input stream
    cout << "Enter real part: ";
    is >> c.real;
    cout << "Enter imaginary part: ";
    is >> c.imag;
    return is;
}

int main() {
    Complex c1, c2;

    // Read complex number from user
    cout << "Enter first complex number:" << endl;
    cin >> c1;
    
    // Read another complex number from user
    cout << "Enter second complex number:" << endl;
    cin >> c2;

    // Display the complex numbers
    cout << "First complex number: " << c1 << endl;
    cout << "Second complex number: " << c2 << endl;

    return 0;
}
