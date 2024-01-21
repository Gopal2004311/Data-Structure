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
void display(char a[][20],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\t%s",a[i]);
    }
}
void quick_sort(char a[][20],int first,int last)
{
    int j;
    if(first<last)
    {
        j=partition(a,first,last);
        quick_sort(a,first,j-1);
        quick_sort(a,j+1,last);
    }
}
int partition(char a[][20],int first,int last)
{
    int i,j;
    char pivot[20],temp[20];
    strcpy(pivot,a[first]);
    i=first+1;
    j=last;
    do
    {
        while (strcmp(a[i],pivot)<0&&i<=last)
        {
            i++;
        }
        while (strcmp(a[j],pivot)>0&&j>first)
        {
            j--;
        }
        if(i<j)
        {
            strcpy(temp,a[i]);
            strcpy(a[i],a[j]);
            strcpy(a[j],temp);
        } 
    }while(i<j);
    strcpy(a[first],a[j]);
    strcpy(a[j],pivot);
    return j;
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
    quick_sort(a,0,n);
    printf("\n The sorted array is:");
    display(a,n);
    getch();
    return 0;
}