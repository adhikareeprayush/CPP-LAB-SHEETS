#include <iostream>
#include <iomanip> // for std::setw and std::setfill
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    // Default constructor (initializes to 00:00:00)
    Time() : hour(0), minute(0), second(0) {}

    // Parameterized constructor
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {
        normalize(); // Ensure time is in valid range
    }

    // Function to normalize the time values
    void normalize() {
        if (second >= 60) {
            minute += second / 60;
            second %= 60;
        }
        if (minute >= 60) {
            hour += minute / 60;
            minute %= 60;
        }
        hour %= 24;
    }

    // Function to add two time objects and return the result
    Time add(const Time& other) const {
        int totalSeconds = (hour * 3600 + minute * 60 + second) +
                           (other.hour * 3600 + other.minute * 60 + other.second);
        int newHour = totalSeconds / 3600;
        totalSeconds %= 3600;
        int newMinute = totalSeconds / 60;
        int newSecond = totalSeconds % 60;
        return Time(newHour, newMinute, newSecond);
    }

    // Function to display time in 24-hour format
    void display24Hour() const {
        cout << setw(2) << setfill('0') << hour << ":"
             << setw(2) << setfill('0') << minute << ":"
             << setw(2) << setfill('0') << second << endl;
    }

    // Function to display time in 12-hour format
    void display12Hour() const {
        int displayHour = hour % 12;
        if (displayHour == 0) displayHour = 12;
        string period = (hour >= 12) ? "PM" : "AM";

        cout << setw(2) << setfill('0') << displayHour << ":"
             << setw(2) << setfill('0') << minute << ":"
             << setw(2) << setfill('0') << second << " " << period << endl;
    }
};

int main() {
    // Create time objects
    Time t1(14, 30, 45); // 14:30:45
    Time t2(9, 45, 15);  // 09:45:15

    // Display original times
    cout << "Time 1 (24-hour format): ";
    t1.display24Hour();
    cout << "Time 1 (12-hour format): ";
    t1.display12Hour();
    
    cout << "Time 2 (24-hour format): ";
    t2.display24Hour();
    cout << "Time 2 (12-hour format): ";
    t2.display12Hour();

    // Add times and display the result
    Time t3 = t1.add(t2);
    cout << "Sum of Time 1 and Time 2 (24-hour format): ";
    t3.display24Hour();
    cout << "Sum of Time 1 and Time 2 (12-hour format): ";
    t3.display12Hour();

    return 0;
}
