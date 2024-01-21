
#include<stdio.h>
#include<conio.h>

struct data
{
   int no;
   float salary;
};

int main(){
    struct data e[2];
   for (int i = 0; i < 2; i++)
   {
     printf("\n enter a number:");
    scanf("%d",&e[i].no);
    printf("\n enter a salary:");
    scanf("%f",&e[i].salary);
   }

   for (int i = 0; i < 2; i++)
   {
    printf("\n number of employee:%d",&e[i].no);
    printf("\n salary of employee:%f",&e[i].salary);
   }
   getch();
   return 0;
   
   

}