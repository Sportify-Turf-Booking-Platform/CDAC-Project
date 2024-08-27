/*Read at most 10 names of students and store them into an array of 
char nameOfStudents[10][50]. Sort the array and display them back. Hint: 
Use qsort() method.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define MAX_STUDENTS 10
// #define MAX_NAME_LENGTH 50

// Function to compare two strings (used for qsort)
int compareNames(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    char nameOfStudents[10][50];
    int n, i;

    // Reading number of students
    printf("Enter the number of students (up to 10): ");
    scanf("%d", &n);
    getchar();  // to consume the newline character after scanf

    if (n > 10) {
        printf("You can enter a maximum of 10 students.\n");
        n = 10;
    }

    // Reading student names
    for (i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        fgets(nameOfStudents[i], 50, stdin);
        nameOfStudents[i][strcspn(nameOfStudents[i], "\n")] = '\0'; // Removing the newline character
    }

    // Sorting the names using qsort
    qsort(nameOfStudents, n, 50, compareNames);

    // Displaying the sorted names
    printf("\nSorted list of student names:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", nameOfStudents[i]);
    }

    return 0;
}
