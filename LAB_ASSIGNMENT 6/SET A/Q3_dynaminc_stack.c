#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
typedef struct stack
{
    char data;
    struct stack *next;
} STACK;

int isEmpty(STACK *s)
{
    return (s == NULL) ? 1 : 0;
}

STACK *push(STACK *s, char n)
{
    STACK *new_node, *temp;
    new_node = (STACK *)malloc(sizeof(STACK));
    new_node->next = NULL;
    new_node->data = n;
    new_node->next = s;
    s = new_node;
    return s;
}

STACK *pop(STACK *s)
{
    char n;
    STACK *temp = s;
    n = temp->data;
    s = temp->next;
    free(temp);
    printf("%c", n);
    return s;
}

int main()
{
    STACK *s = NULL, *temp;
    char input[max], ch;
    int i;
    printf("\nEnter Sentence:\n");
    gets(input);
    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] != ' ')
        {
            s = push(s, input[i]);
        }
        else
        {
            while (!isEmpty(s))
            {
                s = pop(s);
            }
            printf(" ");
        }
    }
    while (!isEmpty(s))
    {
        s = pop(s);
    }
    getch();
    return 0;
}