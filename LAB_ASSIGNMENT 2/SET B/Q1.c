#include <stdio.h>
#include <conio.h>
#include <string.h>
void display(char a[][20])
{
    for (int i = 0; i < 7; i++)
    {
        printf("\t%s", a[i]);
    }
    printf("\n");
}
int main()
{
    char a[7][20] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
    char temp[20];
     int i, j;
    printf("\n the original input array is:");
    display(a);
    for (i = 0; i < 7; i++)
    {
        strcpy(temp, a[i]);
        for (j = i - 1; j >= 0 && strcmp(a[j], temp) > 0; j--)
        {
                strcpy(a[j + 1], a[j]); 
        }
        strcpy(a[j + 1], temp);
    }
    printf("\n the sorted array is:");
    display(a);
}
