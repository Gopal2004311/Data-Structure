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
    return (ps->top == -1) ? 1 : 0;
}

int isFull(STACK *ps)
{
    return (ps->top == max - 1) ? 1 : 0;
}

void push(STACK *ps, int n)
{
    if (isFull(ps))
        printf("\n Stack is full!");
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
        printf("\n Stack is Empty!");
    else
    {
        x = ps->item[ps->top];
        ps->top--;
    }
    return x;
}

int main()
{
    int a, i, len, op1, op2, result = 0;
    char postfix[max];
    STACK s1;
    initStack(&s1);
    printf("\n Enter postfix string :");
    gets(postfix);
    len = strlen(postfix);
    for (i = 0; i < len; i++)
    {
        if (isalnum(postfix[i]))
        {
            if (postfix[i] >= '0' && postfix[i] <= '9')
            {
                push(&s1, (postfix[i] - '0'));
            }
            else
            {
                printf("\n Enter value for %c:", postfix[i]);
                scanf("%d", &a);
                push(&s1, a);
            }
        }
        else
        {
            switch (postfix[i])
            {
            case '+':
                op2 = pop(&s1);
                op1 = pop(&s1);
                result = op1 + op2;
                push(&s1, result);
                break;
            case '-':
                op2 = pop(&s1);
                op1 = pop(&s1);
                result = op1 - op2;
                push(&s1, result);
                break;
            case '*':
                op2 = pop(&s1);
                op1 = pop(&s1);
                result = op1 * op2;
                push(&s1, result);
                break;
            case '/':
                op2 = pop(&s1);
                op1 = pop(&s1);
                result = op1 / op2;
                push(&s1, result);
                break;
            case '%':
                op2 = pop(&s1);
                op1 = pop(&s1);
                result = op1 % op2;
                push(&s1, result);
                break;
            }
        }
    }
    result = pop(&s1);
    printf("\n The result is:%d", result);
    getch();
    return 0;
}