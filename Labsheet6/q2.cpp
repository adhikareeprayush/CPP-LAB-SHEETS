#include <iostream>
#include <iomanip> // For std::setprecision
using namespace std;

// Class for distance in meter-centimeter format
class DistanceMetric {
private:
    int meters;
    int centimeters;

public:
    // Constructor to initialize the distance
    DistanceMetric(int m = 0, int cm = 0) : meters(m), centimeters(cm) {
        normalize();
    }

    // Function to normalize the distance
    void normalize() {
        if (centimeters >= 100) {
            meters += centimeters / 100;
            centimeters = centimeters % 100;
        } else if (centimeters < 0) {
            int cm_to_m = (centimeters / 100) - 1;
            meters += cm_to_m;
            centimeters = 100 + (centimeters % 100);
        }
    }

    // Convert to float meters
    float toMeters() const {
        return meters + centimeters / 100.0;
    }

    // Convert to feet and inches
    void toFeetInches(int &feet, int &inches) const {
        float totalMeters = toMeters();
        float totalInches = totalMeters * 39.3701;
        feet = static_cast<int>(totalInches) / 12;
        inches = static_cast<int>(totalInches) % 12;
    }

    // Display the distance
    void display() const {
        cout << "Distance: " << meters << " meters and " << centimeters << " centimeters" << endl;
    }
};

// Class for distance in feet-inch format
class DistanceImperial {
private:
    int feet;
    int inches;

public:
    // Constructor to initialize the distance
    DistanceImperial(int f = 0, int in = 0) : feet(f), inches(in) {
        normalize();
    }

    // Function to normalize the distance
    void normalize() {
        if (inches >= 12) {
            feet += inches / 12;
            inches = inches % 12;
        } else if (inches < 0) {
            int ft_to_in = (inches / 12) - 1;
            feet += ft_to_in;
            inches = 12 + (inches % 12);
        }
    }

    // Convert to float meters
    float toMeters() const {
        float totalInches = feet * 12 + inches;
        return totalInches * 0.0254;
    }

    // Convert to meters and centimeters
    void toMetersCentimeters(int &meters, int &centimeters) const {
        float totalMeters = toMeters();
        meters = static_cast<int>(totalMeters);
        centimeters = static_cast<int>((totalMeters - meters) * 100);
    }

    // Display the distance
    void display() const {
        cout << "Distance: " << feet << " feet and " << inches << " inches" << endl;
    }
};

int main() {
    // Create DistanceMetric object and display it
    DistanceMetric metricDist(5, 150); // 5 meters and 150 centimeters
    cout << "Metric Distance:" << endl;
    metricDist.display();

    // Convert Metric to Feet-Inches
    int feet, inches;
    metricDist.toFeetInches(feet, inches);
    cout << "Converted to Imperial: " << feet << " feet and " << inches << " inches" << endl;

    // Create DistanceImperial object and display it
    DistanceImperial imperialDist(12, 9); // 12 feet and 9 inches
    cout << "Imperial Distance:" << endl;
    imperialDist.display();

    // Convert Imperial to Meters-Centimeters
    int meters, centimeters;
    imperialDist.toMetersCentimeters(meters, centimeters);
    cout << "Converted to Metric: " << meters << " meters and " << centimeters << " centimeters" << endl;

    return 0;
}
