#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *insert(NODE *list, int n)
{
    NODE *new_node, *temp;
    new_node = (NODE *)malloc(sizeof(NODE));
    new_node->next = NULL;
    new_node->data = n;
    if (list == NULL)
    {
        list = temp = new_node;
        new_node->next = list;
    }
    else
    {
    for (temp = list; temp->next != NULL; temp = temp->next)
        ;
    temp->next = new_node;
    new_node->next = list;
    }
    return list;
}

NODE *delete(NODE *list)
{
    int n;
    NODE *temp;
    temp = list;
    if (list == NULL)
    {
        printf("\nlist is null!");
    }
    else
    {
        n = temp->data;
        list = temp->next;
        free(temp);
        printf("\n The delete is:%d", n);
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

int main()
{
    int ch, n;
    NODE *list = NULL;
    do
    {
        printf("\n------");
        printf("\n1.insert\n2.delete\n3.display\n4.exit");
        printf("\n------");
        printf("\n Enter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter data:");
            scanf("%d", &n);
            list = insert(list, n);
            break;
        case 2:
            list = delete (list);
            break;
        case 3:
            printf("\n The list is:\n");
            display(list);
            break;
        }
    } while (ch != 4);
    getch();
    return 0;
}