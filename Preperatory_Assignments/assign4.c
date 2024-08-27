/*Write a program to calculate the grade of a student. There are five 
subjects. Marks in each subject are entered from keyboard. Assign grade 
based on the following rule:
Total Marks >= 90 Grade: Ex
90 > Total Marks >= 80 Grade: A
80 > Total Marks >= 70 Grade: B
70 > Total Marks >= 60 Grade: C
60 > Total Marks Grade: F*/

#include <stdio.h>
int main(){
    int marks[5],total_marks=0;
    printf("Enter the marks of 5 subjects: ");
    for(int i=0;i<5;i++){
        scanf("%d",&marks[i]);
        if(marks[i]>20){
            printf("\nEnter marks between 0 and 20\n");
            marks[i] = 20;
        }
    }
    for(int i=0; i<5; i++){
        total_marks = total_marks + marks[i];
    }
    if(total_marks>=90){
        printf("Total marks are: %d\tand grade is: Ex", total_marks);
    }else if(total_marks<90 && total_marks>=80){
        printf("Total marks are: %d\tand grade is: A", total_marks);
    }else if(total_marks<80 && total_marks>=70){
        printf("Total marks are: %d\tand grade is: B", total_marks);
    }else if(total_marks<70 && total_marks>=60){
        printf("Total marks are: %d\tand grade is: C", total_marks);
    }else if(total_marks<60){
        printf("Total marks are: %d\tand grade is: F", total_marks);
    }
}