#include <stdio.h>
#include <conio.h>
int main()
{
    int a[10], n, i, j, temp;
    printf("\n enter array limit:");
    scanf("%d", &n);
    printf("\n enter array elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 1; i < n; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0 && a[j] > temp; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
    printf("\n sorted array is:");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
}