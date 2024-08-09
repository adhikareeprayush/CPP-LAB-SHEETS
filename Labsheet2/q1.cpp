#include <iostream>
using namespace std;

// Structure to hold the date
struct Date {
    int month;
    int day;
    int year;
};

// Function to print the date in the format mm/dd/yyyy
void printDate(const Date& date) {
    cout << date.month << "/" << date.day << "/" << date.year << endl;
}

int main() {
    // Create an instance of the Date structure and assign values
    Date today;
    today.month = 11;
    today.day = 28;
    today.year = 2004;

    // Call the function to print the date
    printDate(today);

    return 0;
}
