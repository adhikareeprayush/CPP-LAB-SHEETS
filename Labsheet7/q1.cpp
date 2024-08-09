#include <iostream>
#include <cmath>
using namespace std;

// Base class Shape
class Shape {
public:
    // Virtual destructor to ensure derived class destructors are called
    virtual ~Shape() {
        cout << "Shape destructor called" << endl;
    }

    // Pure virtual function to calculate the area of the shape
    virtual double area() const = 0;

    // Pure virtual function to display the shape details
    virtual void display() const = 0;
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Override the area function
    double area() const override {
        return M_PI * radius * radius; // M_PI from cmath
    }

    // Override the display function
    void display() const override {
        cout << "Circle with radius: " << radius << endl;
        cout << "Area: " << area() << endl;
    }

    ~Circle() override {
        cout << "Circle destructor called" << endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Override the area function
    double area() const override {
        return width * height;
    }

    // Override the display function
    void display() const override {
        cout << "Rectangle with width: " << width << " and height: " << height << endl;
        cout << "Area: " << area() << endl;
    }

    ~Rectangle() override {
        cout << "Rectangle destructor called" << endl;
    }
};

// Derived class Trapezoid
class Trapezoid : public Shape {
private:
    double a; // length of one parallel side
    double b; // length of the other parallel side
    double height;

public:
    Trapezoid(double side1, double side2, double h) : a(side1), b(side2), height(h) {}

    // Override the area function
    double area() const override {
        return 0.5 * (a + b) * height;
    }

    // Override the display function
    void display() const override {
        cout << "Trapezoid with sides: " << a << " and " << b << " and height: " << height << endl;
        cout << "Area: " << area() << endl;
    }

    ~Trapezoid() override {
        cout << "Trapezoid destructor called" << endl;
    }
};

// Function to demonstrate virtual functions and destructors
void demonstrateShapes() {
    Shape* shapes[3];

    // Create instances of derived classes
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);
    shapes[2] = new Trapezoid(3.0, 5.0, 4.0);

    // Display area and details of each shape
    for (int i = 0; i < 3; ++i) {
        shapes[i]->display();
    }

    // Clean up and call destructors
    for (int i = 0; i < 3; ++i) {
        delete shapes[i];
    }
}

int main() {
    demonstrateShapes();
    return 0;
}
