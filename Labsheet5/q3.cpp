#include <iostream>
using namespace std;

class Integer {
private:
    int value;

public:
    // Constructor to initialize value
    Integer(int v = 0) : value(v) {}

    // Member function to overload the equality operator (==)
    bool operator==(const Integer& other) const {
        return value == other.value;
    }

    // Member function to overload the not equal operator (!=)
    bool operator!=(const Integer& other) const {
        return value != other.value;
    }

    // Member function to overload the less than operator (<)
    bool operator<(const Integer& other) const {
        return value < other.value;
    }

    // Member function to overload the greater than operator (>)
    bool operator>(const Integer& other) const {
        return value > other.value;
    }

    // Member function to overload the less than or equal to operator (<=)
    bool operator<=(const Integer& other) const {
        return value <= other.value;
    }

    // Member function to overload the greater than or equal to operator (>=)
    bool operator>=(const Integer& other) const {
        return value >= other.value;
    }

    // Function to display the integer value
    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    // Create two Integer objects
    Integer int1(10);
    Integer int2(20);

    // Compare the two objects using overloaded operators
    cout << "int1: ";
    int1.display();
    cout << "int2: ";
    int2.display();

    cout << "int1 == int2: " << (int1 == int2) << endl;
    cout << "int1 != int2: " << (int1 != int2) << endl;
    cout << "int1 < int2: " << (int1 < int2) << endl;
    cout << "int1 > int2: " << (int1 > int2) << endl;
    cout << "int1 <= int2: " << (int1 <= int2) << endl;
    cout << "int1 >= int2: " << (int1 >= int2) << endl;

    return 0;
}
