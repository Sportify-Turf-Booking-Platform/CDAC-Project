/*Write a program to read the name of a student (studentName), roll 
Number (rollNo) and marks (totalMarks) obtained. rollNo may be an 
alphanumeric string. Display the data as read. Hint: Create a Student 
structure and write appropriate functions.*/

#include <stdio.h>
typedef struct student{
 char studentName[10];
 char rollNo[5];
 int marksObtained;
 }student;

void acceptData(student *s){
    printf("Enter the name of student: ");
    scanf("%s",&s->studentName);
    //printf("\nStudent name is : %s",t1->studentName);
    printf("Enter the roll number: ");
    scanf("%s",&s->rollNo);
    printf("Enter the Marks Obtained by student: ");
    scanf("%d",&s->marksObtained);
}
void displayData(student s){
    printf("\nName of student: %s",s.studentName);
    printf("\nRoll Number of student: %s",s.rollNo);
    printf("\nMarks of student: %d",s.marksObtained);
}
 int main(){
    student t1;
    acceptData(&t1);
    displayData(t1);
    return 0;
 }