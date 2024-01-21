#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define max 50
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
    return (ps->top == -1) ? 1 : 0;
}

int isFull(STACK *ps)
{
    return (ps->top == max - 1) ? 1 : 0;
}

void push(STACK *ps, char ch)
{
    if (isFull(ps))
        printf("\n Stack is full...");
    else
    {
        ps->top++;
        ps->item[ps->top] = ch;
    }
}

char pop(STACK *ps)
{
    char x;
    if (isEmpty(ps))
        printf("\n Stack is Empty...");
    else
    {
        x = ps->item[ps->top];
        ps->top--;
    }
    return x;
}

int main()
{
    STACK s1;
    char infix[20], postfix[20], ch;
    int i, j = 0, len;
    initStack(&s1);
    printf("\n Enter infix string:");
    gets(infix);
    len = strlen(infix);
    for (i = 0; i < len; i++)
    {
        if (isalnum(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
        }
        switch (infix[i])
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '$':
        case '^':
        case '(':
            push(&s1, infix[i]);
            break;

        case ')':
            while ((ch = pop(&s1)) != '(')
            {
                postfix[j] = ch;
                j++;
            }
            break;
        }
    }
    while (!isEmpty(&s1))
    {
        postfix[j] = pop(&s1);
        j++;
    }
    postfix[j] = '\0';
    printf("\n The postfix string is:%s", postfix);
    getch();
    return 0;
}