#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *pre;
    struct node *next;
} D_QUEUE;

D_QUEUE *rear = NULL;
void initQueue(D_QUEUE *q)
{
    q = NULL;
}

int isEmpty(D_QUEUE *q)
{
    if (q == NULL)
        return 1;
    else
        return 0;
}

D_QUEUE *insertAtBeginning(D_QUEUE *q, int n)
{
    D_QUEUE *new_node;
    new_node = (D_QUEUE *)malloc(sizeof(D_QUEUE));
    new_node->next = NULL;
    new_node->pre = NULL;
    new_node->data = n;
    if (isEmpty(q))
    {
        q = new_node;
        return q;
    }
    else
    {
        q->pre = new_node;
        new_node->next = q;
        q = new_node;
        return q;
    }
}

D_QUEUE *insertAtEnd(D_QUEUE *q, int n)
{
    D_QUEUE *new_node, *temp;
    new_node = (D_QUEUE *)malloc(sizeof(D_QUEUE));
    new_node->next = NULL;
    new_node->pre = NULL;
    new_node->data = n;
    if (isEmpty(q))
    {
        q = rear = new_node;
        return q;
    }
    else
    {
        rear->next = new_node;
        new_node->pre = rear;
        rear = new_node;
        return q;
    }
}

D_QUEUE *deleteFromBeginning(D_QUEUE *q)
{
    int n;
    D_QUEUE *temp;
    if (isEmpty(q))
    {
        printf("\n The Queue is Empty!");
    }
    else
    {
        temp = q;
        n = temp->data;
        q = temp->next;
        q->pre=NULL;
        free(temp);
        printf("\n The deleted node is:%d", n);
    }
    return q;
}

D_QUEUE *deleteFromEnd(D_QUEUE *q)
{
    int n;
    D_QUEUE *temp;
    if (isEmpty(q))
    {
        printf("\n The Queue is Empty!");
    }
    else
    {
        temp=rear;
        n = temp->data;
        rear = temp->pre;
        rear->next = NULL;
        free(temp);
        printf("\n The deleted node is:%d", n);
    }
    return q;
}

void display(D_QUEUE *q)
{
    while (q != NULL)
    {
        printf("\t%d", q->data);
        q = q->next;
    }
}
int main()
{
    int n, choice;
    D_QUEUE *q;
    initQueue(q);
    do
    {
        printf("\n------------");
        printf("\n1.insert at beginning\n2.insert at End\n3.delete from beginning \n4.delete from end\n5.display\n6.Exit");
        printf("\n------------");
        printf("\n Enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter data for inserting:");
            scanf("%d", &n);
            q = insertAtBeginning(q, n);
            break;
        case 2:
            printf("\n Enter data for inserting:");
            scanf("%d", &n);
            q = insertAtEnd(q, n);
            break;
        case 3:
            q = deleteFromBeginning(q);
            break;
        case 4:
            q = deleteFromEnd(q);
            break;
        case 5:
            printf("\n The Queue is:\n");
            display(q);
            break;
        }
    } while (choice != 6);
    getch();
    return 0;
}