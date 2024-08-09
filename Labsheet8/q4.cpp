#include <iostream>
#include <fstream> // For file operations
#include <string>
using namespace std;

// Structure to store student information
struct Student {
    string name;
    string studentID;
    string department;
    string address;
};

// Function to write student information to a file
void writeToFile(const Student& student, const string& filename) {
    ofstream outFile(filename, ios::app); // Open file in append mode
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    outFile << student.name << endl
            << student.studentID << endl
            << student.department << endl
            << student.address << endl;
    outFile.close();
}

// Function to read student information from a file and display it
void readFromFile(const string& filename) {
    ifstream inFile(filename); // Open file in read mode
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    Student student;
    while (getline(inFile, student.name) &&
           getline(inFile, student.studentID) &&
           getline(inFile, student.department) &&
           getline(inFile, student.address)) {
        cout << "Name: " << student.name << endl
             << "Student ID: " << student.studentID << endl
             << "Department: " << student.department << endl
             << "Address: " << student.address << endl
             << "------------------------" << endl;
    }
    inFile.close();
}

int main() {
    Student student1;
    string filename = "students.txt";

    // Input student information
    cout << "Enter student information:" << endl;
    cout << "Name: ";
    getline(cin, student1.name);
    cout << "Student ID: ";
    getline(cin, student1.studentID);
    cout << "Department: ";
    getline(cin, student1.department);
    cout << "Address: ";
    getline(cin, student1.address);

    // Write to file
    writeToFile(student1, filename);

    // Display the information from the file
    cout << "\nRetrieving student information from file...\n";
    readFromFile(filename);

    return 0;
}
