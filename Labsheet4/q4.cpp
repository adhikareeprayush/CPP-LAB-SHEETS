#include <iostream>
#include <iomanip> // for std::fixed and std::setprecision
using namespace std;

class VehicleCharge {
private:
    int num_vehicle;
    float hour;
    float rate;

public:
    // Parameterized constructor
    VehicleCharge(int num, float h, float r) : num_vehicle(num), hour(h), rate(r) {
        cout << "Parameterized Constructor called." << endl;
        if (num_vehicle > 10) {
            rate *= 0.9; // Apply 10% discount
        }
    }

    // Copy constructor (bit-by-bit copy)
    VehicleCharge(const VehicleCharge& other) {
        cout << "Copy Constructor called." << endl;
        num_vehicle = other.num_vehicle;
        hour = other.hour;
        rate = other.rate;
    }

    // Function to calculate and display total charge
    void displayTotalCharge() const {
        float total_charge = num_vehicle * hour * rate;
        cout << "Number of Vehicles: " << num_vehicle << endl;
        cout << "Hours: " << hour << endl;
        cout << "Rate per Hour: " << fixed << setprecision(2) << rate << endl;
        cout << "Total Charge: " << fixed << setprecision(2) << total_charge << endl;
    }
};

int main() {
    // Create first VehicleCharge object
    VehicleCharge original(15, 5.0, 20.0);
    original.displayTotalCharge();

    // Create second VehicleCharge object using the copy constructor
    VehicleCharge copy = original;
    copy.displayTotalCharge();

    return 0;
}
