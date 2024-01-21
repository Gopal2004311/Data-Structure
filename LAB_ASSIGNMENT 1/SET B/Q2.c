#include <stdio.h>
#include <conio.h>
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
}
/*int binary_search(int a[],int first,int last,int key){
    int mid;
    while (first<=last)
    {
        mid=first+last/2;
        if (a[mid]==key)
        {
            return mid;
        }
        if (a[mid]<key)
        {
            first=mid+1;
        }
        if (a[mid]>key)
        {
            last=mid-1;
        }
    }
}
void bubble_sort(int a[], int i, int n)
{
    int temp, pass;
    for (pass = 1; pass < n; pass++)
    {
        for (i = 0; i < n - pass; i++)
        {
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}*/
int main()
{
    int a[20], n, i, key, user_value, flag = 0, r;
    printf("\n Enter how many elements you want:");
    scanf("%d", &n);
    printf("\n Enter array elements:");
    for (int i = 0; i < n; i++)
    {
        printf("\n Enter index %d element:", i);
        scanf("%d", &a[i]);
    }

    /*printf("\n The unsorted array is:");
    display(a, n);
     printf("\n The sorted array is:");
    bubble_sort(a, 0, n);
    printf("\n The sorted array is:");
    display(a, n);*/
    printf("\n Enter which element you want to find?:");
    scanf("%d", &key);
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            flag = 1;
            printf("\n The %d is found at index no.%d", key, i);
            r = i;
            break;
        }
    }
    if (flag == 0)
    {
        printf("\n Element not found!");
    }
    else
    {
        printf("\n Enter value to replace search value:");
        scanf("%d", &user_value);
        a[r] = user_value;
        printf("\n After interchanging array is: ");
        display(a, n);
    }
    /*mid=binary_search(a,0,n-1,key);


    printf("\n After interchange sorted array:");
    bubble_sort(a, 0, n);
    display(a,n);*/
}