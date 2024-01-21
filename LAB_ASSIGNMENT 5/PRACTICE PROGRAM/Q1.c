/*1) Write a C Program to find largest element of doubly linked list*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *pre;
    int data;
    struct node *next;
} NODE;

NODE *create_list(NODE *list)
{
    NODE *temp = list, *new_node;
    int n, i;
    printf("\n Enter how many nodes:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        new_node = (NODE *)malloc(sizeof(struct node));
        new_node->next = NULL;
        new_node->pre = NULL;
        printf("\n Enter [%d] node data:", i);
        scanf("%d", &new_node->data);
        if (list == NULL)
        {
            list = temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp->next->pre = temp;
            temp = new_node;
        }
    }
    return list;
}
void display(NODE *list)
{
    NODE *temp=list;
    int max=temp->data;
    while(temp!=NULL)
    {
    printf("\t%d",temp->data);
    temp=temp->next;
    }
}
int count(NODE*list)
{
    int n=0;
    while (list!=NULL)
    {
        n++;
        list=list->next;
    }
    return n;
    
}
int largest(NODE*list)
{
    int max;
    NODE*temp=list;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    max=temp->data;
    return max;
}
void bubble_sort(NODE*list, int n)
{
    int pass,i;
    NODE*temp;
    int temp1;
    for(pass=1;pass<=n;pass++)
    {
        for(i=1,temp=list;i<=n-pass&&temp!=NULL;i++,temp=temp->next)
        {
            if(temp->data>temp->next->data)
            {
                temp1=temp->data;
                temp->data=temp->next->data;
                temp->next->data=temp1;
            }
        }
    }
}
int main()
{
    NODE *list=NULL;
    int max;
    int c;
    list=create_list(list);
    printf("\n Doubly linked list is:\n");
    display(list);
    c=count(list);
    bubble_sort(list,c);
    printf("\n The sorted list is:\n");
    display(list);
    max=largest(list);
    printf("\n The largest number in list is = %d",max);
}