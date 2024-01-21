#include <stdio.h>
#include <conio.h>
#include <string.h>
#define max 100
typedef struct stack
{
    int top;
    char item[max];
} STACK;

void initStack(STACK *ps)
{
    ps->top = -1;
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

void push(STACK *ps, char n)
{
    if (!isFull(ps))
    {
        ps->top++;
        ps->item[ps->top] = n;
    }
    else
    {
        printf("\n Stack is full...!");
    }
}

char pop(STACK *ps)
{
    char x;
    if (!isEmpty(ps))
    {
        x = ps->item[ps->top];
        ps->top--;
    }
    else
    {
        printf("\n Stack is empty!");
    }
    return x;
}

int main()
{
    int len = 0, i;
    STACK s1;
    char input[max];
    initStack(&s1);
    printf("\n Enter sentence:");
    gets(input);
    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] != ' ')
        {
            push(&s1, input[i]);
        }
        else
        {
            while (!isEmpty(&s1))
            {
                printf("%c", pop(&s1));
            }
            printf(" ");
        }
    }
    while (!isEmpty(&s1))
    {
        printf("%c", pop(&s1));
    }
    getch();
    return 0;
}