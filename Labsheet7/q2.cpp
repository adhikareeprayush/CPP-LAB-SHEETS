#include <iostream>
#include <string>
using namespace std;

// Base class Person
class Person {
protected:
    string name;
    int age;

public:
    Person() : name(""), age(0) {}
    Person(string n, int a) : name(n), age(a) {}

    void setDetails(string n, int a) {
        name = n;
        age = a;
    }

    void displayDetails() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    virtual ~Person() {
        cout << "Person destructor called" << endl;
    }
};

// Derived class Employee
class Employee : virtual public Person {
protected:
    string employeeID;
    double salary;

public:
    Employee() : Person(), employeeID(""), salary(0.0) {}
    Employee(string n, int a, string id, double s) : Person(n, a), employeeID(id), salary(s) {}

    void setEmployeeDetails(string id, double s) {
        employeeID = id;
        salary = s;
    }

    void displayEmployeeDetails() const {
        displayDetails();
        cout << "Employee ID: " << employeeID << ", Salary: " << salary << endl;
    }

    virtual ~Employee() {
        cout << "Employee destructor called" << endl;
    }
};

// Derived class Student
class Student : virtual public Person {
protected:
    string studentID;
    double GPA;

public:
    Student() : Person(), studentID(""), GPA(0.0) {}
    Student(string n, int a, string id, double g) : Person(n, a), studentID(id), GPA(g) {}

    void setStudentDetails(string id, double g) {
        studentID = id;
        GPA = g;
    }

    void displayStudentDetails() const {
        displayDetails();
        cout << "Student ID: " << studentID << ", GPA: " << GPA << endl;
    }

    virtual ~Student() {
        cout << "Student destructor called" << endl;
    }
};

// Derived class Manager
class Manager : public Employee, public Student {
public:
    Manager() : Employee(), Student() {}
    Manager(string n, int a, string empID, double sal, string studID, double gpa) 
        : Person(n, a), Employee(n, a, empID, sal), Student(n, a, studID, gpa) {}

    void displayManagerDetails() const {
        Employee::displayEmployeeDetails();
        Student::displayStudentDetails();
    }

    virtual ~Manager() {
        cout << "Manager destructor called" << endl;
    }
};

int main() {
    // Create a Manager object
    Manager mgr("Alice", 35, "E123", 75000.0, "S456", 3.8);

    // Display Manager details
    mgr.displayManagerDetails();

    return 0;
}
