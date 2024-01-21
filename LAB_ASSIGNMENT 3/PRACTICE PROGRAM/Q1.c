#include <stdio.h>
#include <conio.h>
void merge(int a[], int first, int mid, int last)
{
    int i, j, k, b[20];
    i = first;
    j = mid + 1;
    k = 0;
    while (i <= mid && j <= last)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= mid)

    {

        b[k++] = a[i++];
    }

    while (j <= last)

    {

        b[k++] = a[j++];
    }
    for (j = first, k = 0; j <= last; j++, k++)

    {

        a[j] = b[k];
    }
}
void merge_sort(int a[], int first, int last)
{
    int mid;
    if (first < last)
    {
        mid = (first + last) / 2;
        merge_sort(a, first, mid);
        merge_sort(a, mid + 1, last);
        merge(a, first, mid, last);
    }
}
int main()
{
    int a[] = {888, 111, 666, 444, 222, 999, 333};
    int i;
    printf("\n the unsorted array is:");
    for (i = 0; i < 7; i++)
    {
        printf("\t%d", a[i]);
    }

    merge_sort(a, 0, 6);
    printf("\n the sorted array is:");
    for (i = 0; i < 7; i++)
    {
        printf("\t%d", a[i]);
    }
}