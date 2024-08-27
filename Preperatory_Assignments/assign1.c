// Write a program to input n numbers on command line argument and
// calculate maximum of them.

#include <stdio.h>
int main()
{
    int num;
    printf("How many numbers to accept? ");
    scanf("%d", &num);
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d", arr[i]);
    }

    int max = 0;
    for (int i = 0; i < num; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("\n Maximum is %d\n", max);
    return 0;
}