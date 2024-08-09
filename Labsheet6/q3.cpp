#include <iostream>
#include <string>
using namespace std;

// Base class Musicians
class Musicians {
protected:
    // Arrays to store different types of instruments
    string stringInstruments[5] = {"veena", "guitar", "sitar", "sarod", "mandolin"};
    string windInstruments[5] = {"flute", "clarinet", "saxophone", "nadhaswaram", "piccolo"};
    string percInstruments[5] = {"tabla", "mridangam", "bangos", "drums", "tambour"};

public:
    // Method to display string instruments
    void string() {
        cout << "String Instruments:" << endl;
        for (const auto &instrument : stringInstruments) {
            cout << "- " << instrument << endl;
        }
    }

    // Method to display wind instruments
    void wind() {
        cout << "Wind Instruments:" << endl;
        for (const auto &instrument : windInstruments) {
            cout << "- " << instrument << endl;
        }
    }

    // Method to display percussion instruments
    void perc() {
        cout << "Percussion Instruments:" << endl;
        for (const auto &instrument : percInstruments) {
            cout << "- " << instrument << endl;
        }
    }
};

// Derived class TypeIns
class TypeIns : public Musicians {
public:
    // Method to display menu and get user choice
    void get() {
        cout << "Type of instruments to be displayed:" << endl;
        cout << "a. String instruments" << endl;
        cout << "b. Wind instruments" << endl;
        cout << "c. Percussion instruments" << endl;
    }

    // Method to show instruments based on user choice
    void show() {
        char choice;
        cout << "Enter your choice (a/b/c): ";
        cin >> choice;

        switch (choice) {
            case 'a':
                string(); // Call base class method
                break;
            case 'b':
                wind(); // Call base class method
                break;
            case 'c':
                perc(); // Call base class method
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
};

int main() {
    TypeIns instruments;
    
    // Display menu and show instruments based on user choice
    instruments.get();
    instruments.show();
    
    return 0;
}
