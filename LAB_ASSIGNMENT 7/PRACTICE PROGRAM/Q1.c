#include <stdio.h>
#include <conio.h>
#define max 10
typedef struct queue
{
    int item[max];
    int front, rear;
} QUEUE;

void initQueue(QUEUE *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(QUEUE *q)
{
    return (q->front == -1 && q->rear == -1) ? 1 : 0;
}

int isFull(QUEUE *q)
{
    return ((q->rear + 1) % max == q->front) ? 1 : 0;
}

void insert(QUEUE *q, int n)
{
    if (isFull(q))
    {
        printf("\n The Queue is full!");
    }
    else
    {
        if (isEmpty(q))
        {
            q->front++;
            q->rear++;
            q->item[q->rear] = n;
        }
        else
        {
            q->rear = (q->rear + 1) % max;
            q->item[q->rear] = n;
        }
    }
}

void delete(QUEUE *q)
{
    int n;
    if (isEmpty(q))
    {
        printf("\n The Queue is Empty!");
    }
    else
    {
        if (q->front == q->rear)
        {
            n = q->item[q->front];
            q->front = q->rear = -1;
            printf("\n The deleted element is:%d", n);
        }
        else
        {
            n = q->item[q->front];
            q->front = (q->front + 1) % max;
            printf("\n The deleted element is:%d", n);
        }
    }
}

void display(QUEUE *q)
{
    int i;
    for (i = q->front; i != q->rear; i = (i + 1) % max)
    {
        printf("\t%d", q->item[i]);
    }
    printf("\t%d", q->item[i]);
}

int peek(QUEUE *q)
{
    int p;
    p = q->item[q->front];
    return p;
}
int main()
{
    int n, choice, p;
    QUEUE q;
    initQueue(&q);
    do
    {
        printf("\n----------------");
        printf("\n1.insert\n2.delete\n3.display\n4.Exit");
        printf("\n----------------");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter for insert:");
            scanf("%d", &n);
            insert(&q, n);
            break;
        case 2:
            delete (&q);
            break;
        case 3:
            if (!isEmpty(&q))
            {
                printf("\n The Queue is:\n");
                display(&q);
            }
            else
            {
                printf("\n Queue is Empty!");
            }
            break;
        case 4:
            p = peek(&q);
            printf("\n The peek element is:%d", p);
            break;
        }
    } while (choice != 5);
    getch();
    return 0;
}