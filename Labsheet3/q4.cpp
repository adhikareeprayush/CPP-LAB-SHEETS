#include <iostream>
#include <cmath>
using namespace std;

// Class to represent a Circle
class Circle {
private:
    float radius;

public:
    // Function to read circle data
    void read() {
        cout << "Enter the radius of the circle: ";
        cin >> radius;
    }

    // Function to display circle data
    void display() const {
        cout << "Circle:" << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }

    // Function to calculate the area of the circle
    float area() const {
        return M_PI * radius * radius;
    }

    // Function to calculate the perimeter of the circle
    float perimeter() const {
        return 2 * M_PI * radius;
    }
};

// Class to represent a Rectangle
class Rectangle {
private:
    float length;
    float width;

public:
    // Function to read rectangle data
    void read() {
        cout << "Enter the length and width of the rectangle: ";
        cin >> length >> width;
    }

    // Function to display rectangle data
    void display() const {
        cout << "Rectangle:" << endl;
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }

    // Function to calculate the area of the rectangle
    float area() const {
        return length * width;
    }

    // Function to calculate the perimeter of the rectangle
    float perimeter() const {
        return 2 * (length + width);
    }
};

// Class to represent a Triangle
class Triangle {
private:
    float sideA;
    float sideB;
    float sideC;

public:
    // Function to read triangle data
    void read() {
        cout << "Enter the lengths of the three sides of the triangle: ";
        cin >> sideA >> sideB >> sideC;
    }

    // Function to display triangle data
    void display() const {
        cout << "Triangle:" << endl;
        cout << "Side A: " << sideA << endl;
        cout << "Side B: " << sideB << endl;
        cout << "Side C: " << sideC << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }

    // Function to calculate the area of the triangle using Heron's formula
    float area() const {
        float s = perimeter() / 2; // semi-perimeter
        return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }

    // Function to calculate the perimeter of the triangle
    float perimeter() const {
        return sideA + sideB + sideC;
    }
};

int main() {
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;

    // Read and display Circle data
    circle.read();
    circle.display();
    cout << endl;

    // Read and display Rectangle data
    rectangle.read();
    rectangle.display();
    cout << endl;

    // Read and display Triangle data
    triangle.read();
    triangle.display();

    return 0;
}
