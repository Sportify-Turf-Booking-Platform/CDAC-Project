/* Write a program to perform matrix multiplication.*/
#include <stdio.h>

void matrix_multiply(int arr1, int arr2)
{
    
}
int main()
{
    int arr1[3][3], arr2[3][3], num;
    printf("Enter the values for first 3X3 matrix  \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Enter the values for second 3X3 matrix  \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }
    
    int mul[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                mul[i][j] +=  arr1[i][k] * arr2[k][j];
            }
        }
    }
    printf("Multiplied matrix is : \n");
    for(int i = 0; i < 3; i++){
        for(int j = 0;j<3;j++){
             printf("%d", mul[i][j]);
            printf("\t");
        }
       printf("\n");
    }
    return 0;
}