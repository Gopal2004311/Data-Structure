/*3) Write C Program to find length of linked list without using recursion.*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE*create_list(NODE*list)
{
    NODE*temp=list,*new_node;
    int i,n;
    printf("\n Enter size of list:");
    scanf("%d",&n);
    for ( i = 1; i <= n; i++)
    {
        new_node=(NODE*)malloc(sizeof(NODE));
        new_node->next=NULL;
        printf("\n Enter [%d] node data:",i);
        scanf("%d",&new_node->data);
        if (list==NULL)
        {
            list=temp=new_node;
        }else{
            temp->next=new_node;
            temp=new_node;
        }
        
    }
    return list;
}
void display(NODE*list){
    while (list!=NULL)
    {
       printf("\t%d",list->data);
       list=list->next;
    }  
}
int count(NODE*list)
{
    int count=0;
    while (list!=NULL)
    {
        count++;
        list=list->next;
    }
    return count;
}
int main()
{
    NODE *list=NULL;
    int length;
    list=create_list(list);
    printf("\n The linked list is:\n");
    display(list);
    length=count(list);
    printf("\n The size of list is:%d",length);
}
