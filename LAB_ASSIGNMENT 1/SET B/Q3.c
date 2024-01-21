#include <stdio.h>
#include <conio.h>
int main()
{
    int a[10], b[10], c[10];
    int i, n, p, coe;
    printf("\n Enter the limit for polynomials: ");
    scanf("%d", &n);
    printf("\n Enter the coefficient & power for first polynomial: ");
    for (i = 0; i < n; i++)
    {
        printf("\n Enter the %d index coefficient&power:", i);
        scanf("%d%d", &coe, &p);
        a[p] = coe;
    }
    printf("\n Enter the coefficient & power for second polynomial:");
    for (i = 0; i < n; i++)
    {
        printf("\n Enter the %d index coefficient&power:",i);
        scanf("%d%d", &coe, &p);
        b[p] = coe;
    }

    printf("\n The addition of two polynomial:");
    for (i = 0; i < n; i++)
    {
        c[i] = a[i] + b[i];
    }
    for (i = n - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            printf("%d", c[i]);
        }
        else
        {
            printf("%dx^%d+", c[i], i);
        }
    }
}