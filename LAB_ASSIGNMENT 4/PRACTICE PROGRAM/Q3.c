/*3) Read the data from file ‘player.txt’ containing names of n Player, their game_played and
age. Accept a name of the player from the user and by using binary search algorithm check
whether the name of player is present in the file or not if present display game_played and
age of that player, otherwise display “player not found”.*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
typedef struct play
{
    char name[20];
    char game[20];
    int age;
} player;
void display(player p[], int i, int n)
{
    for (i = 0; i < n; i++)
    {
        printf("\n%s   %s   %d", p[i].name, p[i].game, p[i].age);
    }
}
void bubble_sort(player a[], int n)
{
    player temp;
    int i, pass;
    for (pass = 1; pass < n; pass++)
    {
        for (i = 0; i < n - pass; i++)
        {
            if (strcmp(a[i].name, a[i + 1].name) > 0)
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}
void binary_search(player a[], int first, int last, char key[])
{
    int mid, flag = 0;
    while (first < last)
    {
        mid = (first + last) / 2;
        if (strcmp(a[mid].name, key) == 0)
        {
            flag = 1;
            printf("\nThe %s player founded at %d position.", key, mid);
            printf("\n Player name:%s", a[mid].name);
            printf("\n Player game:%s", a[mid].game);
            printf("\n Player age:%d", a[mid].age);
            break;
        }
        if (strcmp(a[mid].name, key) > 0)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }
    if (flag == 0)
    {
        printf("\n The %s player are not exist in file!", key);
    }
}
int main()
{
    player p[10];
    FILE *ptr;
    int i, n = 0;
    char key[20];
    ptr = fopen("player.txt", "r");
    if (ptr == NULL)
    {
        printf("\n The file does not exist!");
        exit(0);
    }
    i = 0;
    while (!feof(ptr))
    {
        fscanf(ptr, "%s%s%d", &p[i].name, &p[i].game, &p[i].age);
        i++;
        n++;
    }

    printf("\n Before sorting details:\n");
    display(p, 0, n);
    printf("\n Enter search player name:");
    scanf("%s", &key);
    printf("\n After sorting details:\n");
    bubble_sort(p, n);
    display(p, 0, n);
    binary_search(p, 0, n, key);
    fclose(ptr);
}