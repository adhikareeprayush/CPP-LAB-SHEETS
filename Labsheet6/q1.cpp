#include <iostream>
#include <iomanip> // For std::setprecision
using namespace std;

class Distance {
private:
    int meter;
    int centimeter;

public:
    // Constructor to initialize distance
    Distance(int m = 0, int cm = 0) : meter(m), centimeter(cm) {
        normalize();
    }

    // Function to normalize the distance
    void normalize() {
        if (centimeter >= 100) {
            meter += centimeter / 100;
            centimeter = centimeter % 100;
        } else if (centimeter < 0) {
            int cm_to_m = (centimeter / 100) - 1;
            meter += cm_to_m;
            centimeter = 100 + (centimeter % 100);
        }
    }

    // Convert to float meters
    float toMeters() const {
        return meter + centimeter / 100.0;
    }

    // Convert from float meters
    void fromFloatMeters(float m) {
        meter = static_cast<int>(m);
        centimeter = static_cast<int>((m - meter) * 100);
        normalize();
    }

    // Display the distance in meters and centimeters
    void display() const {
        cout << "Distance: " << meter << " meters and " << centimeter << " centimeters" << endl;
    }

    // Display the distance in float meters
    void displayInMeters() const {
        cout << "Distance: " << fixed << setprecision(2) << toMeters() << " meters" << endl;
    }
};

int main() {
    // Create a Distance object and initialize with meters and centimeters
    Distance dist1(5, 250); // 5 meters and 250 centimeters
    cout << "Distance 1:" << endl;
    dist1.display();
    dist1.displayInMeters();
    
    // Convert from float meters
    float meters = 7.75;
    Distance dist2;
    dist2.fromFloatMeters(meters);
    cout << "Distance 2 (from float meters):" << endl;
    dist2.display();
    dist2.displayInMeters();

    return 0;
}
