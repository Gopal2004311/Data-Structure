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
void display(int a[],int n){
     int i;
     for(i=0;i<n;i++)
     {
        printf("\t%d",a[i]);
     }
}
void merge_sort(int a[],int first,int last)
{
    int mid;
    if(first<last)
    {
        mid=(first+last)/2;
        merge_sort(a,first,mid);
        merge_sort(a,mid+1,last);
        merge(a,first,mid,last);
    }
}
void merge(int a[],int first,int mid,int last)
{
    int b[20],i,j,k;
    i=first;
    j=mid+1;
    k=0;
    while (i<=mid&&j<=last)
    {
        if(a[i]>a[j])
        {
            b[k++]=a[j++];
        }else{
            b[k++]=a[i++];
        }
    }
    while (i<=mid)
    {
        b[k++]=a[i++];
    }
    while (j<=last)
    {
        b[k++]=a[j++];
    }
    
    for(j=first,k=0;j<=last;j++,k++)
    {
        a[j]=b[k];
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
    merge_sort(a,0,n);
    printf("\n The sorted array is:");
    display(a,n);
    getch();
    return 0;
}