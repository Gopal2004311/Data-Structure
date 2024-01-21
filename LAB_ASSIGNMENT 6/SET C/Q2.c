#include <stdio.h>
#include <conio.h>
#define max 50
typedef struct stack
{
    int top;
    int item[max];
} STACK;

void initStack(STACK *ps)
{
    ps->top = -1;
}
int isEmpty(STACK *ps)
{
    if (ps->top == -1)
        return 1;
    else
        return 0;
}

int isFull(STACK *ps)
{
    if (ps->top == max - 1)
        return 1;
    else
        return 0;
}

void push(STACK *ps, int n)
{
    if (isFull(ps))
    {
        printf("\n Stack is full---");
    }
    else
    {
        ps->top++;
        ps->item[ps->top] = n;
    }
}

int pop(STACK *ps)
{
    int x;
    if (isEmpty(ps))
    {
        printf("\n Stack is Empty---");
    }
    else
    {
        x = ps->item[ps->top];
        ps->top--;
    }
    return x;
}

void display(STACK *ps)
{
    int i;
    for (i = 0; i < ps->top; i++)
    {
        printf("\t %d", ps->item[i]);
    }
}
int main()
{
    STACK s1, s2, temp;
    initStack(&s1);
    initStack(&s2);
    initStack(&temp);
    int choice, n;
    do
    {
        printf("\n ---------------------");
        printf("\n1.push\n2.Exit");
        printf("\n-----------------------");
        printf("\n Enter choice:");
        scanf("%d", &choice);
        printf("\n Enter stack element:");
        scanf("%d", &n);
        push(&s1, n);
    } while (choice != 2);

    printf("\n The original stack is:\n");
    display(&s1);

    while (!isEmpty(&s1))
    {
        n = pop(&s1);
        push(&temp, n);
    }

    while (!isEmpty(&temp))
    {
        n = pop(&temp);
        push(&s2, n);
    }

    printf("\n The copied stack is:\n");
    display(&s2);
    getch();
    return 0;
}