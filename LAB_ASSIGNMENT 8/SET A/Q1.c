#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100
typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
} TREE;

typedef struct queue
{
    TREE *data[MAX];
    int front, rear;
} QUEUE;

void initQueue(QUEUE *q)
{
    q->front = q->rear = -1;
}
int isEmptyQueue(QUEUE *q)
{
    return (q->front == -1 && q->rear == -1) ? 1 : 0;
}

int isFullQueue(QUEUE *q)
{
    return (q->rear == MAX - 1) ? 1 : 0;
}

void insert(QUEUE *q, TREE *t)
{
    if (isFullQueue(q))
    {
        printf("\n The Queue is Full!");
    }
    else
    {
        if (isEmptyQueue(q))
        {
            q->rear++;
            q->front++;
            q->data[q->rear] = t;
        }
        else
        {
            q->rear++;
            q->data[q->rear] = t;
        }
    }
}

void delete(QUEUE *q)
{
    if (isEmptyQueue(q))
    {
        printf("\n The Queue is Empty!");
    }
    else
    {
        if (q->front == q->rear)
        {
            initQueue(q);
        }
        else
        {
            q->front++;
        }
    }
}

TREE *peek(QUEUE *q)
{
    TREE *t = NULL;
    if (isEmptyQueue(q))
    {
        printf("\n The Queue is Empty!");
    }
    else
    {
        t = q->data[q->front];
        return t;
    }
}
int isEmpty(TREE *t)
{
    return (t == NULL) ? 1 : 0;
}
TREE *create(TREE *t)
{
    TREE *new_node, *temp;
    QUEUE *q;
    initQueue(q);
    int n, i;
    printf("\n Enter how many nodes you want:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        new_node = (TREE *)malloc(sizeof(TREE));
        printf("\n Enter [%d] node data:", i);
        scanf("%d", &new_node->data);
        new_node->left = NULL;
        new_node->right = NULL;
        if (isEmpty(t))
        {
            t = new_node;
            insert(q, t);
        }
        else
        {
            temp = peek(q);
            if (isEmpty(temp->left))
            {
                temp->left = new_node;
                insert(q, temp->left);
            }
            else
            {
                if (isEmpty(temp->right))
                {
                    temp->right = new_node;
                    insert(q, temp->right);
                    delete (q);
                }
            }
        }
    }
    return t;
}

void display(TREE *t)
{
    if (!isEmpty(t))
    {
        printf("\t%d", t->data);
        display(t->left);
        display(t->right);
    }
}

int main()
{
    TREE *t = NULL;
    t = create(t);
    printf("\n The tree is:\n");
    display(t);
    getch();
    return 0;
}
