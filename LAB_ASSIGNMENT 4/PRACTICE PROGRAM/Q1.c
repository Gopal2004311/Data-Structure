#include <stdio.h>
#include <conio.h>
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
}
void linear_search(int a[], int n, int key)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {

            printf("\n The %d element are founded at %d position!", key, i);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("\n the element are not exist!");
    }
}
int main()
{
    int a[10], i, n, key, search;
    printf("\n Enter the size of array:");
    scanf("%d", &n);
    printf("\n Enter array elements:");
    for (i = 0; i < n; i++)
    {
        printf("\n Enter %d index element:", i);
        scanf("%d", &a[i]);
    }

    printf("\n The array is:");
    display(a, n);
    printf("\n Enter element what you want to search:");
    scanf("%d", &key);
    linear_search(a, n, key);

    getch();
    return 0;
}