#include<stdio.h>
#include<conio.h>
#include<string.h>
#define l 5
void display(char a[][30],int i){
    for ( i = 0; i < l; i++)
    {
        printf("\t%s",a[i]);
    }
    printf("\n");
    
}
int main(){
    char a[l][30],temp[30];
    int i,pass;
    printf("\n enter %d vowel alphabet started string's:",l);
    for ( i = 0; i < l; i++)
    {
       scanf("%s",&a[i]);
    }
    printf("\n the unsorted string array is:");
    display(a,i);

    for ( pass=0;pass<l;pass++)
    {
        for ( i=0;i<pass;i++)
        {
            if (strcmp(a[i],a[i+1])>0)
            {
                strcpy(temp,a[i]);
                strcpy(a[i],a[i+1]);
                strcpy(a[i+1],temp);
            }
            
        }
        
    }
    printf("\n the sorted array is:");
    display(a,i);
    
    
}