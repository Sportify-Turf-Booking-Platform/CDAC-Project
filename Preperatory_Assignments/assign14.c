// Write a code to check if string is palindrome.
#include <stdio.h>
#include <string.h>

void checkPalindrome(char ch)
{
}

int main()
{
    char ch[50];
    int len, flag = 0;
    printf("Enter the string ");
    scanf("%s", &ch);

    for (len = 0; ch[len] != '\0'; len++)
        ;

    for (int i = 0; i < len / 2; i++)
    {
        if (ch[i] != ch[len - i - 1])
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("%s is a palindrome string.\n", ch);
    else
        printf("%s is not a palindrome string.\n", ch);

    return 0;
}