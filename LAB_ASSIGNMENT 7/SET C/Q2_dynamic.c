#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    int priority;
    struct node *next;
} QUEUE;
QUEUE *rear = NULL;

int isEmpty(QUEUE *q)
{
    return (q == NULL) ? 1 : 0;
}
QUEUE *insert(QUEUE *q, int n, int p)
{
    QUEUE *new_node;
    new_node = (QUEUE *)malloc(sizeof(QUEUE));
    new_node->data = n;
    new_node->priority = p;
    new_node->next = NULL;
    if (isEmpty(q))
    {
        q = rear = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
    return q;
}

QUEUE *delete(QUEUE *q, int p)
{
    QUEUE *temp, *temp1;
    int n;
    if (isEmpty(q))
    {
        printf("\n The Queue is Empty!");
        return q;
    }
    else
    {
        if (q->priority == p)
        {
            temp = q;
            n = temp->data;
            q = temp->next;
            free(temp);
            printf("\n The deleted node data is:%d", n);
            return q;
        }
        else
        {
            for (temp = q; temp->next->priority != p; temp = temp->next)
                ;
            temp1 = temp->next;
            n = temp1->data;
            temp->next = temp1->next;
            free(temp1);
            printf("\n The deleted node data is:%d", n);
            return q;
        }
    }
}

int getHeighPriority(QUEUE *q)
{
    int p;
    QUEUE *temp = q;
    p = temp->priority;
    for (temp = q; temp != NULL; temp = temp->next)
    {
        if (temp->priority < p)
        {
            p = temp->priority;
        }
    }
    return p;
}

void display(QUEUE *q)
{
    QUEUE *temp;
    printf("\nQueue:\t");
    for (temp = q; temp != NULL; temp = temp->next)
    {
        printf("\t%d", temp->data);
    }
    printf("\nPriority:");
    for (temp = q; temp != NULL; temp = temp->next)
    {
        printf("\t%d", temp->priority);
    }
}
int main()
{
    QUEUE *q = NULL;
    int p, n, choice;
    do
    {
        printf("\n-------------");
        printf("\n1.Insert\n2.Delete\n3.Get heigh priority\n4.Display\n5.Exit");
        printf("\n-------------");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter data:");
            scanf("%d", &n);
            printf("\n Enter priority:");
            scanf("%d", &p);
            q = insert(q, n, p);
            break;
        case 2:
            if (!isEmpty(q))
            {
                p = getHeighPriority(q);
                q = delete (q, p);
            }
            else
            {
                printf("\n The Queue is Empty!");
            }
            break;
        case 3:
            if (!isEmpty(q))
            {
                p = getHeighPriority(q);
                printf("\n The heigh priority is:%d", p);
            }
            else
            {
                printf("\n The Queue is Empty!");
            }
            break;
        case 4:
            if (!isEmpty(q))
            {
                printf("\n The Queue is:\n");
                display(q);
            }
            else
            {
                printf("\n The Queue is Empty!");
            }
            break;
        }
    } while (choice != 5);
    getch();
    return 0;
}