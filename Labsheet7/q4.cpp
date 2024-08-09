#include <iostream>
#include <typeinfo> // For typeid
using namespace std;

// Base class Vehicle
class Vehicle {
public:
    virtual void display() const {
        cout << "This is a Vehicle." << endl;
    }

    virtual ~Vehicle() {
        cout << "Vehicle destructor called" << endl;
    }
};

// Derived class Bus
class Bus : public Vehicle {
public:
    void display() const override {
        cout << "This is a Bus." << endl;
    }

    ~Bus() override {
        cout << "Bus destructor called" << endl;
    }
};

// Derived class Car
class Car : public Vehicle {
public:
    void display() const override {
        cout << "This is a Car." << endl;
    }

    ~Car() override {
        cout << "Car destructor called" << endl;
    }
};

// Derived class Bike
class Bike : public Vehicle {
public:
    void display() const override {
        cout << "This is a Bike." << endl;
    }

    ~Bike() override {
        cout << "Bike destructor called" << endl;
    }
};

int main() {
    // Create objects of derived classes
    Vehicle* v1 = new Bus();
    Vehicle* v2 = new Car();
    Vehicle* v3 = new Bike();

    // Array of pointers to Vehicle
    Vehicle* vehicles[] = { v1, v2, v3 };

    // Display type information and use dynamic_cast
    for (int i = 0; i < 3; ++i) {
        cout << "Type of object " << i+1 << ": " << typeid(*vehicles[i]).name() << endl;

        // Use dynamic_cast to downcast to specific types
        if (Bus* busPtr = dynamic_cast<Bus*>(vehicles[i])) {
            cout << "This is a Bus object." << endl;
            busPtr->display();
        } else if (Car* carPtr = dynamic_cast<Car*>(vehicles[i])) {
            cout << "This is a Car object." << endl;
            carPtr->display();
        } else if (Bike* bikePtr = dynamic_cast<Bike*>(vehicles[i])) {
            cout << "This is a Bike object." << endl;
            bikePtr->display();
        } else {
            cout << "Unknown Vehicle type." << endl;
        }
    }

    // Clean up
    for (int i = 0; i < 3; ++i) {
        delete vehicles[i];
    }

    return 0;
}
