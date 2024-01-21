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
    int i, n;
    TREE *new_node, *temp;
    printf("Enter size of tree:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        new_node = (TREE *)malloc(sizeof(TREE));
        new_node->left = NULL;
        new_node->right = NULL;
        printf("\nEnter [%d] node data:", i);
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

                if (temp->data <= new_node->data)
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

void preOrder(TREE*t)
{
    if(!isEmpty(t))
    {
        printf("\t%d",t->data);
        preOrder(t->left);
        preOrder(t->right);
    }
}

void postOrder(TREE*t)
{
    if(!isEmpty(t))
    {
        postOrder(t->left);
        postOrder(t->right);
        printf("\t%d",t->data);
    }
}

int main()
{
    int n,choice;
    TREE*t=NULL;
    do
    {
        printf("\n--------------");
        printf("\n1.create\n2.display\n3.pre-order display\n4.post-order display\n5.Exit");
        printf("\n--------------");
        printf("\nEnter your choice:");;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            t=create(t);
            break;
        case 2:
            printf("\nThe Tree is:\n");
            display(t);
            break;
        case 3:
            printf("\nThe Pre-order tree is:\n");
            preOrder(t);
            break;
        case 4:
            printf("\nThe Post-order tree is:\n");
            postOrder(t);
            break;
        }
    } while (choice!=5);
    getch();
    return 0;
}