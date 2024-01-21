/*1) Write a C program to find intersection of two singly linked lists.*/
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
    NODE *temp = list, *new_node;
    int i, n;
    printf("\n Enter how many elements you want in list:");
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
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }
    return list;
}
void display(NODE *list)
{
    while (list != NULL)
    {
        printf("\t%d", list->data);
        list = list->next;
    }
}
int count(NODE *list)
{
    int count = 0;
    while (list != NULL)
    {
        count++;
        list = list->next;
    }
    return count;
}
NODE *insert_End(NODE *list, int n)
{
    NODE *temp, *new_node;
    new_node = (NODE *)malloc(sizeof(NODE));
    new_node->next = NULL;
    new_node->data = n;
    for (temp = list; temp != NULL; temp = temp->next);
    if (list == NULL)
    {
        list = temp = new_node;
    }
    else
    {
        temp->next = new_node;
        temp = new_node;
    }
    return list;
}
NODE *intersection(NODE *list1, NODE *list2, NODE *list3, int size1, int size2)
{
    NODE *temp, *temp1;
    int i, j;
    for (i = 1, temp = list1; i <= size1 && temp != NULL; i++, temp = temp->next)
    {
        for (j = 1, temp1 = list2; j <= size2 && temp1 != NULL; j++, temp1 = temp1->next)
        {
            if (temp->data == temp1->data)
            {
                list3 = insert_End(list3, temp->data);
            }
        }
    }
    return list3;
}
int main()
{
    NODE *list1 = NULL, *list2 = NULL, *list3 = NULL;
    int s1, s2;
    list1 = create_list(list1);
    list2 = create_list(list2);
    printf("\n First list is:\n");
    display(list1);
    s1 = count(list1);
    printf("\n Second list is:\n");
    display(list2);
    s2 = count(list2);
    list3 = intersection(list1, list2, list3, s1, s2);
    printf("\n Intersection of two list are:\n ");
    display(list3);
    getch();
    return 0;
}