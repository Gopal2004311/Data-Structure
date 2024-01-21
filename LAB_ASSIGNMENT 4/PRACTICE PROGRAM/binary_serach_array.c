#include<stdio.h>
#include<conio.h>
int create(int a[],int n)
{
    int i;
    printf("\n Enter array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    return a[0];
}
void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
}
void insertion_sort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0&&a[j]>temp;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
}
void binary_search(int a[],int first,int last,int key)
{
    int mid;
    while(first<=last)
    {
        mid=(first+last)/2;
        if(a[mid]==key)
        {
            printf("\nThe %d element are founded at %d index.",key,mid);
            break;
        }
        if(a[mid]>key)
        {
            last=mid-1;
        }
        if(a[mid]<key)
        {
            first=mid+1;
        }
    }
    if(first>last)
    {
        printf("\n Element not found!");
    }
}
int main()
{
    int a[20],n,key;
    printf("\n Enter size of array:");
    scanf("%d",&n);
    a[0]=create(a,n);
    printf("\n The array is:");
    display(a,n);
    insertion_sort(a,n);
    printf("\n The sorted array is:");
    display(a,n);
    printf("\n Enter search key:");
    scanf("%d",&key);
    binary_search(a,0,n-1,key);
    getch();
    return 0;
}