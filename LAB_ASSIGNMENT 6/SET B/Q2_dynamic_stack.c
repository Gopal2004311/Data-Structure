#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct stack
{
    int data;
    struct stack *next;
} STACK;

int isEmpty(STACK *ps)
{
    return (ps == NULL) ? 1 : 0;
}

STACK *push(STACK *ps, int n)
{
    STACK *new_node, *temp;
    new_node = (STACK *)malloc(sizeof(STACK));
    new_node->next = NULL;
    new_node->data = n;
    if (isEmpty(ps))
    {
        ps = temp = new_node;
    }
    else
    {
        new_node->next = ps;
        ps = new_node;
    }
    return ps;
}
STACK *operate(STACK *s, int op1, int op2, char operator)
{
    int i, result = 0;
    switch (operator)
    {
    case '+':
        result = op1 + op2;
        s = push(s, result);
        break;
    case '-':
        result = op1 - op2;
        s = push(s, result);
        break;
    case '*':
        result = op1 * op2;
        s = push(s, result);
        break;
    case '/':
        result = op1 / op2;
        s = push(s, result);
        break;
    case '%':
        result = op1 % op2;
        s = push(s, result);
        break;
    case '^':
        result = 1;
        for (i = 1; i <= op2; i++)
        {
            result = result * op1;
        }
        printf("%d",result);
        s = push(s, result);
        break;
    case '$':
        result = 1;
        for (i = 1; i <= op2; i++)
        {
            result = result * op1;
        }
        printf("%d",result);
        s = push(s, result);
        break;
    }
    return s;
}

STACK *popToTime(STACK *ps, char op)
{
    int op1 = 0, op2 = 0, i = 1, n;
    STACK *temp;
    if (isEmpty(ps))
        printf("\n Stack is Empty!");
    else
    {
        while (i <= 2)
        {
            if (i == 1)
            {
                temp = ps;
                op2 = temp->data;
                ps = temp->next;
                free(temp);
            }
            else
            {
                temp = ps;
                op1 = temp->data;
                ps = temp->next;
                free(temp);
            }
            i++;
        }
        ps = operate(ps, op1, op2, op);
    }
    return ps;
}
STACK *pop(STACK *ps)
{
    int result = 0;
    STACK *temp = ps;
    result = temp->data;
    ps = temp->next;
    free(temp);
    printf("\n The result is:%d", result);
    return ps;
}
void main()
{
    int a, i, len;
    char postfix[50];
    STACK *s1 = NULL;
    printf("\n Enter postfix string :");
    gets(postfix);
    len = strlen(postfix);
    for (i = 0; i < len; i++)
    {
        if (isalnum(postfix[i]))
        {
            // if (postfix[i] >= '0' && postfix[i] <= '9')//also used isdigit();
            if (isdigit(postfix[i]))
            {
                s1 = push(s1, (postfix[i] - '0'));
            }
            else
            {
                printf("\n Enter value for %c:", postfix[i]);
                scanf("%d", &a);
                s1 = push(s1, a);
            }
        }
        else
        {
            s1 = popToTime(s1, postfix[i]);
        }
    }
    s1 = pop(s1);
    getch();
}