#include <stdio.h>
#include <conio.h>
#define max 100
typedef struct queue
{
    int data;
    int priority;
    int rear;
} P_QUEUE;

void initQueue(P_QUEUE *q)
{
    q->rear = -1;
}

int isEmpty(P_QUEUE *q)
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

int isFull(P_QUEUE *q)
{
    if (q->rear == max - 1)
        return 1;
    else
        return 0;
}

void insert(P_QUEUE *q, int n, int p)
{
    if (isFull(q))
    {
        printf("\n The Queue is Full!");
    }
    else
    {
        q->rear++;
        q[q->rear].data = n;
        q[q->rear].priority = p;
    }
}

int delete(P_QUEUE *q, int p)
{
    int i, n, j;
    if (isEmpty(q))
        printf("\n The Queue is Empty!");
    else
    {
        for (i = 0; i < q->rear; i++)
        {
            if (q[i].priority == p)
            {
                n = q[i].data;
                break;
            }
        }
        for (j = i; j < q->rear; j++)
        {
            q[j].data = q[j + 1].data;
            q[j].priority = q[j + 1].priority;
        }
        q->rear--;
    }
    return n;
}

int getHeighPriority(P_QUEUE *q)
{
    int p, i;
    if (isEmpty(q))
    {
        printf("\n The Queue is Empty!");
    }
    else
    {
        p=q[0].priority;
        for(i=0;i<q->rear;i++)
        {
            if(q[i].priority>p)
            {
                p=q[i].priority;
            }
        }
    }
    return p;
}
void display(P_QUEUE *q)
{
    int i;
    for (i = 0; i <= q->rear; i++)
    {
        printf("\t%d", q[i].data);
    }
}
int main()
{
    P_QUEUE q[max];
    initQueue(&q);
    int choice, n, p;
    do
    {
        printf("\n---------");
        printf("\n1.insert\n2.delete\n3.Get Heigh Priority\n4.display\n5.Exit");
        printf("\n---------");
        printf("\n Enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isFull(&q))
                printf("\n The Queue is Full!");
            else
            {
                printf("\n Enter data:");
                scanf("%d", &n);
                printf("\n Enter priority:");
                scanf("%d", &p);
                insert(&q, n, p);
            }
            break;
        case 2:
            if (isEmpty(&q))
            {
                printf("\n The Queue is Empty!");
            }
            else
            {
                p = getHeighPriority(&q);
                n = delete (&q, p);
                printf("\n The deleted element is:%d", n);
            }
            break;
        case 3:
            p = getHeighPriority(&q);
            printf("\n The heigh priority is:%d", p);
            break;
        case 4:
            printf("\n The Queue is:\n");
            display(&q);
            break;
        }
    } while (choice != 5);
    getch();
    return 0;
}