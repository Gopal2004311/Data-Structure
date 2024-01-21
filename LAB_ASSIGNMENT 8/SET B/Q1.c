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
    int n, i;
    TREE *new_node, *temp;
    printf("\n Enter size of tree:");
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

void display(TREE *t)
{
    if (!isEmpty(t))
    {
        printf("\t%d", t->data);
        display(t->left);
        display(t->right);
    }
}

TREE *insert(TREE *t, int n)
{
    TREE *new_node, *temp;
    new_node = (TREE *)malloc(sizeof(TREE));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = n;
    if (isEmpty(t))
    {
        printf("\n The tree is Empty!");
        return t;
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
    return t;
}

TREE *search(TREE *t, int n)
{
    int flag = 0;
    TREE *temp;
    if (isEmpty(t))
    {
        printf("\n Tree is Empty!");
        return t;
    }
    else
    {
        temp = t;
        while (t)
        {
            if (temp->data == n)
            {
                flag = 1;
                printf("\n The element founded at %u position.", temp);
                break;
            }

            if (temp->data <= n)
            {
                if (!isEmpty(temp->right))
                {
                    temp = temp->right;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (!isEmpty(temp->left))
                {
                    temp = temp->left;
                }
                else
                {
                    break;
                }
            }
        }
    }
    if (flag == 0)
    {
        printf("\n Element not found!");
    }
    return t;
}

int main()
{
    int n, choice;
    TREE *t = NULL;
    do
    {
        printf("\n---------------");
        printf("\n1.create BST\n2.display\n3.insert\n4.search\n5.Exit");
        printf("\n---------------");
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
            printf("\n Enter element for insert:");
            scanf("%d", &n);
            t = insert(t, n);
            break;
        case 4:
            printf("\n Enter element for search:");
            scanf("%d", &n);
            t = search(t, n);
            break;
        }
    } while (choice != 5);
    getch();
    return 0;
}