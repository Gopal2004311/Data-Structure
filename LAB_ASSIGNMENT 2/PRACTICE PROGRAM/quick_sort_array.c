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
void quick_sort(int a[],int first,int last)
{
    int j;
    if(first<last)
    {
        j=partition(a,first,last);
        quick_sort(a,first,j-1);
        quick_sort(a,j+1,last);
    }
}
int partition(int a[],int first,int last)
{
    int pivot,i,j,temp;
    pivot=a[first];
    i=first+1;
    j=last;
    do
    {
        while (a[i]<pivot&&i<=last)
        {
            i++;
        }
        while (a[j]>pivot&&j>first)
        {
            j--;
        }
        if(i<j)
        {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;  
        } 
    }while(i<j);
    a[first]=a[j];
    a[j]=pivot;
    return j;
}
int main()
{
    int a[20],i,n;
    printf("\n Enter size of array:");
    scanf("%d",&n);
    a[0]=create(a,n);
    printf("\n The original array is:");
    display(a,n);
    quick_sort(a,0,n);
    printf("\n The sorted array is:");
    display(a,n);
    getch();
    return 0;
}