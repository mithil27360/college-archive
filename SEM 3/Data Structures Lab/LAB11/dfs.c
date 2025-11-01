#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int numVertices;
    struct Node **adjLists;
};

struct Node* createNode(int v)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    
    int i;
    for(i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFSUtil(struct Graph *graph, int vertex, int visited[])
{
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    struct Node *temp = graph->adjLists[vertex];
    
    while(temp)
    {
        int adjVertex = temp->vertex;
        
        if(visited[adjVertex] == 0)
            DFSUtil(graph, adjVertex, visited);
        
        temp = temp->next;
    }
}

void DFS(struct Graph *graph, int startVertex)
{
    int visited[100] = {0};
    
    printf("DFS Traversal: ");
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

int main()
{
    int vertices, edges, i, u, v, start;
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    struct Graph *graph = createGraph(vertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (u v):\n");
    for(i = 0; i < edges; i++)
    {
        scanf("%d%d", &u, &v);
        addEdge(graph, u, v);
    }
    
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    
    DFS(graph, start);
    
    return 0;
}