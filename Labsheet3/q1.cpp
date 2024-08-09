#include <iostream>
using namespace std;

// Class to handle Celsius temperature
class Celsius {
private:
    double tempC;

public:
    // Constructor to initialize Celsius temperature
    Celsius(double temp) : tempC(temp) {}

    // Function to convert Celsius to Fahrenheit
    double toFahrenheit() const {
        return (tempC * 9.0 / 5.0) + 32.0;
    }

    // Function to set a new Celsius temperature
    void setTemperature(double temp) {
        tempC = temp;
    }

    // Function to get the Celsius temperature
    double getTemperature() const {
        return tempC;
    }
};

// Class to handle Fahrenheit temperature
class Fahrenheit {
private:
    double tempF;

public:
    // Constructor to initialize Fahrenheit temperature
    Fahrenheit(double temp) : tempF(temp) {}

    // Function to convert Fahrenheit to Celsius
    double toCelsius() const {
        return (tempF - 32.0) * 5.0 / 9.0;
    }

    // Function to set a new Fahrenheit temperature
    void setTemperature(double temp) {
        tempF = temp;
    }

    // Function to get the Fahrenheit temperature
    double getTemperature() const {
        return tempF;
    }
};

int main() {
    // Create an instance of Celsius with an initial temperature
    Celsius celsiusTemp(25.0);
    // Create an instance of Fahrenheit with an initial temperature
    Fahrenheit fahrenheitTemp(77.0);

    // Convert Celsius to Fahrenheit
    double fahrenheit = celsiusTemp.toFahrenheit();
    cout << "Temperature in Celsius: " << celsiusTemp.getTemperature() << "°C" << endl;
    cout << "Converted to Fahrenheit: " << fahrenheit << "°F" << endl;

    // Convert Fahrenheit to Celsius
    double celsius = fahrenheitTemp.toCelsius();
    cout << "Temperature in Fahrenheit: " << fahrenheitTemp.getTemperature() << "°F" << endl;
    cout << "Converted to Celsius: " << celsius << "°C" << endl;

    return 0;
}
