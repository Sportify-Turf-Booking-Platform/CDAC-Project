/*. Write a menu driven program for Date in a CPP language using structure.
Date is having data members day, month, year. Implement the following functions.
void initDate();
void printDateOnConsole();
void acceptDateFromConsole();
bool isLeapYear()*/

//Using Structure

#include <iostream>
using namespace std;

// Define the Date structure
struct Date {
    int day;
    int month;
    int year;

    // Function to initialize a date
    void initDate() {
        day = 1;
        month = 1;
        year = 2000;
    }

    // Function to print a date to the console
    void printDateOnConsole() {
        cout << "Date: " << (day < 10 ? "0" : "") << day << "/"
             << (month < 10 ? "0" : "") << month << "/"
             << year << endl;
    }

    // Function to accept a date from the console
    void acceptDateFromConsole() {
        cout << "\nEnter day: ";
        cin >> day;
        if(day>31){
            cout<<"\nEnter valid day!"<<endl;
            initDate();
            return;
        }
        cout << "\nEnter month: ";
        cin >> month;
        if(month>12){
            cout<<"\nEnter valid month!"<<endl;
            initDate();
            return;
        }
        cout << "\nEnter year: ";
        cin >> year;
    }

    // Function to check if a year is a leap year
    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

int main() {
    Date date;
    int choice;

    do {
        cout << "\n-----------------------------\n";
        cout << "1. Initialize Date\n";
        cout << "2. Accept Date\n";
        cout << "3. Print Date\n";
        cout << "4. Check Leap Year\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                date.initDate();
                cout << "Date initialized to default (01/01/2000).\n";
                break;
            case 2:
                date.acceptDateFromConsole();
                break;
            case 3:
                date.printDateOnConsole();
                break;
            case 4:
                if (date.isLeapYear()) {
                    cout << "Year " << date.year << " is a leap year.\n";
                } else {
                    cout << "Year " << date.year << " is not a leap year.\n";
                }
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
