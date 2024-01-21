#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
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
    int i, j, len;
    char infix[20], ch, prefix[20];
    STACK s1;
    initStack(&s1);

    printf("\n Enter infix expression:");
    scanf("%s", infix);
    len = strlen(infix);
    for (i = len - 1; i >= 0; i--)
    {
        if (isalnum(infix[i]))
        {
            prefix[j] = infix[i];
            j++;
        }
        else
        {
            switch (infix[i])
            {
            case '*':
            case '-':
            case '+':
            case '/':
            case '%':
            case '^':
            case ')':
                push(&s1, infix[i]);
                break;
            case '(':
                while ((ch = pop(&s1)) != ')')
                {
                    prefix[j] = ch;
                    j++;
                }
                break;
            }
        }
    }
    while (!isEmpty(&s1))
    {
        prefix[j] = pop(&s1);
        j++;
    }
    prefix[j] = '\0';
    strcpy(prefix, strrev(prefix));
    printf("\n The Prefix expression is:%s", prefix);
    getch();
    return 0;
}