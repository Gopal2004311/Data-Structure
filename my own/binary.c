#include<stdio.h>
#include<conio.h>
int main(){
    int first,last;
    int i,key,a[20],mid,n;
    printf("\n enter array limit:");
    scanf("%d",&n);
    printf("\n enter sorted array elements:");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n enter key value:");
    scanf("%d",&key);
    first=0;
    last=n-1;
    while (first<=last)
    {
       mid=(first+last)/2;
       
       if (a[mid]==key)
       {
          printf("\n the key value is founded in index no.%d",mid);
          
          break;
       }
       if (a[mid]>key)
       {
          last = mid-1;
       }
       if (a[mid]<key)
       {
         first = mid+1;
       }    
    }
    if (first>last)
    {
        printf("\n key value is does not exist!");
    }
    
    getch();
    return 0;
    
}