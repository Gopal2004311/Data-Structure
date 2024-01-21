#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
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
// function for stack empty or not
int isEmptyStack(STACK *s)
{
    return (s->top == -1) ? 1 : 0;
}
// function for stack full or not
int isFullStack(STACK *s)
{
    return (s->top == MAX - 1) ? 1 : 0;
}
// function for push into stack
void push(STACK *s, TREE *t)
{
    if (isFullStack(s))
    {
        printf("\n The stack is full!");
    }
    else
    {
        s->top++;
        s->data[s->top] = t;
    }
}

// function for pop from stack
TREE *pop(STACK *s)
{
    TREE *t = NULL;
    if (isEmptyStack(s))
    {
        printf("\n The stack is Empty!");
    }
    else
    {
        t = s->data[s->top];
        s->top--;
    }
    return t;
}
// Empty tree function
int isEmpty(TREE *t)
{
    return (t == NULL) ? 1 : 0;
}
// creating binary search tree
TREE *create(TREE *t)
{
    int i, n;
    TREE *temp, *new_node;
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
        }
        else
        {
            temp = t;
            while (t)
            {
                if (temp->data > new_node->data)
                {
                    if (isEmpty(temp->left))
                    {
                        temp->left = new_node;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->data <= new_node->data)
                    {
                        if (isEmpty(temp->right))
                        {
                            temp->right = new_node;
                            break;
                        }
                        else
                        {
                            temp = temp->right;
                        }
                    }
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

void preOrder(TREE *t)
{
    TREE *temp;
    STACK s;
    s.top = -1;
    temp = t;
    while (!isEmpty(temp))
    {
        printf("\t%d", temp->data);
        push(&s, temp->right);
        temp = temp->left;
    }

    while (!isEmptyStack(&s))
    {
        temp = pop(&s);
        while (!isEmpty(temp))
        {
            printf("\t%d", temp->data);
            push(&s, temp->right);
            temp = temp->left;
        }
    }
}

void postOrder(TREE *t)
{
    TREE *temp;
    STACK s, s1;
    s.top = s1.top = -1;
    temp = t;
    push(&s, temp);
    while (!isEmptyStack(&s))
    {
        temp = pop(&s);
        push(&s1, temp);
        if (!isEmpty(temp->left))
        {
            push(&s, temp->left);
        }

        if (!isEmpty(temp->right))
        {
            push(&s, temp->right);
        }
    }

    while (!isEmptyStack(&s1))
    {
        temp = pop(&s1);
        printf("\t%d", temp->data);
    }
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
        printf("\n-------------------");
        printf("\n1.create\n2.display\n3.pre-order\n4.post-order\n5.in-order\n6.Exit");
        printf("\n-------------------");
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
            preOrder(t);
            break;
        case 4:
            postOrder(t);
            break;
        case 5:
            inOrder(t);
            break;
        }
    } while (choice != 6);
    getch();
    return 0;
}
