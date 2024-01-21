#include<stdio.h>
#include<conio.h>
#include<string.h>
void selection_sort(char a[][30],int n){
    char temp[20],temp1[20];
    int i,j;
    for ( i = 0; i < n; i++)
    {
        strcpy(temp,a[i]);
        for ( j = i+1; j < n; j++)
        {
            if (strcmp(temp,a[j])>0)
            {
                strcpy(temp1,temp);
                strcpy(temp,a[j]);
                strcpy(a[j],temp1);
            }
            
        }
        strcpy(a[i],temp);
        
    }
    
}
int main(){
    int n,i;
    printf("\n Enter string array limit:");
    scanf("%d",&n);
    char a[n][30];
    printf("\n Enter strings:");
    for ( i = 0; i < n; i++)
    { 
        scanf("%s",&a[i]);
    }

    printf("\n The unsorted string array is:\n");
    for ( i = 0; i < n; i++)
    {
        printf("\t%s",a[i]);
    }

    selection_sort(a,n);

    printf("\n The sorted array is:\n");
    for ( i = 0; i < n; i++)
    {
        printf("\t%s",a[i]);
    }
    
    
    
}