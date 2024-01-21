/*2) Write a C Program to interchange the two adjacent nodes in given circular linked list.*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *create_list(NODE *list)
{
    NODE *temp = list, *new_node, *temp1;
    int i, n;
    printf("\n Enter size of list:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        new_node = (NODE *)malloc(sizeof(NODE));
        new_node->next = NULL;
        printf("\n Enter [%d] node data:", i);
        scanf("%d", &new_node->data);
        if (list == NULL)
        {
            list = temp = new_node;
            temp1=list;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
        if (temp->next==NULL)
        {
            temp->next=temp1;
        }
        
    }
    return list;
}
void display(NODE *list)
{
    NODE *temp = list;
    do
    {
        printf("\t%d", temp->data);
        temp = temp->next;
    } while (temp != list);
}
NODE *interchange(NODE *list)
{
     NODE *t1,*t2,*t3;
    
    t1=list;
    t2=t1->next;
    t3=t2->next;
    while (t2!=list)
    {
        t2->next=NULL;
        t2->next=t1;
        t1->next=t3;
    }
    
    return list;
}
int main()
{
    NODE *list = NULL;
    list = create_list(list);
    printf("\n The circular list is:\n");
    display(list);
    list=interchange(list);
    printf("\n After interchange two adjacent of list is:\n ");
    display(list);
    getch();
    return 0;
}
