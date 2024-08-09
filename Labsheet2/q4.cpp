#include <iostream>
using namespace std;

// Function to compare two temperatures and set the larger one to a new value
double& setLargerTemperature(double& temp1, double& temp2) {
    if (temp1 > temp2) {
        return temp1;
    } else {
        return temp2;
    }
}

int main() {
    // Initialize two temperature values
    double temperature1 = 37.5;
    double temperature2 = 39.0;

    cout << "Initial temperatures:" << endl;
    cout << "Temperature 1: " << temperature1 << "°C" << endl;
    cout << "Temperature 2: " << temperature2 << "°C" << endl;

    // User enters a new value for the larger temperature
    cout << "\nEnter a new value for the larger temperature: ";
    double newTemperature;
    cin >> newTemperature;

    // Set the larger temperature to the new value
    setLargerTemperature(temperature1, temperature2) = newTemperature;

    cout << "\nUpdated temperatures:" << endl;
    cout << "Temperature 1: " << temperature1 << "°C" << endl;
    cout << "Temperature 2: " << temperature2 << "°C" << endl;

    return 0;
}
