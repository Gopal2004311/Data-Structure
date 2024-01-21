#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *pre;
} NODE;
NODE *create_list(NODE *list)
{
    NODE *temp, *new_node;
    int i, n;
    printf("\n Enter size of list:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        new_node = (NODE *)malloc(sizeof(NODE));
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
            new_node->pre = temp;
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
NODE *insert(NODE *list, int p, int n)
{
    NODE *temp = list, *new_node, *temp1;
    int i;
    new_node = (NODE *)malloc(sizeof(NODE));
    new_node->next = NULL;
    new_node->pre = NULL;
    new_node->data = n;
    if (p == 1)
    {
        new_node->next = temp;
        temp->pre = new_node;
        list = new_node;
        return list;
    }
    else
    {
        for (i = 1, temp = list; i < p - 1 && temp != NULL; i++, temp = temp->next)
            ;
        if (temp == NULL)
        {
            printf("\n position out of range!");
            return list;
        }
        else if (temp->next == NULL)
        {
            temp->next = new_node;
            new_node->pre = temp;
            return list;
        }
        else
        {
            temp1 = temp->next;
            new_node->next = temp1;
            temp1->pre = new_node;
            temp->next = new_node;
            new_node->pre = temp;
            return list;
        }
    }
}
NODE *delete_by_value(NODE *list, int n)
{
    NODE *temp = list, *temp1, *temp2;
    if (temp->data == n)
    {
        list = temp->next;
        temp->next->pre = NULL;
        free(temp);
        return list;
    }
        for (temp = list; temp->data != n; temp = temp->next)
            ;
         if(temp!=NULL)
        {
            temp1 = temp->pre;
            temp2 = temp->next;
            temp1->next = temp2;
            temp2->pre = temp1;
            free(temp);
            return list;
        }
        else if (temp->next == NULL)
        {
            temp->pre->next = NULL;
            temp->pre = NULL;
            free(temp);
            return list;
        }else
        {
            printf("\n Data not found!");
            return list;
        }
}

NODE *delete_by_position(NODE *list, int p)
{
    NODE *temp = list, *temp1, *temp2;
    int i;
    if (p == 1)
    {
        list = temp->next;
        temp->next->pre = NULL;
        free(temp);
        return list;
    }
    else
    {
        for (i = 1, temp = list; i < p && temp != NULL; i++, temp = temp->next)
            ;
        if (temp == NULL)
        {
            printf("\n Position out of range!");
            return list;
        }
        else
        {
            temp1 = temp->pre;
            temp2 = temp->next;
            temp1->next = temp2;
            temp2->pre = temp1;
            free(temp);
            return list;
        }
    }
}
void search(NODE *list, int n)
{
    int flag = 0;
    while (list != NULL)
    {
        if (list->data == n)
        {
            flag = 1;
            printf("\n The %d data are founded at %u node address!", n, list);
            break;
        }
        list = list->next;
    }
    if (flag == 0)
    {
        printf("\n Data not found!");
    }
}
int main()
{
    NODE *list = NULL;
    int choice, n, p;
    // clrscr();
    do
    {
        printf("\n -----------------");
        printf("\n 1.create\n2.display\n3.insert\n4.delete by value \n5.delete by position \n6.search\n7.Exit");
        printf("\n------------------");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            list = create_list(list);
            break;
        case 2:
            printf("\n The list is:\n");
            display(list);
            break;
        case 3:
            printf("\n Enter position and data for insert:");
            scanf("%d %d", &p, &n);
            list = insert(list, p, n);
            break;
        case 4:
            printf("\n Enter data for delete:");
            scanf("%d", &n);
            list = delete_by_value(list, n);
            break;
        case 5:
            printf("\n Enter position for delete a data:");
            scanf("%d",&p);
            list = delete_by_position(list, p);
            break;
        case 6:
            printf("\n Enter data for search:");
            scanf("%d", &n);
            search(list, n);
            break;
        }
    } while (choice != 7);
    getch();
    return 0;
}
