#include <iostream>
using namespace std;

// Forward declaration of ComplexDiff
class ComplexDiff;

// Base class ComplexBase
class ComplexBase {
protected:
    double real;
    double imag;

public:
    // Function to enter complex number
    void enterComplex() {
        cout << "Enter the real part of the complex number: ";
        cin >> real;
        cout << "Enter the imaginary part of the complex number: ";
        cin >> imag;
    }

    // Function to display the complex number
    void displayComplex() const {
        cout << "Complex Number: " << real << " + " << imag << "i" << endl;
    }

    // Make ComplexDiff a friend of ComplexBase
    friend class ComplexDiff;
};

// Derived class ComplexAdd
class ComplexAdd : public ComplexBase {
private:
    double derivedReal;
    double derivedImag;

public:
    // Function to enter the complex number of the derived class
    void enterDerivedComplex() {
        enterComplex(); // Calls base class method to enter base complex number
        cout << "Enter the real part of the derived complex number: ";
        cin >> derivedReal;
        cout << "Enter the imaginary part of the derived complex number: ";
        cin >> derivedImag;
    }

    // Function to display the complex number of the derived class
    void displayDerivedComplex() const {
        cout << "Derived Complex Number: " << derivedReal << " + " << derivedImag << "i" << endl;
    }

    // Function to add the base and derived complex numbers
    void addComplex() const {
        double sumReal = real + derivedReal;
        double sumImag = imag + derivedImag;
        cout << "Sum of Base and Derived Complex Numbers: " << sumReal << " + " << sumImag << "i" << endl;
    }

    // Friend class declaration
    friend class ComplexDiff;
};

// Friend class ComplexDiff
class ComplexDiff {
public:
    // Function to calculate the difference between base and derived complex numbers
    void calculateDifference(const ComplexBase& base, const ComplexAdd& derived) const {
        double diffReal = derived.real - base.real;
        double diffImag = derived.imag - base.imag;
        cout << "Difference between Base and Derived Complex Numbers: " << diffReal << " + " << diffImag << "i" << endl;
    }
};

int main() {
    // Create objects
    ComplexBase baseComplex;
    ComplexAdd derivedComplex;

    // Enter and display base complex number
    cout << "Enter base complex number:" << endl;
    baseComplex.enterComplex();
    baseComplex.displayComplex();

    // Enter and display derived complex number, and add both
    cout << "Enter derived complex number:" << endl;
    derivedComplex.enterDerivedComplex();
    derivedComplex.displayDerivedComplex();
    derivedComplex.addComplex();

    // Calculate and display the difference using the friend class
    ComplexDiff diffCalculator;
    diffCalculator.calculateDifference(baseComplex, derivedComplex);

    return 0;
}
