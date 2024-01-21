/*4) Write C Program to print alternative nodes in linked list using recursion.*/
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
void display_alter(NODE*list){
    NODE *temp1,*temp2,*temp3;
    temp1=list;
    temp2=temp1->next;
    temp3=temp2->next;
    do 
    {
        printf("\t%d",temp1->data);
        printf("\t%d",temp3->data);
        printf("\t%d",temp2->data);
        temp1=temp3->next;
        temp2=temp1->next;
        temp3=temp2->next;
    }while((temp1!=NULL));
    
}
int main()
{
    NODE*list=NULL;
    list=create_list(list);
    printf("\n The list is:\n");
    display(list);
    printf("\n The alternative nodes of list is:\n");
    display_alter(list);

}