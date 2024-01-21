#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *create(NODE *list)
{
    int i, n;
    NODE *newNode, *temp;
    printf("\n Enter size of list:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newNode = (NODE *)malloc(sizeof(NODE));
        newNode->next = NULL;
        printf("\n Enter [%d] node data:", i);
        scanf("%d", &newNode->data);
        if (list == NULL)
        {
            list = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return list;
}

void display(NODE *list)
{
    while (list != NULL)
    {
        printf("\t%d", list->data);
        list = list->next;
    }
}

NODE *removeAdd(NODE *list, int p)
{
    int n, i, p1;
    NODE *newNode, *temp, *temp1;
    newNode = (NODE *)malloc(sizeof(NODE));
    newNode->next = NULL;
    if (list == NULL)
    {
        printf("\n List is Empty!");
    }
    else
    {
        if (p == 1)
        {
            temp = list;
            n = temp->data;
            list = temp->next;
            free(temp);
            printf("\n Deleted data:%d", n);
            printf("\n list is:\n");
            display(list);
        }
        else
        {
            for (i = 1, temp = list; i < p - 1 && temp != NULL; i++, temp = temp->next)
                ;
            if (temp != NULL)
            {
                temp1 = temp->next;
                temp->next = temp1->next;
                n = temp1->data;
                free(temp1);
                printf("\n Deleted data:%d", n);
                printf("\n list is:\n");
                display(list);
            }
        }
        printf("\n Enter position for adding data:");
        scanf("%d", &p1);
        if (p1 == 1)
        {
            newNode->data = n;
            newNode->next = list;
            list = newNode;
            return list;
        }
        else
        {
            for (i = 1, temp = list; i < p1 - 1 && temp != NULL; i++, temp = temp->next)
                ;
            if (temp != NULL)
            {
                newNode->data = n;
                newNode->next = temp->next;
                temp->next = newNode;
                return list;
            }
            else
            {
                printf("\n Position out of range!");
                return list;
            }
        }
    }
}

/*void display(NODE*list)
{
    while(list!=NULL)
    {
        printf("\t%d",list->data);
        list=list->next;
    }
}
*/
int main()
{
    NODE *list = NULL;
    int p, n, choice;
    do
    {
        printf("\n------------------");
        printf("\n1.create\n2.display\n3.delete and add\n4.Exit");
        printf("\n------------------");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            list = create(list);
            break;
        case 2:
            printf("\n List is:\n");
            display(list);
            break;
        case 3:
            printf("\n Enter position for delete element:");
            scanf("%d", &p);
            list = removeAdd(list, p);
            break;
        }
    } while (choice != 4);
    getch();
    return 0;
}