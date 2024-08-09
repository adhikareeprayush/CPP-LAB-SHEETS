#include <iostream>
using namespace std;

class CarPark {
private:
    int carID;
    int chargePerHour;
    float parkedTime;

public:
    // Function to set data members
    void setData(int id, int charge, float time) {
        carID = id;
        chargePerHour = charge;
        parkedTime = time;
    }

    // Function to display the charges and parked hours
    void showDetails() const {
        float totalCharge = calculateCharges();
        cout << "Car ID: " << carID << endl;
        cout << "Parked Time (hours): " << parkedTime << endl;
        cout << "Charge per Hour: " << chargePerHour << endl;
        cout << "Total Charge: " << totalCharge << endl;
    }

private:
    // Function to calculate charges based on parked time
    float calculateCharges() const {
        return chargePerHour * parkedTime;
    }
};

int main() {
    CarPark car1;

    // Set car data
    int id;
    int charge;
    float time;

    cout << "Enter Car ID: ";
    cin >> id;
    cout << "Enter Charge per Hour: ";
    cin >> charge;
    cout << "Enter Parked Time (hours): ";
    cin >> time;

    car1.setData(id, charge, time);

    // Show car details
    car1.showDetails();

    return 0;
}
