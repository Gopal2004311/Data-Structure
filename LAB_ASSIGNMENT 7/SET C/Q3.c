#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *pre;
} QUEUE;

QUEUE *rear = NULL;
QUEUE *front = NULL;

int isEmpty(QUEUE *q)
{
    return (q == NULL) ? 1 : 0;
}
QUEUE *addFront(QUEUE *q, int n)
{
    QUEUE *new_node;
    new_node = (QUEUE *)malloc(sizeof(QUEUE));
    new_node->next = NULL;
    new_node->pre = NULL;
    new_node->data = n;
    if (isEmpty(q))
    {
        q = front = new_node;
    }
    else
    {
        new_node->next = q;
        q->pre = new_node;
        q = front = new_node;
    }
    return q;
}
QUEUE *addRear(QUEUE *q, int n)
{
    QUEUE *new_node;
    new_node = (QUEUE *)malloc(sizeof(QUEUE));
    new_node->next = NULL;
    new_node->pre = NULL;
    new_node->data = n;
    if (isEmpty(q))
    {
        q = rear = new_node;
    }
    else
    {
        rear->next = new_node;
        new_node->pre = rear;
        rear = new_node;
    }
    return q;
}
QUEUE *deleteFront(QUEUE *q)
{
    int n;
    QUEUE *temp;
    if (isEmpty(q))
    {
        printf("\n The Queue is Empty!");
    }
    else
    {
        temp = front;
        n = temp->data;
        q = front = temp->next;
        free(temp);
        q->pre = front->pre = NULL;
        printf("\n The deleted node is:%d", n);
    }
    return q;
}
QUEUE *deleteRear(QUEUE *q)
{
    int n;
    QUEUE *temp;
    if (isEmpty(q))
    {
        printf("\n The Queue is Empty!");
    }
    else
    {
        temp = rear;
        n = temp->data;
        rear = temp->pre;
        free(temp);
        rear->next = NULL;
        printf("\n The deleted node is:%d", n);
    }
    return q;
}

void display(QUEUE *q)
{

    if (!isEmpty(q))
    {
        do
        {
            printf("\t%d", front->data);
            front = front->next;
        } while (front != rear);
    }
    else
    {
        printf("\n The Queue is Empty!");
    }
}

int main()
{
    QUEUE *q = NULL;
    int choice, n;
    do
    {
        printf("\n--------------");
        printf("\n1.insert at beginning\n2.insert at End\n3.delete from beginning\n4.delete from End\n5.display\n6.Exit");
        printf("\n--------------");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter data for insert:");
            scanf("%d", &n);
            q = addFront(q, n);
            break;
        case 2:
            printf("\n Enter data for insert:");
            scanf("%d", &n);
            q = addRear(q, n);
            break;
        case 3:
            q = deleteFront(q);
            break;
        case 4:
            q = deleteRear(q);
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