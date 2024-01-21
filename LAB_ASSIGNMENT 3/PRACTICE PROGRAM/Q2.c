#include <stdio.h>
#include <conio.h>
int partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int temp;
    int i = lb + 1;
    int j = ub;

    do
    {
        while ((a[i] < pivot) && (i <= ub))
        {
            i++;
        }
        while ((a[j] > pivot) && (j > lb))
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    a[lb] = a[j];
    a[j] = pivot;
    return j;
}
void quick_sort(int a[], int lb, int ub)
{
    int j;
    if (lb < ub)
    {
        j = partition(a, lb, ub);
        quick_sort(a, lb, j - 1);
        quick_sort(a, j + 1, ub);
    }
}
int main()
{
    int a[10], n, i;
    printf("\n enter array limit:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\n enter element of index[%d]", i);
        scanf("%d", &a[i]);
    }
    printf("\n the unsorted array is:");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
    quick_sort(a, 0, n - 1);
    printf("\n the sorted array is:");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
}