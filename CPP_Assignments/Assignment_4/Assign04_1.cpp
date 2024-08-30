/*Q1. Create a class Date with data memebrs day,month and year.
Cretae a class Person with data members name,address and birthdate. The birthdate shoud be of
type Date.
Implement above classes. Test all functionalities in main().*/

#include <iostream>
using namespace std;

enum EMenu
{
    ACCEPT_INFO = 1,
    DISPLAY_INFO,
    EXIT
};

class Date
{
private:
    int day;
    int month;
    int year;

public:
    // Constructor
    Date()
    {
    }

    // Setters
    //  void setDay(int day){this->day = day;}
    //  void setMonth(int month){this->month;}
    //  void setYear(int year){this->year;}

    // Getters
    // int getDay(){return day;}
    // int getMonth(){return month;}
    // int getYear(){return year;}

    // Function to accept date
    void acceptDate()
    {
        cout << "Enter the day, month, year" << endl;
        cin >> day >> month >> year;
    }

    // Function to display date
    void displayDate()
    {
        cout << " " << day << "/" << month << "/" << year << endl;
    }
};

class Person
{
private:
    string name;
    string address;
    Date dob;

public:
    // Constructors
    Person()
    {
        this->name = "";
        this->address = "";
    }
    Person(string name, string address)
    {
        this->name = name;
        this->address = address;
    }

    // Setters
    //  void setName(string name){this->name = name;}
    //  void setAddress(string address){this->address = address;}
    //  void setDate(Date dob){this->name = name;}

    // Getters
    //  string getName(){return this->name;}
    //  string getAddress(){return this->address;}
    //  string getName(){return this->name;}

    void displayInfo()
    {
        cout << "\nDisplaying Information :" << endl;
        cout << "Name :" << this->name << endl;
        cout << "Address :" << this->address << endl;
        cout << "Date of Birth : ";
        dob.displayDate();
    }

    void acceptInfo()
    {
        cout << "Enter the Name of person : ";
        cin >> this->name;
        cin.ignore();
        cout << "Enter the Address of person : ";
        getline(cin,this->address);
        cout << "Enter the DOB of person : ";
        dob.acceptDate();
    }
};

int menu()
{
    int choice;
    cout << "\n-----Menu--------\n" << endl;
    cout << "1. Accept Person Information" << endl;
    cout << "2. Display Person Information" << endl;
    cout << "3. EXIT" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    return choice;
}

int main()
{
    Person p1;
    int choice;
    do
    {
        choice = menu();
        switch (choice)
        {
        case ACCEPT_INFO:
            p1.acceptInfo();
            break;
        case DISPLAY_INFO:
            p1.displayInfo();
            break;
        case EXIT:
            cout << "Exiting the program...";
            break;
        default:
            cout << "Invalid Choice, please enter valid choice!";
            break;
        }
    } while (choice != EXIT);
    return 0;
}