#include <iostream>
#include <string>
using namespace std;

// Class to represent an employee report
class EmployeeReport {
private:
    int employeeID;
    float totalBonus;
    float totalOvertime;
    int year;

public:
    // Function to set report attributes
    void setPara(int id, float bonus, float overtime, int year) {
        employeeID = id;
        totalBonus = bonus;
        totalOvertime = overtime;
        this->year = year;
    }

    // Function to display the report
    void displayReport(const string& name) const {
        cout << "An employee with ID " << employeeID 
             << " named " << name 
             << " has received Rs " << totalBonus 
             << " as a bonus and had worked " << totalOvertime 
             << " hours as overtime in the year " << year << "." << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    // Create an array of EmployeeReport objects
    EmployeeReport reports[n];

    // Input data for each employee
    for (int i = 0; i < n; ++i) {
        int id, year;
        float bonus, overtime;
        string name;

        cout << "Enter details for employee " << (i + 1) << ":" << endl;
        cout << "Employee ID: ";
        cin >> id;
        cout << "Employee Name: ";
        cin.ignore(); // Clear newline character from input buffer
        getline(cin, name);
        cout << "Total Bonus: ";
        cin >> bonus;
        cout << "Total Overtime Hours: ";
        cin >> overtime;
        cout << "Year: ";
        cin >> year;

        // Set the report attributes
        reports[i].setPara(id, bonus, overtime, year);
    }

    // Display reports for each employee
    cout << "\nEmployee Reports:" << endl;
    for (int i = 0; i < n; ++i) {
        reports[i].displayReport("Employee " + to_string(i + 1));
    }

    return 0;
}
