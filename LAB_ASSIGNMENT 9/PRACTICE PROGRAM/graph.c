#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10
typedef struct graph
{
    int data;
    struct graph *edges[MAX];
} GRAPH;

GRAPH *create(GRAPH *g[], int numNodes)
{
    int i, j;
    GRAPH *temp, *newNode;
    for (i = 0; i < numNodes; i++)
    {
        newNode = (GRAPH *)malloc(sizeof(GRAPH));
        for (j = 0; j < numNodes; j++)
        {
            newNode->edges[j] = NULL;
        }
        printf("\n Enter [%d] node data:", i);
        scanf("%d", &newNode->data);
        g[i] = newNode;
        printf("\t%d", g[i]->data);
    }
    return g[0];
}

GRAPH*addEdge(GRAPH *g[], int from, int to, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (g[i]->data == from && g[j]->data == to)
            {
                if (g[i]->edges[i] == NULL || g[j]->edges[j] == NULL)
                {
                    g[i]->edges[i] = g[j];
                    printf("%d->%d",g[i]->edges[i]->data,g[j]->data);
                }
            }
        }
    }
    return g[0];
}

void print(GRAPH *g[], int numNodes)
{
    int i, j, k;
    for (i = 0; i < numNodes; i++)
    {
        for (j = 0; j < numNodes; j++)
        {
            for (k = 0; k < numNodes; k++)
            {
                if (g[i]->edges[j] == g[j]->edges[k])
                {
                    printf("\n%d->%d", g[i]->edges[j]->data, g[j]->edges[k]->data);
                }
            }
        }
    }
}
int main()
{
    int n, edge, i, from, to;
    GRAPH *g[MAX];
    printf("\n how many nodes you want in graph:");
    scanf("%d", &n);
    g[0] = create(g, n);
    printf("\n Enter how many edges you want to add:");
    scanf("%d", &edge);
    for (i = 0; i < edge; i++)
    {
        printf("\n Enter [%d] edge:", i);
        scanf("%d%d", &from, &to);
        g[0]=addEdge(g, from, to, n);
    }
    printf("\n The graph is :\n");
    print(g, n);
    getch();
    return 0;
}
