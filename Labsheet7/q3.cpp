#include <iostream>
#include <string>
using namespace std;

// Abstract base class Student
class Student {
protected:
    string name;
    int rollNumber;

public:
    Student(string n = "", int r = 0) : name(n), rollNumber(r) {}

    // Pure virtual function to be implemented by derived classes
    virtual void display() const = 0;

    virtual ~Student() {
        cout << "Student destructor called" << endl;
    }
};

// Derived class Engineering
class Engineering : public Student {
private:
    string specialization;

public:
    Engineering(string n, int r, string spec) : Student(n, r), specialization(spec) {}

    void display() const override {
        cout << "Engineering Student: " << endl;
        cout << "Name: " << name << ", Roll Number: " << rollNumber << endl;
        cout << "Specialization: " << specialization << endl;
    }

    ~Engineering() override {
        cout << "Engineering destructor called" << endl;
    }
};

// Derived class Medicine
class Medicine : public Student {
private:
    string hospital;

public:
    Medicine(string n, int r, string hosp) : Student(n, r), hospital(hosp) {}

    void display() const override {
        cout << "Medicine Student: " << endl;
        cout << "Name: " << name << ", Roll Number: " << rollNumber << endl;
        cout << "Hospital: " << hospital << endl;
    }

    ~Medicine() override {
        cout << "Medicine destructor called" << endl;
    }
};

// Derived class Science
class Science : public Student {
private:
    string researchArea;

public:
    Science(string n, int r, string area) : Student(n, r), researchArea(area) {}

    void display() const override {
        cout << "Science Student: " << endl;
        cout << "Name: " << name << ", Roll Number: " << rollNumber << endl;
        cout << "Research Area: " << researchArea << endl;
    }

    ~Science() override {
        cout << "Science destructor called" << endl;
    }
};

int main() {
    // Create an array of pointers to the base class Student
    Student* students[3];

    // Create objects of derived classes
    students[0] = new Engineering("Alice", 101, "Software Engineering");
    students[1] = new Medicine("Bob", 202, "City Hospital");
    students[2] = new Science("Carol", 303, "Astrophysics");

    // Process and display the details of each student
    for (int i = 0; i < 3; ++i) {
        students[i]->display();
    }

    // Clean up and delete the objects
    for (int i = 0; i < 3; ++i) {
        delete students[i];
    }

    return 0;
}
