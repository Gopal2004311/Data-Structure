#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} STACK;

int isEmpty(STACK *ps)
{
    return ps == NULL ? 1 : 0;
}

STACK *push(STACK *ps, int n)
{
    STACK *new_node;
    new_node = (STACK *)malloc(sizeof(STACK));
    new_node->next = NULL;
    new_node->data = n;
    new_node->next = ps;
    ps = new_node;
    return ps;
}

STACK *pop(STACK *ps)
{
    int x;
    STACK *temp = ps;
    if (!isEmpty(ps))
    {
        x = temp->data;
        ps = temp->next;
        free(temp);
        printf("\n The pop element is:%d", x);
        return ps;
    }
    else
    {
        printf("\n Stack is Empty!");
        return ps;
    }
}

void display(STACK *list)
{
    while (list != NULL)
    {
        printf("\t%d", list->data);
        list = list->next;
    }
}

int main()
{
    int n, choice;
    STACK *s1 = NULL;
    do
    {
        printf("\n---------------");
        printf("\n1.push\n2.pop\n3.display\n4.Exit");
        printf("\n------------------");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter push element:");
            scanf("%d", &n);
            s1 = push(s1, n);
            break;
        case 2:
            if (!isEmpty(s1))
            {
                s1 = pop(s1);
            }
            else
            {
                printf("\n Stack is empty!");
            }
            break;
        case 3:
            if (!isEmpty(s1))
            {
                printf("\n The stack is:\n");
                display(s1);
            }
            else
            {
                printf("\n The stack is Empty!");
            }
            break;
        }
    } while (choice != 4);
    getch();
    return 0;
}