#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 100
typedef struct tree
{
    int data;
    struct tree *left, *right;
} TREE;

int isEmpty(TREE *t)
{
    return (t == NULL) ? 1 : 0;
}
typedef struct queue
{
    TREE *data[MAX];
    int front, rear;
} QUEUE;
typedef struct stack
{
    TREE *data[MAX];
    int top;
} STACK;
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
        printf("\n Stack is Full!");
    }
    else
    {
        s->top++;
        s->data[s->top] = t;
    }
}
TREE *pop(STACK *s)
{
    TREE *t;
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
    q->rear = -1;
    q->front = -1;
}
void insertQueue(QUEUE *q, TREE *t)
{
    if (isFullQueue(q))
    {
        printf("\n Queue is Full!");
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

void deleteQueue(QUEUE *q)
{
    if (isFullQueue(q))
    {
        printf("\n Queue is Full!");
    }
    else
    {
        if (q->rear == q->front)
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
    TREE *t;
    t = q->data[q->front];
    return t;
}
TREE *create(TREE *t)
{
    int i, n;
    TREE *new_node, *temp;
    QUEUE *q = NULL;
    initQueue(q);
    printf("\n Enter size of tree:");
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
            insertQueue(q, t);
        }
        else
        {
            temp = peek(q);
            if (isEmpty(temp->left))
            {
                temp->left = new_node;
                insertQueue(q, temp->left);
            }
            else
            {
                if (isEmpty(temp->right))
                {
                    temp->right = new_node;
                    insertQueue(q, temp->right);
                    deleteQueue(q);
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

void ancestors(TREE *t, int n)
{
    TREE *temp, *tr;
    STACK s1, s2, s3;
    s1.top = -1;
    s2.top = -1;
    s3.top = -1;
    temp = t;
    push(&s1, temp);
    while (!isEmpty(temp))
    {
        push(&s1, temp->left);
        if (!isEmpty(temp->right))
        {
            push(&s1, temp->right);
            push(&s2, temp->right);
        }
        if (temp->data == n)
            break;
        temp = temp->left;
    }

    while (!isEmptyStack(&s2))
    {
        temp = pop(&s2);
        while (!isEmpty(temp))
        {
            push(&s1, temp->left);
            if (!isEmpty(temp->right))
            {
                push(&s1, temp->right);
                push(&s2, temp->right);
            }
            temp = temp->left;
        }
    }

    while (!isEmptyStack(&s1))
    {
        temp = pop(&s1);
        if (temp->data == n)
        {
            push(&s3, temp);
            tr = temp;
        }
        else
        {
            if (temp->left == tr || temp->right == tr)
            {
                push(&s3, temp);
                tr = temp;
            }
        }
    }

    while (!isEmptyStack(&s3))
    {
        temp = pop(&s3);
        if (temp->data != n)
            printf("\t%d", temp->data);
    }
}
void decent(TREE *t, int n)
{
    TREE *temp, *tr;
    STACK s1, s2;
    s1.top = s2.top = -1;
    temp = t;
    while (!isEmpty(temp))
    {
        if (temp->data == n)
        {
            push(&s1, temp);
        }
        else
        {
            push(&s2, temp->right);
        }
        temp = temp->left;
    }

    while (!isEmptyStack(&s2))
    {
        temp = pop(&s2);
        while (!isEmpty(temp))
        {
            if (temp->data == n)
            {
                push(&s1, temp);
            }
            else
            {
                push(&s2, temp->right);
            }
            temp = temp->left;
        }
    }

    while (!isEmptyStack(&s1))
    {
        temp = pop(&s1);
        while (!isEmpty(temp))
        {
            if (!isEmpty(temp->right))
            {
                push(&s1, temp->right);
            }
            printf("\t%d", temp->data);
            temp = temp->left;
        }
    }
}
int main()
{
    int n, choice;
    TREE *t = NULL;
    clrscr();
    do
    {
        printf("\n ------------");
        printf("\n1.create\n2.display\n3.ancestors\n4.Exit");
        printf("\n-------------");
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
            printf("\n Enter data for finding ancestors:");
            scanf("%d", &n);
            ancestors(t, n);
            break;
        case 4:
            printf("\n Enter data for finding descendent:");
            scanf("%d", &n);
            decent(t, n);
            break;
        }
    } while (choice != 5);
    getch();
    return 0;
}