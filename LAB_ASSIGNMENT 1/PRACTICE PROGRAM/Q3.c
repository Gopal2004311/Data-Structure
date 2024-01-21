#include <stdio.h>
#include <conio.h>
void display(int a[],int n){
      int i;
     for (i = 0; i < n; i++)
    {
        printf("\t%d",a[i]);
    }
}
void combine(int a[],int b[],int c[],int n1,int n2){
    int i,j,k;
    i = 0;
    j = 0;
    k = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] > b[j])
        {
            c[k++] = b[j++];
        }
        else
        {
            c[k++] = a[i++];
        }
    }

    while (i < n1)
    {
        c[k++] = a[i++];
    }
    while (j < n2)
    {
        c[k++] = b[j++];
    }

}
void bubble_sort(int a[],int n){
    int temp,pass;
    int i;
    for ( pass = 1; pass < n; pass++)
    {
        for ( i = 0; i < n-pass; i++)
        {
            if (a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
            
        }
        
    }
    
}
int main()
{
    int a[10], b[10], c[20];
    int n1, n2, i,median;
    printf("\n Enter first array limit:");
    scanf("%d", &n1);
    printf("\n Enter second array limit:");
    scanf("%d", &n2);
    printf("\n Enter first array elements:");
    for (i = 0; i < n1; i++)
    {
        printf("\n Enter [%d] index element:", i);
        scanf("%d", &a[i]);
    }
    printf("\n Enter second array elements:");
    for (i = 0; i < n2; i++)
    {
        printf("\n Enter [%d] index element:", i);
        scanf("%d", &b[i]);
    }
    combine(a,b,c,n1,n2);
    printf("\n The combine array is:");
    display(c,n1+n2);
    bubble_sort(c,n1+n2);
    printf("\n The combine sorted array:");
   display(c,n1+n2);
    median=(n1+n2)/2;
    printf("\n The median of two sorted array is:%d",c[median]);
    getch();
    return 0;
}