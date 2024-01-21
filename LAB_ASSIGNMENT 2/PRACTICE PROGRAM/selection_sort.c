#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

// Sorts an array of strings where length of every
// string should be smaller than MAX_LEN
void selectionSort(char arr[][MAX_LEN], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted sub array
    char minStr[30];
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        strcpy(minStr, arr[i]);
        for (j = i + 1; j < n; j++)
        {
            // If min is greater than arr[j]
            if (strcmp(minStr, arr[j]) > 0)
            {
                // Make arr[j] as minStr and update min_idx
                strcpy(minStr, arr[j]);
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i)
        {
            char temp[MAX_LEN];
            strcpy(temp, arr[i]); // swap item[pos] and item[i]
            strcpy(arr[i], arr[min_idx]);
            strcpy(arr[min_idx], temp);
        }
    }
}

// Driver code
int main()
{
    
    int n;
    printf("\n enter size pf array:");
    scanf("%d",&n);
    int i;
    char arr[n][MAX_LEN];
    printf("\n enter array elements:");
    for ( i = 0; i < n; i++)
    {
       printf("\n Enter [%d] index element:",i);
       scanf("%s",arr[i]);
    }
    

    printf("\n Given array is:");
    for (i = 0; i < n; i++)
       {
        printf("\t%s",arr[i]);
       }

    selectionSort(arr, n);

    printf("\nSorted array is:");
    for (i = 0; i < n; i++)
        printf("\t%s",arr[i]);

    return 0;
}