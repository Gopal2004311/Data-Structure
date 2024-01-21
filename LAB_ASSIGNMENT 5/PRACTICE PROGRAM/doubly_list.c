#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *pre;
    struct node *next;
}NODE;

NODE*create_list(NODE*list)
{
    NODE *temp,*new_node;
    int n,i;
    printf("\n Enter size of list:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        new_node=(NODE*)malloc(sizeof(NODE));
        new_node->next=NULL;
        new_node->pre=NULL;
        printf("\n Enter [%d] node data:",i);
        scanf("%d",&new_node->data);
        if(list==NULL)
        {
            list=temp=new_node;
        }else{
            temp->next=new_node;
            new_node->pre=temp;
            temp=new_node;
        }
    }
    return list;
}
void display(NODE*list)
{
    while(list!=NULL)
    {
        printf("\t%d",list->data);
        list=list->next;
    }
}
NODE*delete(NODE*list,int n)
{
    NODE*temp=list,*temp1,*temp2;
    if(temp->data==n)
    {
        temp->next->pre=temp;
        list=temp->next;
        return list;
    }else{
        for(temp=list;temp->data!=n;temp=temp->next);
        temp1=temp->pre;
        temp2=temp->next;
        temp1->next=temp2;
        temp2->pre=temp1;
        free(temp);
        return list;
    }
}
int main()
{
    NODE*list=NULL;
    int n;
    list=create_list(list);
    printf("\n The list is:\n");
    display(list);
    printf("\n Enter value for delete:");
    scanf("%d",&n);
    list=delete(list,n);
    printf("\n After node deleted list is:\n");
    display(list);
}
