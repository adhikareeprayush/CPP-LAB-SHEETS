#include <iostream>
#include <cstring> // for strlen, strcpy
using namespace std;

class Department {
private:
    int departmentID;
    char* departmentName;

public:
    // Parameterized constructor
    Department(int id, const char* name) : departmentID(id) {
        departmentName = new char[strlen(name) + 1];
        strcpy(departmentName, name);
        cout << "Constructor: Department ID " << departmentID << " and Name " << departmentName << " initialized." << endl;
    }

    // Destructor
    ~Department() {
        cout << "Destructor: Object with Department ID " << departmentID << " goes out of scope." << endl;
        delete[] departmentName;
    }

    // Member function to display department details
    void display() const {
        cout << "Department ID: " << departmentID << endl;
        cout << "Department Name: " << departmentName << endl;
    }
};

int main() {
    {
        Department dept1(101, "HR");
        dept1.display();

        Department dept2(102, "Finance");
        dept2.display();
    } // dept1 and dept2 go out of scope here

    return 0;
}
