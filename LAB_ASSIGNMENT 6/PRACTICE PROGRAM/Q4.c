#include <stdio.h>
#include <conio.h>
#define max 100
typedef struct stack
{
    int top;
    int item[max];
} STACK;

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
        printf("\n Stack is full----");
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
        printf("\n Stack is Empty---");
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
        printf("\t%d", ps->item[i]);
    }
}

void insertion_sort(STACK *ps)
{
    int i, j, temp;
    for (i = 0; i < ps->top; i++)
    {
        temp = ps->item[i];
        for (j = i - 1; j >= 0 && ps->item[j] > temp; j--)
        {
            ps->item[j + 1] = ps->item[j];
        }
        ps->item[j + 1] = temp;
    }
}
int main()
{
    STACK s1, temp;
    int choice, n;
    s1.top = -1;
    do
    {
        printf("\n------------");
        printf("\n1.push\n2.Exit");
        printf("\n------------");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter push element:");
            scanf("%d", &n);
            push(&s1, n);
            break;
        }
    } while (choice != 2);

    printf("\n The original stack is:\n");
    display(&s1);

    insertion_sort(&s1);

    printf("\n The Sorted stack is:\n");
    display(&s1);
}