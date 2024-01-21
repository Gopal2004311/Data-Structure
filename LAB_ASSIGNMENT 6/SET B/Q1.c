#include <stdio.h>
#include <conio.h>
#include <string.h>
#define max 50
typedef struct stack
{
    int top;
    char a[max];
} STACK;

void initStack(STACK *ps)
{
    ps->top = -1;
}

int isEmpty(STACK *ps)
{
    return (ps->top == -1) ? 1 : 0;
}

int isFull(STACK *ps)
{
    return (ps->top == max - 1) ? 1 : 0;
}

void push(STACK *ps, char ch)
{
    if (isFull(ps))
        printf("\n Stack is full...!");
    else
    {
        ps->top++;
        ps->a[ps->top] = ch;
    }
}

char pop(STACK *ps)
{
    char x;
    if (isEmpty(ps))
        printf("\n Stack is Empty!");
    else
    {
        x = ps->a[ps->top];
        ps->top--;
    }
    return x;
}

int main()
{
    STACK s1;
    initStack(&s1);
    char input[max], output[max], temp[max];
    int len, i;
    printf("\n Enter a string to check it palindrome or not:");
    gets(input);
    strcpy(temp, input);
    len = strlen(temp);
    for (i = 0; i < len; i++)
    {
        push(&s1, temp[i]);
    }
    for (i = 0; i < len; i++)
    {
        output[i] = pop(&s1);
    }

    output[i] = '\0';
    if (strcmp(output, input) == 0)
    {
        printf("\n String is palindrome!");
    }
    else
    {
        printf("\n The String not a palindrome!");
    }
    getch();
    return 0;
}