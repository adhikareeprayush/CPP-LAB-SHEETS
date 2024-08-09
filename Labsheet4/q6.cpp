#include <iostream>
using namespace std;

class SerialNumberGenerator {
private:
    int serialNumber; // Holds the serial number of the object

    // Static data member to keep track of the next serial number
    static int nextSerialNumber;

public:
    // Constructor to initialize the serial number
    SerialNumberGenerator() {
        serialNumber = nextSerialNumber++;
    }

    // Static member function to get the next serial number
    static int getNextSerialNumber() {
        return nextSerialNumber;
    }

    // Function to display the serial number of the object
    void displaySerialNumber() const {
        cout << "Serial Number: " << serialNumber << endl;
    }
};

// Initialize static data member
int SerialNumberGenerator::nextSerialNumber = 1;

int main() {
    // Create objects of SerialNumberGenerator
    SerialNumberGenerator obj1;
    SerialNumberGenerator obj2;
    SerialNumberGenerator obj3;

    // Display serial numbers of each object
    obj1.displaySerialNumber(); // Should display 1
    obj2.displaySerialNumber(); // Should display 2
    obj3.displaySerialNumber(); // Should display 3

    // Display the next serial number (which will be 4)
    cout << "Next Serial Number to be assigned: " << SerialNumberGenerator::getNextSerialNumber() << endl;

    return 0;
}
