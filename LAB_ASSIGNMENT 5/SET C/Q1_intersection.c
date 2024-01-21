#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *create_list(NODE *list)
{
    NODE *temp = list, *new_node;
    int n, i;
    printf("\n Enter size of list:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        new_node = (NODE *)malloc(sizeof(NODE));
        new_node->next = NULL;
        printf("\n Enter [%d] node data:", i);
        scanf("%d", &new_node->data);
        if (list == NULL)
        {
            list = temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
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
NODE*insert(NODE*list,int n)
{
    NODE*new_node;
    new_node=(NODE*)malloc(sizeof(NODE));
    new_node->data=n;
    new_node->next=list;
    list=new_node;
    return list;

}
NODE*intersection(NODE*list1,NODE*list2,NODE*list)
{
    NODE*temp=list1;
    NODE*temp1=list2;

    for(temp=list1;temp!=NULL;temp=temp->next)
    {
        for(temp1=list2;temp1!=NULL;temp1=temp1->next)
        {
            if (temp->data==temp1->data)
            {
                list=insert(list,temp->data);
                break;
            }
            
        }
    }
    return list;
    
}
int main()
{
    NODE *list = NULL, *list1 = NULL, *list2 = NULL;
    list = create_list(list);
    list1 = create_list(list1);
    printf("\n The list is:\n");
    display(list);
    printf("\n The list is:\n");
    display(list1);
    list2 = intersection(list, list1, list2);
    printf("\n The intersection is:\n");
    display(list2);
    getch();
    return 0;
}