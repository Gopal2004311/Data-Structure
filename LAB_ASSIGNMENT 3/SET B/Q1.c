/*1) Write a C program to create a string array with months (accept atleast 6 month) and sort
them using Quick sort.*/
#include <stdio.h>
#include <conio.h>
#include <string.h>

void display(char a[][30], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\t%s", a[i]);
    }
}
int partition(char a[][30], int first, int last)
{
    char pivot[10], temp[20];
    strcpy(pivot, a[first]);
    int i, j;
    i = first + 1;
    j = last;

    do
    {
        while (strcmp(pivot, a[i]) > 0 && i < last)
        {
            i++;
        }
        while (strcmp(a[j], pivot) > 0 && j > first)
        {
            j--;
        }
        if (i < j)
        {
            strcpy(temp, a[i]);
            strcpy(a[i], a[j]);
            strcpy(a[j], temp);
        }
    } while (i < j);

    strcpy(a[first], a[j]);
    strcpy(a[j], pivot);
    return j;
}
void quick_sort(char a[][30], int first, int last)
{
    int j;
    if (first < last)
    {
        j = partition(a, first, last);
        quick_sort(a, first, j - 1);
        quick_sort(a, j + 1, last);
    }
}
int main()
{
    char month[12][30];
    int i, n;
    printf("\n Enter how many months you want to store in array:");
    scanf("%d", &n);
    printf("\nEnter months of the year:");
    for (i = 0; i < n; i++)
    {
        printf("\nEnter [%d] index month:", i);
        scanf("%s", &month[i]);
    }

    printf("\nThe un-sorted string array is:\n");
    display(month, n);
    quick_sort(month, 0, n - 1);
    printf("\nThe sorted string array is:\n");
    display(month, n);
}