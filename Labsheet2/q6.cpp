#include <iostream>
using namespace std;

// Function to calculate the new salary after applying the increment
double calculateNewSalary(double salary, double incrementPercentage = 0.0) {
    return salary + (salary * incrementPercentage / 100.0);
}

int main() {
    // Salaries in 2009
    double ceoSalary = 35000;
    double infoOfficerSalary = 25000;
    double sysAnalystSalary = 24000;
    double programmerSalary = 18000;

    // Increment percentages for 2010
    double ceoIncrement = 9.0;
    double infoOfficerIncrement = 10.0;
    double sysAnalystIncrement = 12.0;
    double programmerIncrement = 12.0;

    // Calculate and display new salaries
    cout << "Salaries in 2010 after applying increments:" << endl;

    double ceoNewSalary = calculateNewSalary(ceoSalary, ceoIncrement);
    cout << "Chief Executive Officer: Rs. " << ceoNewSalary << "/m" << endl;

    double infoOfficerNewSalary = calculateNewSalary(infoOfficerSalary, infoOfficerIncrement);
    cout << "Information Officer: Rs. " << infoOfficerNewSalary << "/m" << endl;

    double sysAnalystNewSalary = calculateNewSalary(sysAnalystSalary, sysAnalystIncrement);
    cout << "System Analyst: Rs. " << sysAnalystNewSalary << "/m" << endl;

    double programmerNewSalary = calculateNewSalary(programmerSalary, programmerIncrement);
    cout << "Programmer: Rs. " << programmerNewSalary << "/m" << endl;

    return 0;
}
