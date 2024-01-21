#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct queue
{
    int data;
    struct queue *next;
} QUEUE;

QUEUE *rear = NULL;
int isEmpty(QUEUE *q)
{
    return (q == NULL) ? 1 : 0;
}

QUEUE *insert(QUEUE *q, int n)
{
    QUEUE *new_node;
    new_node = (QUEUE *)malloc(sizeof(QUEUE));
    new_node->next = NULL;
    new_node->data = n;
    if (isEmpty(q))
    {
        q = rear = new_node;
        return q;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
        return q;
    }
}

QUEUE *delete(QUEUE *q)
{
    int n;
    QUEUE *temp = q;
    if (isEmpty(q))
    {
        printf("\n The Queue is empty!");
        return q;
    }
    else
    {
        n = temp->data;
        q = temp->next;
        free(temp);
        printf("\n the deleted element is:%d", n);
        return q;
    }
}

void display(QUEUE *q)
{
    QUEUE *temp;
    for (temp = q; temp != NULL; temp = temp->next)
    {
        printf("\t%d", temp->data);
    }
}

int main()
{
    int n, choice;
    QUEUE *q = NULL;
    do
    {
        printf("\n------------");
        printf("\n1.insert\n2.delete\n3.display\n4.Exit");
        printf("\n------------");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter element for inserting:");
            scanf("%d", &n);
            q = insert(q, n);
            break;
        case 2:
            q = delete (q);
            break;
        case 3:
            if (!isEmpty(q))
            {
                printf("\nThe Queue is:\n");
                display(q);
            }
            else
            {
                printf("\n Queue is Empty!");
            }
            break;
        }
    } while (choice != 4);
    getch();
    return 0;
}
