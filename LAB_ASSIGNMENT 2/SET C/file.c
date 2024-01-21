#include<stdio.h> 
 #include<conio.h> 
 #include<stdlib.h> 
 int main() 
 { 
    FILE *fp1; 
    int num;
    char a[20];
    fp1=fopen("emp.txt","r"); 
     if(fp1==NULL) 
     { 
       printf("file not found"); 
       exit(0); 
     } 
       while(!feof(fp1)) 
        { 
          fscanf(fp1,"%d%s",&num,&a); 
          printf("%d:%s\n",num,a); 
  
        } 
       fclose(fp1); 
     getch(); 
 }
