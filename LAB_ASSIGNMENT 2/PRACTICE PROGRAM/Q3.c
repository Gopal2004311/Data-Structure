#include <stdio.h>
#include <string.h>

void selectionSort(char arr[][30], int n)
{
    int i, j, min_idx;

    char minStr[30];
    for (i = 0; i < n - 1; i++)
    {

        int min_idx = i;
        strcpy(minStr, arr[i]);
        for (j = i + 1; j < n; j++)
        {

            if (strcmp(minStr, arr[j]) > 0)
            {

                strcpy(minStr, arr[j]);
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            char temp[30];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[min_idx]);
            strcpy(arr[min_idx], temp);
        }
    }
}

int main()
{

    int n;
    printf("\n enter size pf array:");
    scanf("%d", &n);
    int i;
    char arr[n][30];
    printf("\n enter array elements in string format:");
    for (i = 0; i < n; i++)
    {
        printf("\n Enter [%d] index string:", i);
        scanf("%s", arr[i]);
    }

    printf("\n Given array is:");
    for (i = 0; i < n; i++)
    {
        printf("\t%s", arr[i]);
    }

    selectionSort(arr, n);

    printf("\nSorted array is:");
    for (i = 0; i < n; i++)
        printf("\t%s", arr[i]);

    return 0;
}