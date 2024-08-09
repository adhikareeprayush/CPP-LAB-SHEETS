#include <iostream>
#include <iomanip> // For std::setw, std::setprecision
using namespace std;

// Custom manipulator function
class CustomFormat {
public:
    CustomFormat(int w, int p, char f) : width(w), precision(p), fillChar(f) {}

    friend ostream& operator<<(ostream& os, const CustomFormat& cf) {
        os << setw(cf.width) << setfill(cf.fillChar) << fixed << setprecision(cf.precision);
        return os;
    }

private:
    int width;
    int precision;
    char fillChar;
};

int main() {
    double price1 = 123.456789;
    double price2 = 78.9;

    // Using the custom manipulator
    cout << "Formatted Prices:" << endl;

    // Applying custom formatting
    cout << CustomFormat(15, 2, '*') << price1 << endl;
    cout << CustomFormat(15, 2, '.') << price2 << endl;

    return 0;
}
