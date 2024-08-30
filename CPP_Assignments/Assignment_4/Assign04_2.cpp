/*Write a menu driven program for Student management.
Create a class student with data members name, gender, rollNumber(Auto generated) and array to
keep marks of three subjects.
Accept every thing from user and Print name, rollNumber, gender and percentage.
Provide global functions void sortRecords() and int searchRecords() for sorting and searching array.
In main(), create Student* arr[5] and provide facility for accept, print, search and sort.
Search function returns index of found Student, otherwise returns -1.
sortRecord sorts the students array based on roll no in descending order.*/

#include <iostream>
using namespace std;

enum EMenu
{
    ACCEPT_INFO = 1,
    DISPLAY_INFO,
    SORT,
    SEARCH,
    EXIT
};

class Student
{
private:
    string name;
    char gender;
    static int generateRollNumber;
    int rollNumber;
    double marks[3];
    double percentage;

public:
    // Constructors
    Student()
    {
        this->rollNumber = generateRollNumber++;
        this->name = "";
        this->gender = ' ';
        for (int i = 0; i < 3; i++)
        {
            this->marks[i] = 0;
        }
        this->percentage = 0;
    }

    Student(string name, char gender, double *marks,double percentage)
    {
        Student::generateRollNumber++;
        this->name = name;
        this->gender = gender;
        this->percentage = getPercetage();
        for (int i = 0; i < 3; i++)
        {
            this->marks[i] = marks[i];
        }
    }

    // Function to calculate the percentage
    double calcPercentage()
    {
        double percentage = ((this->marks[0] + this->marks[1] + this->marks[2]) * 100) / 300;
        cout<<"Percentage : "<<percentage<<endl;
        return percentage;
    }

    // Function to accept the data
    void acceptData()
    {
        cout << "Enter Name of Student : ";
        cin >> this->name;
        cout << "Enter gender of Student (M/F) : ";
        cin >> this->gender;
        this->rollNumber = Student::rollNumber;
        cout << "Enter marks for 3 subjects : " << endl;
        for (int i = 0; i < 3; i++)
        {
            cin >> this->marks[i];
        }
    }

    // Function to display the data
    void displayData()
    {
        // double percentage;
        cout << "\n\nDisplaying details : " << endl;
        cout << "Roll Number : " << this->rollNumber << endl;
        cout << "Name : " << this->name << endl;
        cout << "Gender : " << this->gender << endl;
        cout << "Marks : ";
        for (int i = 0; i < 3; i++)
        {
            cout << marks[i] << endl;
        }
        cout << "Percentage : " << this->getPercetage() << endl;
    }

    // Setters
    //  void setName(string name){
    //      this->name = name;
    //  }
    //  void setGender(char gender){
    //      this->gender = gender;
    //  }
    void setPercentage(){
        this->percentage = calcPercentage();
    }

    // Getters
    string getName()
    {
        return this->name;
    }
    char getGender()
    {
        return this->gender;
    }
    void getRollNumber()
    {
        cout<<"Roll Number";
        //return this->rollNumber;
    }
    double getPercetage()
    {
        return this->percentage;
    }
    double getMarks()
    {
        for (int i = 0; i < 3; i++)
            return this->marks[i];
    }
};

// Static member initialization
int Student::generateRollNumber = 1;


int menu()
{
    int choice;
    cout << "\n-----Menu--------\n"
         << endl;
    cout << "1. Accept Information" << endl;
    cout << "2. Display Information" << endl;
    cout << "3.Sort Data." << endl;
    cout << "4.Search Data." << endl;
    cout << "5. EXIT" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    return choice;
}

int main()
{
    Student *S = new Student[3];
    int choice;
    do
    {
        choice = menu();
        switch (choice)
        {
        case ACCEPT_INFO:
            for (int i = 0; i < 3; i++)
            {
                S[i].acceptData();
            }
            break;
        case DISPLAY_INFO:
            for (int i = 0; i < 3; i++)
            {
                S[i].displayData();
            }
            break;
        case SORT:
            //sort(S);
            continue;
        case SEARCH:
            // int rollNumber;
            // cout << "Enter a roll number : ";
            // cin >> rollNumber;
            // search(S, rollNumber);
            continue;;
        case EXIT:
            cout << "Exiting the program...";
            break;
        default:
            cout << "Invalid Choice, please enter valid choice!";
            break;
        }
    } while (choice != EXIT);
}