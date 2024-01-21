#include <stdio.h>
#include <conio.h>
int main()
{
    int a[10], i, n;
    int choice, sum = 0;
    printf("\n enter array limit:");
    scanf("%d", &n);  
    printf("\n enter array elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n 1.sum of all even index element of an array.\n");
    printf("\n 2.sum of all odd index element of an array.\n");
    printf("\n.................................................!");
    printf("\n enter your choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        for (i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                sum = sum + a[i];
            }
        }
        printf("\n sum of all even index element is %d ", sum);
        sum = 0;
        break;
    case 2:
        for (i = 0; i < n; i++)
        {
            if (i % 2 != 0)
            {
                sum = sum + a[i];
            }
        }
        printf("\n sum of all odd index element is %d", sum);
        sum = 0;
        break;

    default:
        printf("\n wrong input....!");
        break;
    }
}