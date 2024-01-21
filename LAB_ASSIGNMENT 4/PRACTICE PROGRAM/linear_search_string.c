#include<stdio.h>
#include<conio.h>
#include<string.h>
char create(char a[][20],int n)
{
    int i;
    printf("\n Enter array strings:");
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
void linear_search(char a[][20],int n,char key[])
{
    int flag=0,i;
    for(i=0;i<n;i++)
    {
        if(strcmp(a[i],key)==0)
        {
            flag=1;
            printf("\n The %s string are founded at %d index.",key,i);
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
    char a[10][20],key[20];
    int n;
    printf("\n Enter size of array:");
    scanf("%d",&n);
    a[0][20]=create(a,n);
    printf("\n The array is:");
    display(a,n);
    printf("\n Enter search element:");
    scanf("%s",&key);
    linear_search(a,n,key);
    getch();
    return 0;
}