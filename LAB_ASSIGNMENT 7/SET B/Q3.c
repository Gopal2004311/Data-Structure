#include <stdio.h>
#include <conio.h>
#define max 100
typedef struct queue
{
    int item[max];
    int front;
    int rear;
} QUEUE;

void initQueue(QUEUE *pq)
{
    pq->front = pq->rear = -1;
}

int isEmpty(QUEUE *pq)
{
    if (pq->front == -1 && pq->rear == -1)
        return 1;
    else
        return 0;
}

int isFull(QUEUE *pq)
{
    if ((pq->rear + 1) % max == pq->front)
        return 1;
    else
        return 0;
}

void insertQueue(QUEUE *pq, int n)
{
    if (isFull(pq))
    {
        printf("\n The Queue is full--!");
    }
    else
    {
        if (isEmpty(pq))
        {
            pq->front++;
            pq->rear++;
            pq->item[pq->rear] = n;
        }
        else
        {
            pq->rear = (pq->rear + 1) % max;
            pq->item[pq->rear] = n;
        }
    }
}

int deleteQueue(QUEUE *pq)
{
    int n;
    if (isEmpty(pq))
    {
        printf("\n The Queue is Empty!");
    }
    else
    {
        if (pq->front == pq->rear)
        {
            n = pq->item[pq->front];
            pq->front = pq->rear = -1;
        }
        else
        {
            n = pq->item[pq->front];
            pq->front = (pq->front + 1) % max;
        }
    }
    return n;
}

void display(QUEUE *pq)
{
    int i;
    i = pq->front;
    while (i != pq->rear)
    {
        printf("\t%d", pq->item[i]);
        i = (i + 1) % max;
    }
    printf("\t%d", pq->item[i]);
}

int main()
{
    int choice, n, p;
    QUEUE q1;
    initQueue(&q1);
    do
    {
        printf("\n--------------");
        printf("\n1.insert\n2.delete\n3.display\n4.Exit");
        printf("\n--------------");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter Element for inserting:");
            scanf("%d", &n);
            insertQueue(&q1, n);
            break;
        case 2:
            n = deleteQueue(&q1);
            printf("\n The deleted element is:%d", n);
            break;
        case 3:
            printf("\n The Queue is:\n");
            display(&q1);
            break;
        }
    } while (choice != 4);
    getch();
    return 0;
}