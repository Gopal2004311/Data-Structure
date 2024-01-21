/*sort an array elements in descending order using insertion sort*/
#include <stdio.h>
#include <conio.h>
int create(int a[], int n)
{ 
    int i;
    printf("\n Enter array elements:");
    for (i = 0; i < n; i++)
    {
        printf("\nEnter [%d] index element:", i);
        scanf("%d", &a[i]);
    }
}
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
}
void insertion_sort(int a[], int n)
{
    int i, temp, j;
    for (i = 0; i < n; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0 && a[j] < temp; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}
int main()
{
    int a[20], i, n;
    printf("\n Enter array limit:");
    scanf("%d", &n);
    a[0] = create(a, n);
    printf("\n The original array is:\n");
    display(a, n);
    insertion_sort(a, n);
    printf("\nThe sorted array by descending order is:\n");
    display(a, n);
}