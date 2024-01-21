#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void display(char array[][30], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("\t%s ", array[i]);
  }
}
char create(char array[][30],int n){
  printf("Enter %d Strings: \n", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%s", array[i]);
  }
  return array[0][30];
}
void bubble_sort(char array[][30],int n)
{
  char temp[30];
  int pass,i;
  for(pass=1;pass<=n;pass++)
  {
    for (i = 0; i < n-pass; i++)
    {
      if (strcmp(array[i], array[i + 1]) > 0)
      {
        strcpy(temp, array[i]);
        strcpy(array[i], array[i + 1]);
        strcpy(array[i + 1], temp);
      }
    }
  }
}
int main()
{
  char array[10][30];
  int n;
  printf("\n Enter size of array:");
  scanf("%d", &n);
  array[0][30]=create(array,n);
  printf("\nOriginal array:\n");
  display(array, n);
  bubble_sort(array,n);
  printf("\nSorted Array:\n");
  display(array, n);
}