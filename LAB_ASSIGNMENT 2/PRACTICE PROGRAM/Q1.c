#include <stdio.h>
#include <conio.h>
int main()
{
    int a[] = {56, 23, 11, 67, 12, 89, 2};
    int i;
    int temp, pass;
    printf("\n the input array is: ");
    for (i = 0; i < 7; i++)
    {
        printf("\t%d", a[i]);
    }

    for (pass = 1; pass < 7; pass++)
    {
        for (i = 0; i < 7 - pass; i++)
        {
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
    printf("\n the sorted array is:");
    for (i = 0; i < 7; i++)
    {
        printf("\t %d", a[i]);
    }
}