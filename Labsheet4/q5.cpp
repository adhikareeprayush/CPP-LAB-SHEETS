#include <iostream>
using namespace std;

class Demo {
private:
    int value;

public:
    // Constructor to initialize value
    Demo(int v) : value(v) {}

    // Non-const member function
    void nonConstFunc() {
        cout << "Non-const member function called. Value: " << value << endl;
    }

    // Const member function
    void constFunc() const {
        cout << "Const member function called. Value: " << value << endl;
    }
};

int main() {
    Demo obj1(10); // Non-const object
    const Demo obj2(20); // Const object

    // i) const_object.non_const_mem_function
    // This line will cause a compilation error because non-const member functions
    // cannot be called on const objects.
    // obj2.nonConstFunc(); // Uncommenting this line will cause an error

    // ii) const_object.const_mem_function
    // This is valid because const member functions can be called on const objects.
    obj2.constFunc();

    // iii) non_const_object.non_const_mem_function
    // This is valid because non-const member functions can be called on non-const objects.
    obj1.nonConstFunc();

    // iv) non_const_object.const_mem_function
    // This is also valid because const member functions can be called on non-const objects.
    obj1.constFunc();

    return 0;
}
