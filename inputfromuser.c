#include<stdio.h>
int main()
{
    int arr[8];
    printf("enter eight integers.\n");
    for (int i=0; i<=7; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("You entered:  %d, %d, %d, %d, %d, %d, %d, %d",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]);
    return 0;
}