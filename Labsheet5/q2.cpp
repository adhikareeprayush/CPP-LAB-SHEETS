#include <iostream>
using namespace std;

class Point3D; // Forward declaration

// Class to store coordinates in 3D space
class Point3D {
private:
    int x, y, z;

public:
    // Constructor to initialize coordinates
    Point3D(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}

    // Friend function declarations for operator overloading
    friend Point3D operator+(const Point3D& p1, const Point3D& p2);
    friend Point3D operator-(const Point3D& p1, const Point3D& p2);

    // Function to display the point's coordinates
    void display() const {
        cout << "Point3D(" << x << ", " << y << ", " << z << ")" << endl;
    }
};

// Overload the + operator as a friend function
Point3D operator+(const Point3D& p1, const Point3D& p2) {
    return Point3D(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
}

// Overload the - operator as a friend function
Point3D operator-(const Point3D& p1, const Point3D& p2) {
    return Point3D(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
}

int main() {
    // Create two Point3D objects
    Point3D point1(3, 4, 5);
    Point3D point2(1, 2, 3);

    // Demonstrate addition
    Point3D resultAdd = point1 + point2;
    cout << "Addition result: ";
    resultAdd.display();

    // Demonstrate subtraction
    Point3D resultSub = point1 - point2;
    cout << "Subtraction result: ";
    resultSub.display();

    return 0;
}
