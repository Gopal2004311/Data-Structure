#include <stdio.h>
#include <conio.h>
#define max 30
typedef struct stack
{
    int a[max];
    int top;
} STACK;

void initStack(STACK *ps)
{
    ps->top = -1;
}

void push(STACK *ps, int n)
{
    if (!isEmpty(&ps))
    {
        ps->top++;
        ps->a[ps->top] = n;
    }
    else
    {
        printf("\n Stack is empty!");
        return;
    }
}

int pop(STACK *ps)
{
    int n;
    if (!isFull(&ps))
    {
        n = ps->a[ps->top];
        ps->top--;
        return n;
    }
    else
    {
        printf("\n Stack is full!");
        return 0;
    }
}

int isEmpty(STACK *ps)
{
    if (ps->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(STACK *ps)
{
    if (ps->top == max - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display(STACK *ps)
{
    int i;
    for (i = 0; i <= ps->top; i++)
    {
        printf("\t%d", ps->a[i]);
    }
}
int main()
{
    int n, choice;
    STACK s1;
    initStack(&s1);
    do
    {
        printf("\n----------------------------");
        printf("\n1.push \n2.pop \n 3.display \n4.Exit");
        printf("\n----------------------------");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (!isFull(&s1))
            {
                printf("\n Enter push element:");
                scanf("%d", &n);
                push(&s1, n);
            }
            break;
        case 2:
            if (!isEmpty(&s1))
            {
                n = pop(&s1);
                printf("\n The pop element is:%d", n);
            }
            else
            {
                printf("\n Stack is empty!");
            }
            break;
        case 3:
            if (!isEmpty(&s1))
            {
                printf("\n The Stack is:\n");
                display(&s1);
            }
            else
            {
                printf("\n Stack is Empty!");
            }
            break;
        }
    } while (choice != 4);
}