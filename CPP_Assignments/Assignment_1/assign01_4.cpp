/*Create a namespace NStudent. Create the Student class(created as per Q3) inside namespace. 
Create the object of student and perform accept and display student.*/

#include <iostream>
#include <string>
using namespace std;

// Define the namespace NStudent
namespace NStudent {
    // Define the Student class inside the namespace
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
            cin.ignore(); // to clear the newline left in the input buffer
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
}

int main() {
    // Create an object of Student inside the NStudent namespace
    NStudent::Student student;

    // Perform operations to accept and display student data
    student.acceptStudentFromConsole();
    student.printStudentOnConsole();

    return 0;
}
