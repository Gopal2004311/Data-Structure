#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
} TREE;

int isEmpty(TREE *t)
{
    return (t == NULL) ? 1 : 0;
}
TREE *create(TREE *t)
{
    TREE *new_node, *temp;
    int i, n;
    printf("\n Enter how many nodes you want:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        new_node = (TREE *)malloc(sizeof(TREE));
        new_node->left = NULL;
        new_node->right = NULL;
        printf("\n Enter [%d] node data:", i);
        scanf("%d", &new_node->data);
        if (isEmpty(t))
        {
            t = new_node;
        }
        else
        {
            temp = t;
            while (t)
            {

                if (temp->data > new_node->data)
                {
                    if (isEmpty(temp->left))
                    {
                        temp->left = new_node;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (isEmpty(temp->right))
                    {
                        temp->right = new_node;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
    }
    return t;
}

void display(TREE*t)
{
    if(!isEmpty(t))
    {
        printf("\t%d",t->data);
        display(t->left);
        display(t->right);
    }
}

int main()
{
    TREE*t=NULL;
    t=create(t);
    printf("\n The Tree is:\n");
    display(t);
    getch();
    return 0;
}
