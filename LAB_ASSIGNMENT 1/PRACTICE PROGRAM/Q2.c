#include <stdio.h>
#include <conio.h>
int main()
{
    int a[10], i, n;
    int max,smax,sum=0;
    printf("\n enter array limit:");
    scanf("%d", &n);
    printf("\n enter array elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    max = a[0];
    for (i = 0; i < n; i++)
    {
        if (max<a[i])
        {
            max = a[i];
        }
    }
    printf("\n the largest element is %d",max);
   smax = a[0];
   for ( i = 0; i < n; i++)
   {
      if (a[i]!=max)
      {
          if (smax<a[i])
        {
            smax = a[i];
        }
      }
      
   }
   printf("\n second largest element is %d",smax);

   sum = max+smax;
   printf("\n sum of largest element is %d",sum);
   
     
}