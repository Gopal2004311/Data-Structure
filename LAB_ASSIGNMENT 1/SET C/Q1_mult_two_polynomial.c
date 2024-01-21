#include<stdio.h>
#include<conio.h>
int main(){
    int a[10],b[10],res[20];
    int i,j,n1,n2,c,p,k;
    printf("\n Enter size for first polynomial:");
    scanf("%d",&n1);
    printf("\n Enter size for second polynomial:");
    scanf("%d",&n2);
    printf("\n Enter values for first polynomial:");
    for ( i = 0; i < n1; i++)
    {
        printf("\n Enter [%d] coefficient and power:",i);
        scanf("%d%d",&c,&p);
        a[p]=c;
    }
    printf("\n Enter values for second polynomial:");
    for ( i = 0; i < n2; i++)
    {
        printf("\n Enter [%d] coefficient and power:",i);
        scanf("%d%d",&c,&p);
        b[p]=c;
    }
    k=0;
    if (n1>n2)
    {
        for ( i = 0; i < n2; i++)
        {
            for ( j = 0; j < n1; j++)
            {
                k=i+j;
                res[k]=a[j]*b[i];
            }
            
        }
        
    }
    else
    {
        for ( j = 0; j < n2; j++)
        {
         for ( i = 0; i < n1; i++)
            
            {
                k=i+j;
                
                
                res[k]=a[i]*b[j];
            }
            
        }
    }

    
    
    
    
    
}