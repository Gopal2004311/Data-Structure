#include <stdio.h>
#include <conio.h>
void selection_sort(int a[],int i,int n){
    int min, j, temp = 0;
    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}
int main()
{
    int a[10], i, n;
    printf("\n enter array limit:");
    scanf("%d", &n);
    printf("\n enter array elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    selection_sort(a,i,n);
    printf("\n the sorted array is:");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
}