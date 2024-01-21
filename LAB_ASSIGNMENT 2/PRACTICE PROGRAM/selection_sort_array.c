#include<stdio.h>
#include<conio.h>
int create(int a[],int n){
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
void selection_sort(int a[],int n)
{
    int i,j,temp,temp1;
    for(i=0;i<n;i++)
    {
        temp=a[i];
        for(j=i+1;j<n;j++)
        {
            if(a[j]<temp)
            {
                temp1=temp;
                temp=a[j];
                a[j]=temp1;
            }
        }
        a[i]=temp;
    }
}
int main()
{
    int a[20],i,n;
    printf("\n Enter size of array:");
    scanf("%d",&n);
    a[0]=create(a,n);
    printf("\n The original array is:");
    display(a,n);
    selection_sort(a,n);
    printf("\n The sorted array is:");
    display(a,n);
    getch();
    return 0;
}