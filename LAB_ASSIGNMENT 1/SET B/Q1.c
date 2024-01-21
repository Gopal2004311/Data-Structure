#include<stdio.h>
#include<conio.h>
int main(){
    int a[10],i,n;
    int p,c;
    
    printf("\n enter a limit:");
    scanf("%d",&n);
    printf("\n enter polynomial values:");
    for ( i = 0; i < n; i++)
    {
        printf("\n enter power&coefficient:");
        scanf("%d %d",&p,&c);
        a[p]=c;
    }

    printf("\n polynomial is:");
    for ( i = n-1; i >=0; i--)
    {
        if (i==0)
        {
            printf("%d",a[i]);
        }else{
            printf("%dx^%d+",a[i],i);
        }    
    }
    getch();
    return 0;
}