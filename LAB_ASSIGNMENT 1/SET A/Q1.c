#include<stdio.h>
#include<conio.h>
int main(){
    int a[10],i,n;
    int occur,count=0;
    printf("\n enter a limit:");
    scanf("%d",&n);
    printf("\n enter sorted array elements:");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n enter number for finding occurrences:");
    scanf("%d",&occur);
    for ( i = 0; i < n; i++)
    {
        if (a[i]==occur)
        {
            count++;
        }
        
    }
    printf("\n the number %d is counted up to %d times in given array.",occur,count);
    
    
}