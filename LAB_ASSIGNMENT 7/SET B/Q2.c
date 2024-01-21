#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct queue
{
    int data;
    struct queue *next;
} QUEUE;

int isEmpty(QUEUE *q)
{
    if (q == NULL)
        return 1;
    else
        return 0;
}

QUEUE *insert(QUEUE *q, int n)
{
    QUEUE *new_node, *temp;
    new_node = (QUEUE *)malloc(sizeof(QUEUE));
    new_node->next = NULL;
    new_node->data = n;
    if (isEmpty(q))
    {
        temp = q = new_node;
        return q;
    }
    else
    {
        for (temp = q; temp->next != NULL; temp = temp->next)
            ;
        temp->next = new_node;
        temp = new_node;
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
        printf("\n%d", temp->data);
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

QUEUE *reverse(QUEUE *q)
{
    QUEUE *t1, *t2, *t3;
    t1 = q;
    t2 = t1->next;
    t3 = t2->next;
    t1->next = NULL;
    while (t3 != NULL)
    {
        t2->next = t1;
        t1 = t2;
        t2 = t3;
        t3 = t3->next;
    }
    t2->next = t1;
    return t2;
}
int main()
{
    int n, choice;
    QUEUE *q = NULL;
    do
    {
        printf("\n------------");
        printf("\n1.insert\n2.delete\n3.display\n4.reverse\n5.Exit");
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
            printf("\nThe Queue is:\n");
            display(q);
            break;
        case 4:
            q = reverse(q);
            break;
        }
    } while (choice != 5);
    getch();
    return 0;
}
