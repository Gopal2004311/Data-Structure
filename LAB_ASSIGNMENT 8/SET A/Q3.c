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

typedef struct stack
{
    TREE *data[MAX];
    int top;
} STACK;

// stack operations start here!

void push(STACK *s, TREE* t)
{
    if (s->top == MAX - 1)
    {
        printf("\n Stack is Full!");
    }
    else
    {
        s->top++;
        s->data[s->top] = t;
    }
}

TREE* pop(STACK *s)
{
    TREE* n;
    if (s->top == -1)
    {
        printf("\n Stack is Empty!");
    }
    else
    {
        n = s->data[s->top];
        s->top--;
    }
    return n;
}

// Queue operations start here!
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

void deleteQ(QUEUE *q)
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
    }
    return t;
}

// tree operations start here!
int isEmpty(TREE *t)
{
    return (t == NULL) ? 1 : 0;
}
TREE *create(TREE *t)
{
    int n,i;
    TREE *new_node, *temp;
    QUEUE *q;
    initQueue(q);
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
                    deleteQ(q);
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

int leafProduct(TREE *t)
{
    TREE *temp;
    STACK *s1,*s2;
    int p = 1;
    s1->top=s2->top=-1;
    temp = t;
    while (!isEmpty(temp))
    {
        if (isEmpty(temp->left) && isEmpty(temp->right))
        {
            push(s1,temp);
        }

        if (!isEmpty(temp->right))
        {
            push(s2, temp->right);
        }

        temp = temp->left;
    }

    while (s2->top != -1)
    {
        temp = pop(s2);
        while (!isEmpty(temp))
        {
            if (isEmpty(temp->left) && isEmpty(temp->right))
            {
                push(s1, temp);
            }

            if (!isEmpty(temp->right))
            {
                push(s2, temp->right);
            }

            temp = temp->left;
        }
    }

    while (s1->top != -1)
    {
        p = p * pop(s1)->data;
    }
    return p;
}

// main function start here!
int main()
{
    int p;
    TREE *t = NULL;
    t = create(t);
    printf("\n The tree is:\n");
    display(t);
    p = leafProduct(t);
    printf("\n The product is:%d", p);
    getch();
    return 0;
}
