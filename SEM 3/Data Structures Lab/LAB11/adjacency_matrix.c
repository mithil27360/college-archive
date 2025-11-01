#include<stdio.h>
#include<stdlib.h>

void createDirectedGraph(int adj[][10], int vertices)
{
    int i, j, edges, u, v;
    
    for(i = 0; i < vertices; i++)
        for(j = 0; j < vertices; j++)
            adj[i][j] = 0;
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (u v):\n");
    for(i = 0; i < edges; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
    }
}

void createUndirectedGraph(int adj[][10], int vertices)
{
    int i, j, edges, u, v;
    
    for(i = 0; i < vertices; i++)
        for(j = 0; j < vertices; j++)
            adj[i][j] = 0;
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (u v):\n");
    for(i = 0; i < edges; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

void displayMatrix(int adj[][10], int vertices)
{
    int i, j;
    
    printf("\nAdjacency Matrix:\n");
    printf("  ");
    for(i = 0; i < vertices; i++)
        printf("%d ", i);
    printf("\n");
    
    for(i = 0; i < vertices; i++)
    {
        printf("%d ", i);
        for(j = 0; j < vertices; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

int main()
{
    int adj[10][10];
    int vertices, choice;
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    printf("1. Directed Graph\n2. Undirected Graph\nChoice: ");
    scanf("%d", &choice);
    
    if(choice == 1)
        createDirectedGraph(adj, vertices);
    else
        createUndirectedGraph(adj, vertices);
    
    displayMatrix(adj, vertices);
    
    return 0;
}