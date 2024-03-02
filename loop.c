#include<stdio.h>
int main()
{
    int rows=9;
    // first loop to print the no. of rows
    for ( int i = 0; i <= rows; i++)
    {
        // second loop to print the no of pattern
        for ( int j = 0; j <= i; j++)
        {
            printf("*");
        }
        // going to next line
        printf("\n");
    }
    
    return 0;
}