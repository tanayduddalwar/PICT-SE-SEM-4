#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Class to represent a student
class Student {
private:
    int rollNumber;
    string name;
    string division;
    string address;

public:
  
    Student(int roll, const string& n, const string& div, const string& addr) : rollNumber(roll), name(n), division(div), address(addr) {}

    
    int getRollNumber() const { return rollNumber; }
    string getName() const { return name; }
    string getDivision() const { return division; }
    string getAddress() const { return address; }
};

// Function to add student information to the file
void addStudent(const Student& student) {
    ofstream file("students.txt", ios::app);
    if (!file) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    // Write student information to the file
    file << student.getRollNumber() << " " << student.getName() << " " << student.getDivision() << " " << student.getAddress() << endl;
    file.close();

    cout << "Student information added successfully." << endl;
}

// Function to display information of a particular student
void displayStudent(int rollNumber) {
    ifstream file("students.txt");
    if (!file) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    int roll;
    string name, division, address;
    bool found = false;

    // Read student information from the file and search for the specified roll number
    while (file >> roll >> name >> division >> address) {
        if (roll == rollNumber) {
            found = true;
            cout << "Roll Number: " << roll << endl;
            cout << "Name: " << name << endl;
            cout << "Division: " << division << endl;
            cout << "Address: " << address << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student with roll number " << rollNumber << " not found." << endl;
    }

    file.close();
}

// Function to delete information of a particular student
void deleteStudent(int rollNumber) {
    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    ofstream outFile("temp.txt");
    if (!outFile) {
        cerr << "Error: Unable to open temporary file for writing." << endl;
        inFile.close();
        return;
    }

    int roll;
    string name, division, address;
    bool found = false;

    // Read student information from the file and copy to temporary file excluding the specified roll number
    while (inFile >> roll >> name >> division >> address) {
        if (roll != rollNumber) {
            outFile << roll << " " << name << " " << division << " " << address << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    // Remove the original file and rename the temporary file
    if (remove("students.txt") != 0) {
        cerr << "Error: Failed to delete original file." << endl;
        return;
    }
    if (rename("temp.txt", "students.txt") != 0) {
        cerr << "Error: Failed to rename temporary file." << endl;
        return;
    }

    if (found) {
        cout << "Student with roll number " << rollNumber << " deleted successfully." << endl;
    } else {
        cout << "Student with roll number " << rollNumber << " not found." << endl;
    }
}

int main() {
    while (true) {
        cout << "Enter your choice:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Student Information" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int roll;
                string name, division, address;
                cout << "Enter Roll Number: ";
                cin >> roll;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Division: ";
                cin >> division;
                cout << "Enter Address: ";
                cin >> address;
                Student newStudent(roll, name, division, address);
                addStudent(newStudent);
                break;
            }
            case 2: {
                int rollNumber;
                cout << "Enter Roll Number to Display: ";
                cin >> rollNumber;
                displayStudent(rollNumber);
                break;
            }
            case 3: {
                int rollNumber;
                cout << "Enter Roll Number to Delete: ";
                cin >> rollNumber;
                deleteStudent(rollNumber);
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid choice." << endl;
        }
    }

    return 0;
}
