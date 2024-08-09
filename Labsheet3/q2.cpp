#include <iostream>
using namespace std;

// Class to handle prime number checking
class PrimeChecker {
public:
    // Function to check if a number is prime
    bool isPrime(int number) const {
        if (number <= 1) return false;
        if (number <= 3) return true;
        if (number % 2 == 0 || number % 3 == 0) return false;
        for (int i = 5; i * i <= number; i += 6) {
            if (number % i == 0 || number % (i + 2) == 0) return false;
        }
        return true;
    }
};

int main() {
    PrimeChecker checker;
    char response;

    do {
        // Ask the user to enter a number
        int number;
        cout << "Enter a number to check if it is prime: ";
        cin >> number;

        // Check if the number is prime
        if (checker.isPrime(number)) {
            cout << number << " is a prime number." << endl;
        } else {
            cout << number << " is not a prime number." << endl;
        }

        // Ask if the user wants to do another calculation
        cout << "Do you want to check another number? (y/n): ";
        cin >> response;
        
    } while (response == 'y' || response == 'Y');

    cout << "Thank you for using the prime checker!" << endl;
    return 0;
}
