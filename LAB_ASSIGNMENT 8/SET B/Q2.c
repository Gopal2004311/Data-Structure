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

int isEmpty(TREE *t)
{
    return (t == NULL) ? 1 : 0;
}
TREE *create(TREE *t)
{
    TREE *temp = NULL, *new_node;
    int i, n;
    printf("\n Enter Size of tree:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        new_node = (TREE *)malloc(sizeof(TREE));
        new_node->right = NULL;
        new_node->left = NULL;
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

TREE *mirrorImage(TREE *t)
{
    TREE *temp, *temp1;
    STACK s;
    s.top = -1;
    temp = t;
    while (!isEmpty(temp))
    {
        temp1 = temp->right;
        temp->right = temp->left;
        temp->left = temp1;
        push(&s, temp->right);
        temp = temp->left;
    }

    while (!isEmptyStack(&s))
    {
        temp = pop(&s);
        while (!isEmpty(temp))
        {
            temp1 = temp->right;
            temp->right = temp->left;
            temp->left = temp1;
            push(&s, temp->right);
            temp = temp->left;
        }
    }
    return t;
}

void countNonLeaf(TREE *t)
{
    int count = 0;
    TREE *temp;
    STACK s;
    s.top = -1;
    temp = t;

    while (!isEmpty(temp))
    {
        if (!isEmpty(temp->left) || !isEmpty(temp->right))
        {
            count++;
        }
        if (!isEmpty(temp->right))
        {
            push(&s, temp->right);
        }
        temp = temp->left;
    }

    while (!isEmptyStack(&s))
    {
        temp = pop(&s);
        while (!isEmpty(temp))
        {
            if (!isEmpty(temp->left) || !isEmpty(temp->right))
            {
                count++;
            }
            if (!isEmpty(temp->right))
            {
                push(&s, temp->right);
            }
            temp = temp->left;
        }
    }
    printf("\n Total Non-leaf nodes are:%d", count);
}
int main()
{
    int choice, n;
    TREE *t = NULL, *t1 = NULL;
    do
    {
        printf("\n ---------------");
        printf("\n1.create\n2.display\n3.mirror image\n4.count non-leaf node\n5.Exit");
        printf("\n ---------------");
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
            t1 = mirrorImage(t);
            display(t1);
            break;
        case 4:
            countNonLeaf(t);
            break;
        }
    } while (choice != 5);
    getch();
    return 0;
}
