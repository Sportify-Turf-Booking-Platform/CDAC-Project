/*Write a menu driven program for Date in a C. Declare a structure Date having data members 
day, month, year. Implement the following functions.
void initDate(struct Date* ptrDate);
void printDateOnConsole(struct Date* ptrDate);
void acceptDateFromConsole(struct Date* ptrDate);*/


#include <iostream>

// Define the Date structure
struct Date {
    int day;
    int month;
    int year;
};

// Function to initialize a date
void initDate(struct Date* ptrDate) {
    ptrDate->day = 1;
    ptrDate->month = 1;
    ptrDate->year = 1900;
}

// Function to print a date to the console
void printDateOnConsole(struct Date* ptrDate) {
    printf("Date: %02d/%02d/%04d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

// Function to accept valid date from the console
void acceptDateFromConsole(struct Date* ptrDate) {
    printf("Enter day: ");
    scanf("%d", &ptrDate->day);
    if(ptrDate->day>31){
        printf("\nInvalid day entered");
        ptrDate->day = 1;
        return;
    }
    printf("Enter month: ");
    scanf("%d", &ptrDate->month);
    if(ptrDate->month>12){
        printf("\nInvalid month entered");
        ptrDate->day = 1;
        ptrDate->month =1;
        return;
    }
    printf("Enter year: ");
    scanf("%d", &ptrDate->year);
}

int main() {
    struct Date date;
    int choice;

    //menu-driven approach
    do {
        printf("\n--- Date Menu ---\n");
        printf("1. Initialize Date\n");
        printf("2. Accept Date\n");
        printf("3. Print Date\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initDate(&date);
                printf("Date initialized to default (01/01/1900).\n");
                break;
            case 2:
                acceptDateFromConsole(&date);
                break;
            case 3:
                printDateOnConsole(&date);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
