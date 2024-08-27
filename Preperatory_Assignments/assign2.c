//Write a program to calculate a Factorial of a number.
#include <stdio.h>
int factorial(int num){
    if(num==1 || num==0){
        return 1;
    }else {
        return num*factorial(num-1);
    }
}
int main(){
    int num;
    printf("Enter the number to find factorial? ");
    scanf("%d",&num);
    printf("%d",factorial(num));
}
