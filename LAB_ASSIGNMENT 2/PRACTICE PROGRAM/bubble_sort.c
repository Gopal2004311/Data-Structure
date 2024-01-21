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
void bubble_sort(int a[],int n)
{
    int pass,temp,i;
    for(pass=1;pass<n ;pass++)
    {
        for(i=0;i<n-pass;i++)
        {
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
}
int main(){
    int a[20],i,n;
    printf("\n Enter size of array:");
    scanf("%d",&n);
    a[0]=create(a,n);
    printf("\n The original array is:");
    display(a,n);
    bubble_sort(a,n);
    printf("\n The sorted array is:");
    display(a,n);
    getch();
    return 0;
}