#include<stdio.h>
#include<conio.h>
#include<string.h>
char create(char a[][20],int n)
{
    int i;
    printf("\n Enter[%d]array strings:",n);
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
void bubble_sort(char a[][20],int n)
{
    int pass,i;
    char temp[20];
    for(pass=1;pass<n ;pass++)
    {
        for(i=0;i<n-pass;i++)
        {
            if(strcmp(a[i],a[i+1])>0)
            {
                strcpy(temp,a[i]);
                strcpy(a[i],a[i+1]);
                strcpy(a[i+1],temp);
            }
        }
    }
}
int main(){
    char a[10][20];
    int i,n;
    printf("\n Enter size of array:");
    scanf("%d",&n);
    a[0][20]=create(a,n);
    printf("\n The original array is:");
    display(a,n);
    bubble_sort(a,n);
    printf("\n The sorted array is:");
    display(a,n);
    getch();
    return 0;
}