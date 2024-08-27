/* Write a menu driven program for Student in CPP language. Create a class student with data 
members roll no, name and marks. Implement the following functions
void initStudent();
void printStudentOnConsole();
void acceptStudentFromConsole();*/

#include <iostream>
#include <string>
using namespace std;

// Define the Student class
class Student {
private:
    int rollNo;
    string name;
    float marks;

public:
    // Constructor to initialize student data
    Student() {
        rollNo = 0;
        name = "Unknown";
        marks = 0.0;
    }

    // Function to initialize a student
    void initStudent() {
        rollNo = 0;
        name = "Unknown";
        marks = 0.0;
    }

    // Function to accept student data from the console
    void acceptStudentFromConsole() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cin.ignore(); // to supress the enter character 
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    // Function to print student data to the console
    void printStudentOnConsole() const {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student student;
    int choice;

    do {
        cout << "\n--- Student Menu ---\n";
        cout << "1. Initialize Student\n";
        cout << "2. Accept Student Data\n";
        cout << "3. Print Student Data\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                student.initStudent();
                cout << "Student data initialized to default values.\n";
                break;
            case 2:
                student.acceptStudentFromConsole();
                break;
            case 3:
                student.printStudentOnConsole();
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
