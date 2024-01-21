/*sort data using bubble sort in descending order!*/
#include <stdio.h>
#include <conio.h>
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
}
void bubble_sort(int a[], int n)
{
    int temp, pass, i;
    for (pass = 1; pass < n - 1; pass++)
    {
        for (i = 0; i < n - pass; i++)
        {
            if (a[i] < a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}
int main()
{
    int a[20], i, n;
    printf("\n Enter array limit:");
    scanf("%d", &n);
    printf("\n Enter array elements:");
    for (i = 0; i < n; i++)
    {
        printf("\nEnter[%d]index element:",i);
        scanf("%d", &a[i]);
    }
    printf("\n The original array is:\n");
    display(a, n);
    bubble_sort(a, n);
    printf("\n The sorted array by descending order:\n");
    display(a,n);
}