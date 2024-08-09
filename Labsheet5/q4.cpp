#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;

    // Helper function to check if a year is a leap year
    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Helper function to get the number of days in a month
    int daysInMonth(int month, int year) const {
        switch (month) {
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                return isLeapYear(year) ? 29 : 28;
            default:
                return 31;
        }
    }

public:
    // Constructor to initialize date
    Date(int day = 1, int month = 1, int year = 2000) : day(day), month(month), year(year) {}

    // Prefix increment operator
    Date& operator++() {
        // Increment the day
        if (++day > daysInMonth(month, year)) {
            day = 1;
            if (++month > 12) {
                month = 1;
                ++year;
            }
        }
        return *this;
    }

    // Postfix increment operator
    Date operator++(int) {
        Date temp = *this; // Save the current state
        ++(*this);         // Use the prefix increment
        return temp;       // Return the old state
    }

    // Function to display the date
    void display() const {
        cout << (day < 10 ? "0" : "") << day << "/"
             << (month < 10 ? "0" : "") << month << "/"
             << year << endl;
    }
};

int main() {
    // Create a Date object
    Date date(28, 2, 2024); // Leap year example

    // Display initial date
    cout << "Initial date: ";
    date.display();

    // Test prefix increment
    ++date;
    cout << "After prefix increment: ";
    date.display();

    // Test postfix increment
    date++;
    cout << "After postfix increment: ";
    date.display();

    return 0;
}
