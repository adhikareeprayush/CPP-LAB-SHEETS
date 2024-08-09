#include <iostream>
#include <string>
using namespace std;

// Base class Person
class Person {
protected:
    string name;
    int age;

public:
    // Function to enter name and age
    void enterDetails() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore(); // To ignore the newline character left in the buffer
    }

    // Print the address of the current object
    void printAddress() const {
        cout << "Address of object: " << this << endl;
    }

    // Function to display the person's details
    void displayDetails() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class Student
class Student : public Person {
private:
    string studentID;

public:
    // Function to enter student details
    void enterStudentDetails() {
        enterDetails();
        cout << "Enter student ID: ";
        getline(cin, studentID);
    }

    // Function to change student ID
    void changeStudentID() {
        cout << "Enter new student ID: ";
        getline(cin, studentID);
    }

    // Function to delete student record
    void deleteStudentRecord() {
        studentID = "";
    }

    // Function to display student details
    void displayStudentDetails() const {
        displayDetails();
        cout << "Student ID: " << studentID << endl;
    }
};

// Derived class Employee
class Employee : public Person {
private:
    string employeeID;

public:
    // Function to enter employee details
    void enterEmployeeDetails() {
        enterDetails();
        cout << "Enter employee ID: ";
        getline(cin, employeeID);
    }

    // Function to change employee ID
    void changeEmployeeID() {
        cout << "Enter new employee ID: ";
        getline(cin, employeeID);
    }

    // Function to delete employee record
    void deleteEmployeeRecord() {
        employeeID = "";
    }

    // Function to display employee details
    void displayEmployeeDetails() const {
        displayDetails();
        cout << "Employee ID: " << employeeID << endl;
    }
};

int main() {
    // Create objects of base class Person
    Person person1, person2;
    cout << "Enter details for Person 1:" << endl;
    person1.enterDetails();
    cout << "Enter details for Person 2:" << endl;
    person2.enterDetails();

    // Create objects of derived class Student
    Student student1, student2;
    cout << "Enter details for Student 1:" << endl;
    student1.enterStudentDetails();
    cout << "Enter details for Student 2:" << endl;
    student2.enterStudentDetails();

    // Create objects of derived class Employee
    Employee employee1, employee2;
    cout << "Enter details for Employee 1:" << endl;
    employee1.enterEmployeeDetails();
    cout << "Enter details for Employee 2:" << endl;
    employee2.enterEmployeeDetails();

    // Print addresses of objects
    cout << "\nAddresses of objects:" << endl;
    person1.printAddress();
    person2.printAddress();
    student1.printAddress();
    student2.printAddress();
    employee1.printAddress();
    employee2.printAddress();

    // Display details
    cout << "\nDetails of Person 1:" << endl;
    person1.displayDetails();
    cout << "Details of Person 2:" << endl;
    person2.displayDetails();

    cout << "\nDetails of Student 1:" << endl;
    student1.displayStudentDetails();
    cout << "Details of Student 2:" << endl;
    student2.displayStudentDetails();

    cout << "\nDetails of Employee 1:" << endl;
    employee1.displayEmployeeDetails();
    cout << "Details of Employee 2:" << endl;
    employee2.displayEmployeeDetails();

    return 0;
}
