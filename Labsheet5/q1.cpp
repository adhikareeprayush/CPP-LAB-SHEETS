#include <iostream>
using namespace std;

class Coordinate; // Forward declaration

// Class for 2D Cartesian coordinates
class Coordinate {
private:
    int x, y;

public:
    // Constructor to initialize coordinates
    Coordinate(int x = 0, int y = 0) : x(x), y(y) {}

    // Friend function to handle addition of two Coordinate objects
    friend Coordinate add(const Coordinate& c1, const Coordinate& c2);

    // Member function to handle subtraction
    Coordinate subtract(const Coordinate& c) const {
        return Coordinate(x - c.x, y - c.y);
    }

    // Member function to handle multiplication (by a scalar)
    Coordinate multiply(int scalar) const {
        return Coordinate(x * scalar, y * scalar);
    }

    // Member function to handle division (by a scalar)
    Coordinate divide(int scalar) const {
        if (scalar != 0)
            return Coordinate(x / scalar, y / scalar);
        else
            throw invalid_argument("Division by zero is not allowed.");
    }

    // Function to display coordinates
    void display() const {
        cout << "Coordinate: (" << x << ", " << y << ")" << endl;
    }
};

// Friend function to handle addition of two Coordinate objects
Coordinate add(const Coordinate& c1, const Coordinate& c2) {
    return Coordinate(c1.x + c2.x, c1.y + c2.y);
}

int main() {
    // Create two Coordinate objects
    Coordinate coord1(3, 4);
    Coordinate coord2(1, 2);

    // Demonstrate addition
    Coordinate sum = add(coord1, coord2);
    cout << "Addition result: ";
    sum.display();

    // Demonstrate subtraction
    Coordinate diff = coord1.subtract(coord2);
    cout << "Subtraction result: ";
    diff.display();

    // Demonstrate multiplication
    Coordinate prod = coord1.multiply(2);
    cout << "Multiplication result: ";
    prod.display();

    // Demonstrate division
    try {
        Coordinate quot = coord1.divide(2);
        cout << "Division result: ";
        quot.display();
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}
