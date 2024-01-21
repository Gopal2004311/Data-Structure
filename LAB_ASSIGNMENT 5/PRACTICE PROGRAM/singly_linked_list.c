#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE*create_list(NODE*list)
{
    int i,n;
    NODE*temp,*new_node;
    printf("\n Enter size of list:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        new_node=(NODE*)malloc(sizeof(NODE));
        new_node->next=NULL;
        printf("\n Enter [%d] node data:",i);
        scanf("%d",&new_node->data);
        if(list==NULL)
        {
            list=temp=new_node;
        }else{
            temp->next=new_node;
            temp=new_node;
        }
    }
    return list;
}
void display(NODE*list)
{
    while(list!=NULL)
    {
        printf("\t%d",list->data);
        list=list->next;
    }
}
void search(NODE*list,int n)
{
    int flag=0;
    while(list!=NULL)
    {
        if(list->data==n)
        {
            flag=1;
            printf("\n Element are founded at %u node position.",list);
            break;
        }
        list=list->next;
    }
    if(flag==0)
    {
        printf("\n Element not found!");
    }
}
NODE*insert_by_position(NODE*list,int n,int p)
{
    NODE*temp=list,*new_node;
    int i;
    new_node=(NODE*)malloc(sizeof(NODE));
    new_node->next=NULL;
    new_node->data=n;
    if(p==1)
    {
        new_node->next=list;
        list=new_node;
        return list;
    }else{
        for(i=1,temp=list;i<p-1&&temp!=NULL;i++,temp=temp->next);
        if(temp->next!=NULL)
        {
        new_node->next=temp->next;
        temp->next=new_node;
        return list;
        }else{
            temp->next=new_node;
            return list;
        }
    }
}
NODE*delete_by_value(NODE*list,int n)
{
    NODE*temp=list,*temp1,*temp2;
    if(temp->data==n)
    {
        list=temp->next;
        free(temp);
        return list;
    }else{
    for(temp=list;temp->next->data!=n;temp=temp->next);
    if(temp!=NULL)
    {
    temp->next=temp1;
    temp1->next=temp2;
    temp->next=temp2;
    free(temp1);
    return list;
    }else{
        printf("\n Data not found!");
        return list;
    }
}
}
NODE*delete_by_position(NODE*list,int p)
{
    int i;
    NODE*temp=list,*temp1,*temp2;
    if(p==1)
    {
        list=temp->next;
        free(temp);
        return list;
    }else{
        for(i=1,temp=list;i<p-1&&temp!=NULL;i++,temp=temp->next);
        if(temp!=NULL)
        {
            temp->next=temp1;
            temp1->next=temp2;
            temp->next=temp2;
            free(temp1);
            return list;
        }else{
            printf("\nPosition out of range!");
            return list;
        }
    }
}
NODE*insert(NODE*list,int n)
{
    NODE*new_node;
    new_node->next=NULL;
    new_node->data=n;
    new_node->next=list;
    list=new_node;
    return list;
}
NODE*intersection(NODE*list,NODE*list1,NODE*list2)
{
    NODE*temp,*temp1;
    for(temp=list;temp!=NULL;temp=temp->next)
    {
        for(temp1=list1;temp1!=NULL;temp1=temp1->next)
        {
            if(temp->data==temp1->data)
            {
                list2=insert(list2,temp->data);
                break;
            }
        }
    }
    return list2;
}
int main()
{
   NODE*list=NULL,*list1=NULL,*list2=NULL;
   int n,p,choice;
   do
   {
     printf("\n---------------");
     printf("\n1.create\n2.display\n3.search\n4.insert by position\n5.delete by value \n6.delete by position \n7.intersection\n8.Exit");
     printf("\n---------------");
     printf("\n Enter your choice:");
     scanf("%d",&choice);
     switch(choice)
     {
        case 1:list=create_list(list);
        break;
        case 2:display(list);
        break;
        case 3:printf("\n Enter search value:");
        scanf("%d",&n);
        search(list,n);
        break;
        case 4:printf("\n Enter node data and position:");
        scanf("%d %d",&n,&p);
        list=insert_by_position(list,n,p);
        break;
        case 5:printf("\n Enter value for delete:");
        scanf("%d",&n);
        list=delete_by_value(list,n);
        break;
        case 6:printf("\n Enter position for delete data:");
        scanf("%d",&p);
        list=delete_by_position(list,p);
        break;
        case 7:list1=create_list(list1);
        list2=intersection(list,list1,list2);
        printf("\n The intersection of two list are:");
        display(list2);
        break;
        case 8:printf("\nExit!");
        break;
     }
   } while (choice!=8);
    getch();
    return 0;
}