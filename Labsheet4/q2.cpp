#include <iostream>
#include <cstring> // for strlen, strcpy, strcat
using namespace std;

class DynamicString {
private:
    char* str; // Pointer to dynamically allocated character array

public:
    // Default constructor
    DynamicString() : str(nullptr) {}

    // Parameterized constructor
    DynamicString(const char* initStr) {
        if (initStr) {
            str = new char[strlen(initStr) + 1];
            strcpy(str, initStr);
        } else {
            str = new char[1];
            str[0] = '\0';
        }
    }

    // Destructor
    ~DynamicString() {
        delete[] str;
    }

    // Function to concatenate two DynamicString objects
    static DynamicString join(const DynamicString& s1, const DynamicString& s2) {
        // Calculate new length
        size_t newLength = strlen(s1.str) + strlen(s2.str) + 1;
        char* newStr = new char[newLength];

        // Copy strings
        strcpy(newStr, s1.str);
        strcat(newStr, s2.str);

        // Create new DynamicString object
        DynamicString result(newStr);
        delete[] newStr; // Free the temporary allocated memory
        return result;
    }

    // Function to display the string
    void display() const {
        cout << str << endl;
    }
};

int main() {
    // Create DynamicString objects
    DynamicString s1("Engineers are");
    DynamicString s2(" Creatures of logic");

    // Concatenate strings
    DynamicString result = DynamicString::join(s1, s2);

    // Display concatenated result
    cout << "Concatenated String: ";
    result.display();

    return 0;
}
