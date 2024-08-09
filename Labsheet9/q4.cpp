#include <iostream>
#include <stdexcept> // For standard exceptions
using namespace std;

// Custom exception for demonstration
class CustomException : public runtime_error {
public:
    CustomException(const string& message) : runtime_error(message) {}
};

void functionWithExceptions(int choice) {
    try {
        if (choice == 1) {
            throw runtime_error("Standard runtime_error occurred.");
        } else if (choice == 2) {
            throw out_of_range("Standard out_of_range exception occurred.");
        } else if (choice == 3) {
            throw CustomException("CustomException occurred.");
        } else {
            throw exception(); // General exception
        }
    } catch (const CustomException& e) {
        cout << "Caught CustomException: " << e.what() << endl;
        throw; // Re-throw the same exception
    } catch (const out_of_range& e) {
        cout << "Caught out_of_range: " << e.what() << endl;
        throw; // Re-throw the same exception
    } catch (const runtime_error& e) {
        cout << "Caught runtime_error: " << e.what() << endl;
        throw; // Re-throw the same exception
    }
}

int main() {
    int choice;
    cout << "Enter choice (1: runtime_error, 2: out_of_range, 3: CustomException, 4: generic exception): ";
    cin >> choice;

    try {
        functionWithExceptions(choice);
    } catch (const exception& e) {
        cout << "Caught in main: " << e.what() << endl;
    } catch (...) {
        cout << "Caught an unknown exception type." << endl;
    }

    return 0;
}
