//Write a program to accept a number from user using command line argument and display its table.
#include <stdio.h>
void printTable(int num){
 for(int i=1; i<=10; i++){
    printf("%d\n", num*i);
 }
}
int main(){
    int num;
    printf("Enter the numer to print the table.\n");
    scanf("%d",&num);
    printTable(num);
    return 0;
}