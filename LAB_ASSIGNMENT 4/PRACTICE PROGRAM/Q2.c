/*2) Read the data from file ‘employee.txt’ containing names of n employees, their qualification
and salary. Accept a name of the employee from the user and by using linear search
algorithm check whether the name of employee is present in the file or not if present
display salary of that employee, otherwise display “Employee not found”.*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct employee
{
    char name[20];
    char qua[20];
    float salary;
};

void linear_search(struct employee emp[], int n, char key[])
{
    int flag = 0, index;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(emp[i].name, key) == 0)
        {
            flag = 1;
            printf("\n The employee %s is found at index of %d.", key, i);
            printf("\n employee name:%s", emp[i].name);
            printf("\n employee qualification:%s", emp[i].qua);
            printf("\nemployee salary:%.2f", emp[i].salary);

            break;
        }
    }
    if (flag == 0)
    {
        printf("\n The employee are not exist!");
    }
}

int main()
{
    struct employee emp[10];
    FILE *ptr;
    int i = 0, n = 0;
    char key[20];
    ptr = fopen("employee.txt", "r");
    if (ptr == NULL)
    {
        printf("\n The file does not exist!");
        exit(0);
    }

    while (!feof(ptr))
    {
        fscanf(ptr, "%s%s%f", &emp[i].name, &emp[i].qua, &emp[i].salary);
        i++;
        n++;
    }

    printf("\n Enter search value:");
    gets(key);

    linear_search(emp, n, key);
    fclose(ptr);
    getch();
    return 0;
}