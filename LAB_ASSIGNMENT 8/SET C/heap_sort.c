#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100


typedef struct tree
{
    int data;
    struct tree *left, *right;
} TREE;

typedef struct stack
{
    TREE *data[MAX];
    int top;
} STACK;

typedef struct queue
{
    TREE *data[MAX];
    int front, rear;
} QUEUE;

int isEmptyStack(STACK *s)
{
    return (s->top == -1) ? 1 : 0;
}

int isFullStack(STACK *s)
{
    return (s->top == MAX - 1) ? 1 : 0;
}

void push(STACK *s, TREE *t)
{
    if (isFullStack(s))
    {
        printf("\n Stack is full!");
    }
    else
    {
        s->top++;
        s->data[s->top] = t;
    }
}

TREE *pop(STACK *s)
{
    TREE *t = NULL;
    if (isEmptyStack(s))
    {
        printf("\n Stack is Empty!");
    }
    else
    {
        t = s->data[s->top];
        s->top--;
    }
    return t;
}

void initQueue(QUEUE *q)
{
    q->front = q->rear = -1;
}
int isEmptyQueue(QUEUE *q)
{
    return (q->front == -1 && q->rear == -1) ? 1 : 0;
}

bool isFullQueue(QUEUE *q)
{
    return (q->rear == MAX - 1) ? true : false;
}

void insert(QUEUE *q, TREE *t)
{
    if (isFullQueue(q))
    {
        printf("\n Queue is full!");
    }
    else
    {
        if (isEmptyQueue(q))
        {
            q->front++;
            q->rear++;
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
        printf("\n Queue is Empty!");
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
    if (!isEmptyQueue(q))
    {
        t = q->data[q->front];
    }
    return t;
}

int isEmpty(TREE *t)
{
    return (t == NULL) ? 1 : 0;
}

TREE *create(TREE *t,int n)
{
    TREE *new_node, *temp;
    QUEUE*q;
    initQueue(q);
    int i;
    for (i = 0; i < n; i++)
    {
        new_node = (TREE *)malloc(sizeof(TREE));
        new_node->left = new_node->right = NULL;
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

TREE *balance(TREE *t,int n)
{
    int temp1, i;
    TREE *temp;
    STACK *s;
    s->top = -1;
    temp = t;
    i = 1;
    while (i)
    {
        while (!isEmpty(temp))
        {
            if (temp->data < temp->left->data)
            {
                temp1 = temp->left->data;
                temp->left->data = temp->data;
                temp->data = temp1;
            }
            else if (temp->data < temp->right->data)
            {
                temp1 = temp->right->data;
                temp->right->data = temp->data;
                temp->data = temp1;
            }

            if (!isEmpty(temp->right))
            {
                push(s, temp->right);
            }
            temp = temp->left;
        }

        while (!isEmptyStack(s))
        {
            temp = pop(s);
            while (!isEmpty(temp))
            {
                if (temp->data < temp->left->data)
                {
                    temp1 = temp->left->data;
                    temp->left->data = temp->data;
                    temp->data = temp1;
                }
                else if (temp < temp->right)
                {
                    temp1 = temp->right->data;
                    temp->right->data = temp->data;
                    temp->data = temp1;
                }

                if (!isEmpty(temp->right))
                {
                    push(s, temp->right);
                }
                temp = temp->left;
            }
        }
        i++;
    }
    return t;
}
TREE *heapSort(TREE *t,int n)
{
    int i, temp1;
    TREE *temp;
    STACK *s;
    s->top = -1;
    for (i = 1, temp = t; i <= n && !isEmpty(temp); i++, temp = temp->left)
    {
        t = balance(t,n);
        if (i == n)
        {
            temp1 = temp->data;
            temp->data = t->data;
            t->data = temp1;
        }

        if (!isEmpty(temp->right))
        {
            push(s, temp->right);
        }
        n = n - 1;
    }

    while (!isEmptyStack(s))
    {
        for (i = 1, temp = t; i <= n && !isEmpty(temp); i++, temp = temp->left)
        {
            t = balance(t,n);
            if (i == n)
            {
                temp1 = temp->data;
                temp->data = t->data;
                t->data = temp1;
            }

            if (!isEmpty(temp->right))
            {
                push(s, temp->right);
            }
            n = n - 1;
        }
    }
}
int main()
{
    int n;
    TREE *t = NULL;
     printf("\n Enter size of tree:");
    scanf("%d",&n);
    t = create(t,n);
    printf("\n The Tree is:\n");
    display(t);
    t = heapSort(t,n);
    printf("\n The Sorted Tree is:\n");
    display(t);
    getch();
    return 0;
}