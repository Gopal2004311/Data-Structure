#include <stdio.h>
#include <conio.h>
#define max 100
typedef struct stack
{
    int item[max];
    int top;
} STACK;

void initStack(STACK *s)
{
    s->top = -1;
}

int isEmpty(STACK *s)
{
    return (s->top == -1) ? 1 : 0;
}

int isFull(STACK *s)
{
    return (s->top == max - 1) ? 1 : 0;
}

void push(STACK *s, int n)
{
    if (isFull(s))
    {
        printf("\n The Stack is Full!");
    }
    else
    {
        s->top++;
        s->item[s->top] = n;
    }
}

void printStack(STACK *s)
{
    int i;
    for (i = 0; i <= s->top; i++)
    {
        printf("\t%d", s->item[i]);
    }
}

int identical(STACK *s1, STACK *s2)
{
    int flag = 0, i = 0;
    while (i <= s1->top)
    {
        if (s1->item[i] == s2->item[i])
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
        i++;
    }
    return flag;
}
int main()
{
    STACK s1, s2;
    int choice, n;
    initStack(&s1);
    initStack(&s2);
    do
    {
        printf("\n------------------");
        printf("\n1.push(1)\n2.push(2)\n3.display(1)\n4.display(2)\n5.Exit");
        printf("\n------------------");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter data for first stack insertion:");
            scanf("%d", &n);
            push(&s1, n);
            break;
        case 2:
            printf("\n Enter data for second stack insertion:");
            scanf("%d", &n);
            push(&s2, n);
            break;
        case 3:
            printf("\n The first stack is:\n");
            printStack(&s1);
            break;
        case 4:
            printf("\n The second stack is:\n");
            printStack(&s2);
            break;
        }
    } while (choice != 5);
    if (identical(&s1, &s2))
    {
        printf("\n The Both stacks are identical!");
    }
    else
    {
        printf("\n The Both stacks are not identical!");
    }
    getch();
    return 0;
}