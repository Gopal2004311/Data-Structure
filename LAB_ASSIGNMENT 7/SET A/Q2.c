#include <stdio.h>
#include <conio.h>
#define max 100
typedef struct queue
{
    int front;
    int rear;
    int item[max];
} QUEUE;

void initQueue(QUEUE *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(QUEUE *q)
{
    if (q->front == -1 && q->rear == -1)
        return 1;
    else
        return 0;
}

int isFull(QUEUE *q)
{
    if (q->rear == max - 1)
        return 1;
    else
        return 0;
}

void insert(QUEUE *q, int n)
{
    if (isEmpty(q))
    {
        q->front++;
        q->rear++;
        q->item[q->rear] = n;
    }
    else
    {
        if (isFull(q))
        {
            printf("\n The Queue is full...!");
        }
        else
        {
            q->rear++;
            q->item[q->rear] = n;
        }
    }
}

int delete(QUEUE *q)
{
    int a;
    if (isEmpty(q))
    {
        printf("\n The Queue is Empty...!");
    }
    else
    {
        if (q->front == q->rear)
        {
            a = q->item[q->front];
            q->front = q->rear = -1;
        }
        else
        {
            a = q->item[q->front];
            q->front++;
        }
    }
    return a;
}

void display(QUEUE *q)
{
    int i;
    for (i = q->front; i <= q->rear; i++)
    {
        printf("\t%d", q->item[i]);
    }
}

void reverse(QUEUE *q)
{
    int s, i;
    s = q->front;
    q->front = q->rear;
    q->rear = s;
    printf("\n The reverse Queue is:\n");
    for (i = q->front; i >= q->rear; i--)
    {
        printf("\t%d", q->item[i]);
    }
}
int main()
{
    QUEUE q;
    int choice, n;
    initQueue(&q);
    do
    {
        printf("\n-----------------");
        printf("\n1.insert\n2.delete\n3.display\n4.reverse\n5.Exit");
        printf("\n-----------------");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter insert element:");
            scanf("%d", &n);
            insert(&q, n);
            break;
        case 2:
            n = delete (&q);
            printf("\n The deleted element is:%d", n);
            break;
        case 3:
            printf("\n The Queue is:\n");
            display(&q);
            break;
        case 4:
            reverse(&q);
            break;
        }
    } while (choice != 5);
}