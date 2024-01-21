#include<stdio.h>
#include<conio.h>
#include<string.h>
char create(char a[][20],int n)
{
    int i;
    printf("\n Enter array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%s",&a[i]);
    }
    return a[0][20];
}
void display(char a[][20],int n){
     int i;
     for(i=0;i<n;i++)
     {
        printf("\t%s",a[i]);
     }
}
void merge_sort(char a[][20],int first,int last)
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
void merge(char a[][20],int first,int mid,int last)
{
    char b[10][20];
    int i,j,k;
    i=first;
    j=mid+1;
    k=0;
    while (i<=mid&&j<=last)
    {
        if(strcmp(a[i],a[j])>0)
        {
            strcpy(b[k++],a[j++]);
        }else{
            strcpy(b[k++],a[i++]);
        }
    }
    while (i<=mid)
    {
        strcpy(b[k++],a[i++]);
    }
    while (j<=last)
    {
        strcpy(b[k++],a[j++]);
    }
    
    for(j=first,k=0;j<=last;j++,k++)
    {
        strcpy(a[j],b[k]);
    }  
}
int main()
{
    char a[10][20];
    int i,n;
    printf("\n Enter size of array:");
    scanf("%d",&n);
    a[0][20]=create(a,n);
    printf("\n The original array is:");
    display(a,n);
    merge_sort(a,0,n);
    printf("\n The sorted array is:");
    display(a,n);
    getch();
    return 0;
}