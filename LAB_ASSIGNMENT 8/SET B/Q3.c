#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100
typedef struct tree
{
    int data;
    struct tree *left, *right;
} TREE;

int isEmpty(TREE *t)
{
    return (t == NULL) ? 1 : 0;
}
TREE *create(TREE *t)
{
    TREE *temp = NULL, *new_node;
    int i, n;
    printf("\n Enter Size of tree:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        new_node = (TREE *)malloc(sizeof(TREE));
        new_node->right = NULL;
        new_node->left = NULL;
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
    }
    return t;
}

void display(TREE *t)
{
    if (!isEmpty(t))
    {
        printf("\t%d", t->data);
        display(t->left);
        display(t->right);
    }
}

int countLeaf(TREE *t)
{
    if (isEmpty(t))
    {
        return 0;
    }

    if (isEmpty(t->left) && isEmpty(t->right))
    {
        return 1;
    }

    return (countLeaf(t->left) + countLeaf(t->right));
}

int allNodes(TREE *t)
{
    int i;
    if (isEmpty(t))
    {
        return 0;
    }
    i = 1 + allNodes(t->left) + allNodes(t->right);
    return (i);
}

int main()
{
    TREE *t = NULL;
    int count1 = 0, count2 = 0, choice;
    do
    {
        printf("\n -----------------------");
        printf("\n1.create\n2.display\n3.count all nodes\n4.count leaf nodes\n5.Exit");
        printf("\n------------------------");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            t = create(t);
            break;
        case 2:
            printf("\n The Tree is:\n");
            display(t);
            break;
        case 3:
            count1 = allNodes(t);
            printf("\n Total nodes are:%d", count1);
            break;
        case 4:
            count2 = countLeaf(t);
            printf("\n Total leaf nodes are:%d", count2);
            break;
        }
    } while (choice != 5);
    getch();
    return 0;
}