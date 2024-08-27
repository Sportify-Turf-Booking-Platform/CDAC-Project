//Write a program to calculate Fibonacci Series up to n numbers
#include<stdio.h>
int main(){
    int num1=0,num2=1,num3,number;
    printf("Enter the number to find the Fibonacci Series : ");
    scanf("%d",&number);
    printf("%d\t",num1);
    for(int i=0;i<number;i++){
        num3 = num1+num2;
        printf("%d\t",num3);
        num1=num2;
        num2=num3;
    }
    return 0;
}