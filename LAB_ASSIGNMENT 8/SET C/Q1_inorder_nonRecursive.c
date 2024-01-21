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
    TREE *item[MAX];
    int front, rear;
} QUEUE;

typedef struct stack
{
    TREE *item[MAX];
    int top;
} STACK;

int isEmpty(TREE *t)
{
    return (t == NULL) ? 1 : 0;
}

int isEmptyQueue(QUEUE *q)
{
    return (q->front == -1 && q->rear == -1) ? 1 : 0;
}

int isFullQueue(QUEUE *q)
{
    return (q->rear == MAX - 1) ? 1 : 0;
}

void initQueue(QUEUE *q)
{
    q->front = q->rear = -1;
}

void insert(QUEUE *q, TREE *t)
{
    if (isFullQueue(q))
    {
        printf("\n Queue is Full!");
    }
    else
    {
        if (q->front == -1 && q->rear == -1)
        {
            q->front++;
            q->rear++;
            q->item[q->rear] = t;
        }
        else
        {
            q->rear++;
            q->item[q->rear] = t;
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
    t = q->item[q->front];
    return t;
}
TREE *create(TREE *t)
{
    TREE *new_node, *temp;
    QUEUE *q;
    int i, n;
    initQueue(q);
    printf("\n Enter how many nodes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        new_node = (TREE *)malloc(sizeof(TREE));
        new_node->left = NULL;
        new_node->right = NULL;
        printf("\n Enter [%d] node data:", i);
        scanf("%d", &new_node->data);
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

int isEmptyStack(STACK *s)
{
    return (s->top == -1) ? 1 : 0;
}
int isFull(STACK *s)
{
    return (s->top == MAX - 1) ? 1 : 0;
}
void push(STACK *s, TREE *n)
{
    if (!isFull(s))
    {
        s->top++;
        s->item[s->top] = n;
    }
}

TREE *pop(STACK *s)
{
    TREE *n;
    if (!isEmptyStack(s))
    {
        n = s->item[s->top];
        s->top--;
    }
    return n;
}
void inOrder(TREE *t)
{
    TREE *temp;
    STACK s;
    s.top = -1;
    temp = t;

    while (!isEmpty(temp))
    {
        push(&s, temp);
        temp = temp->left;
    }

    while (!isEmptyStack(&s))
    {
        temp = pop(&s);
        printf("\t%d", temp->data);
        temp = temp->right;
        while (!isEmpty(temp))
        {
            push(&s, temp);
            temp = temp->left;
        }
    }
}
int main()
{
    int choice, n;
    TREE *t = NULL;
    do
    {
        printf("\n ---------------------");
        printf("\n1.create\n2.display\n3.in-order\n4.Exit");
        printf("\n ---------------------");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            t = create(t);
            break;
        case 2:
            printf("\n The Tree is:\n");
            display(t);
            break;
        case 3:
            printf("\n In-order traversal tree is:\n");
            inOrder(t);
            break;
        }
    } while (choice != 4);
    getch();
    return 0;
}