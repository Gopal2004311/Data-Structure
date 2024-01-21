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
void linear_search(int a[],int n,int key)
{
    int flag=0,i;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            flag=1;
            printf("\n The %d element are founded at %d index.",key,i);
            break;
        }
    }
    if(flag==0)
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
    printf("\n Enter search element:");
    scanf("%d",&key);
    linear_search(a,n,key);
    getch();
    return 0;
}