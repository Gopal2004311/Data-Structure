#include <stdio.h>
#include <conio.h>
    void main()
{
    int a[10], b[10], c[10];
    int n, k, i, p, coeff;
    
    for (i = 0; i < 10; i++)
        
    {
        a[i] = 0;
         b[i] = 0;
         c[i] = 0;
        
    }
    printf("\n first polynomial");
    printf("\n enter number of terms=");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        
    {
         printf("\n enter power & coefficient=");
         scanf("%d%d", &p, &coeff);
         a[p] = coeff;
        
        }
    printf("\n second polynomial");
    printf("\n enter number of terms=");
    scanf("%d",&k);
    for(i=0; i<k; i++)
         {
         printf("\n enter power & coefficient=");
         scanf("%d%d",&p,&coeff);
         b[p]=coeff;
        
    }
    for(i=0; i<10; i++)
         {
         c[i]=a[i]*b[i];
        
    }
    printf("\n polynomial subtraction is=");
    for(i=9; i>=0; i--)
         {
         if(c[i]!=0)
             {
            if(i!=0)
                {
                 printf("%dx^%d+",c[i],i);
                
            }
            else
                 {
                  printf("%dx^%d",c[i],i);
                
            }
            
        }
        
    }
getch();
}
