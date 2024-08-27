// Write a Program to reverse the letters present in the given String. Do 
// not use strrev() function.

#include <stdio.h>
#include <string.h>
int main(){
    char str[10];
    printf("Enter the string: ");
    scanf("%s",&str);
   
    for(int i=strlen(str)-1; i>=0;i--){
        printf("%c",str[i]);
    }

    return 0;
}