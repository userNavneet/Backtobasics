#include<stdio.h>
int main()
{
    int arr[5];
    printf("enter five integers.\n");
    for (int i=0; i<=4; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("You entered:  %d, %d, %d, %d, %d",arr[0],arr[1],arr[2],arr[3],arr[4]);
    return 0;
}