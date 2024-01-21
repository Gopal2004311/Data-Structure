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
void insertion_sort(char a[][20],int n)
{
    int i,j;
    char temp[20];
    for(i=0;i<n;i++)
    {
        strcpy(temp,a[i]);
        for(j=i-1;j>=0&&strcmp(a[j],temp)>0;j--)
        {
            strcpy(a[j+1],a[j]);
        }
       strcpy(a[j+1],temp);
    }
}
void binary_search(char a[][20],int first,int last,char key[])
{
    int mid;
    while(first<=last)
    {
        mid=(first+last)/2;
        if(strcmp(a[mid],key)==0)
        {
            printf("\nThe %s element are founded at %d index.",key,mid);
            break;
        }
        if(strcmp(a[mid],key)>0)
        {
            last=mid-1;
        }
        if(strcmp(a[mid],key)<0)
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
    char a[10][20],key[20];
    int n;
    printf("\n Enter size of array:");
    scanf("%d",&n);
    a[0][20]=create(a,n);
    printf("\n The array is:");
    display(a,n);
    insertion_sort(a,n);
    printf("\n The sorted array is:");
    display(a,n);
    printf("\n Enter search key:");
    scanf("%s",&key);
    binary_search(a,0,n-1,key);
    getch();
    return 0;
}