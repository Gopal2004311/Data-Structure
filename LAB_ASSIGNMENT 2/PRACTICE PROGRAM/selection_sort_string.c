#include<stdio.h>
#include<conio.h>
#include<string.h>
char create(char a[][20],int n){
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
void selection_sort(char a[][20],int n)
{
    int i,j;
    char temp[20],temp1[20];
    for(i=0;i<n;i++)
    {
        strcpy(temp,a[i]);
        for(j=i+1;j<n;j++)
        {
            if(strcmp(temp,a[j])>0)
            {
                strcpy(temp1,temp);
                strcpy(temp,a[j]);
                strcpy(a[j],temp1);
            }
        }
       strcpy(a[i],temp);
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
    selection_sort(a,n);
    printf("\n The sorted array is:");
    display(a,n);
    getch();
    return 0;
}