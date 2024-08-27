// Write a program to check the input characters for uppercase,
// lowercase, number of digits and other characters. Display appropriate
// message.

#include <stdio.h>
void characterCheck(char ch)
{
    if (ch >= 'A' && ch < 'Z')
    {
        printf("%c is Upper case character\n", ch);
    }
    else if (ch >= 'a' && ch < 'z')
    {
        printf("%c is Lower case character\n", ch);
    }
    else if(ch>='0' && ch<='9')
    {
        printf("%c is Digit\n", ch);
    }else{
        printf("Other Character");
    }
}

int main()
{
 char ch;
 printf("Enter the character you want to check ? ");
 scanf("%c", &ch);
 characterCheck(ch);

}

// try applying logic of string
/* Take input in string format and check every letter using for loop if character is uppercase/lowercase/digit
and print the result of count accordingly
HINT : OPENED TAB IN GOOGLE CHROME*/

