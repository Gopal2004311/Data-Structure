#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
#define COUNT 50
typedef struct queue
{
    int id;
    char name[max];
    char destination[max];
    char source[max];
    int rate;
    int noises;
    int total;
    struct queue *next;
} QUEUE;

QUEUE *rear = NULL;
QUEUE *front = NULL;
int isEmpty(QUEUE *q)
{
    return (q == NULL) ? 1 : 0;
}

QUEUE *insert(QUEUE *q, int id, char name[], char dest[], char source[], int rate, int n, int total)
{
    QUEUE *temp, *new_node;
    new_node = (QUEUE *)malloc(sizeof(QUEUE));
    new_node->next = NULL;
    new_node->id = id;
    strcpy(new_node->name, name);
    strcpy(new_node->destination, dest);
    strcpy(new_node->source, source);
    new_node->rate = rate;
    new_node->noises = n;
    new_node->total = total;
    if (isEmpty(q))
    {
        front = rear = q = new_node;
        printf("\n Thanks For Visit!");
        printf("\n------------------------------------------");
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
        printf("\n Thanks For Visit!");
        printf("\n------------------------------------------");
    }
    return q;
}

QUEUE *delete(QUEUE *q)
{
    QUEUE *temp;
    if (isEmpty(q))
    {
        printf("\n Sorry!passenger not available!");
        printf("\n------------------------------------------");
        return q;
    }
    else
    {
        temp = front;
        printf("\n Passenger id=%d", temp->id);
        printf("\n Passenger Name=%s", temp->name);
        printf("\n Passenger destination=%s", temp->destination);
        printf("\n Passenger Source =%s", temp->source);
        printf("\n No.of Passengers=%d", temp->noises);
        printf("\n Per Passenger cost=%d", temp->rate);
        printf("\n Total cost=%d", temp->total);
        front = temp->next;
        free(temp);
        printf("\n Record Deleted Successfully!");
        printf("\n------------------------------------------");
        return q;
    }
}

void display(QUEUE *q)
{
    printf("\tid\tname\tdestination\tsource\tno.of passengers\tcost\ttotal");
    printf("\n---------------------------------------------------------------------------\n");
    front = q;
    do
    {
        printf("\t%d", front->id);
        printf("\t%s", front->name);
        printf("\t%s", front->destination);
        printf("\t%s", front->source);
        printf("\t%d", front->noises);
        printf("\t%d", front->rate);
        printf("\t%d", front->total);
        printf("\n");
        front = front->next;
    } while (front != NULL);
}

void search(QUEUE *q, char name[])
{
    int flag = 0;
    front = q;
    do
    {
        if (strcmp(front->name, name) == 0)
        {
            flag = 1;
            printf("\tid\tname\tdestination\tsource\tno.of passengers\tcost\ttotal");
            printf("\n---------------------------------------------------------------------------\n");
            printf("\t%d", front->id);
            printf("\t%s", front->name);
            printf("\t%s", front->destination);
            printf("\t%s", front->source);
            printf("\t\t%d", front->noises);
            printf("\t\t%d", front->rate);
            printf("\t\t%d", front->total);
            printf("\n---------------------------------------------------------------------------");
            break;
        }
        front = front->next;
    } while (front != rear);

    if (flag == 0)
    {
        printf("\nSorry!Passenger Not Found!");
    }
}
int main()
{
    QUEUE *q = NULL;
    int choice, id, cost, total, n;
    char name[max], source[max], dest[max];
    do
    {
        printf("\n-------------Railway Reservation System--------------------");
        printf("\n1.Ticket Booking");
        printf("\n2.Passenger Detail");
        printf("\n3.Remove Passenger");
        printf("\n4.Display all Passenger Details");
        printf("\n5.Exit");
        printf("\n-----------------------------------------------------------");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter Passenger id:\t");
            scanf("%d", &id);
            printf("\n Enter Passenger name:\t");
            scanf("%s", &name);
            printf("\n Enter Passenger source:\t");
            scanf("%s", &source);
            printf("\n Enter Passenger destination:\t");
            scanf("%s", &dest);
            printf("\n Enter No.of peoples Travel:\t");
            scanf("%d", &n);
            if (strcmp(source, "mumbai") == 0 || strcmp(source, "pune") == 0 || strcmp(source, "nashik") == 0)
            {
                cost = 200;
            }
            else
            {
                cost = 100;
            }
            printf("\n Cost per passenger is:\t%d\n", cost);
            total = cost * n;
            printf("\n Total Cost:\t%d\n", total);
            q = insert(q, id, name, dest, source, cost, n, total);
            break;
        case 2:
            printf("\n Enter Name of Passenger:");
            scanf("%s", &name);
            search(q, name);
            break;
        case 3:
            q = delete (q);
            break;
        case 4:
            display(q);
            break;
        }
    } while (choice != 5);
    getch();
    return 0;
}