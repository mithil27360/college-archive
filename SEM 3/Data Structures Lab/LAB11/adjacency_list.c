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
}

void addUndirectedEdge(struct Graph *graph, int src, int dest)
{
    addEdge(graph, src, dest);
    addEdge(graph, dest, src);
}

void displayGraph(struct Graph *graph)
{
    int i;
    printf("\nAdjacency List:\n");
    for(i = 0; i < graph->numVertices; i++)
    {
        struct Node *temp = graph->adjLists[i];
        printf("%d: ", i);
        while(temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int vertices, edges, choice, i, u, v;
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    struct Graph *graph = createGraph(vertices);
    
    printf("1. Directed Graph\n2. Undirected Graph\nChoice: ");
    scanf("%d", &choice);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (u v):\n");
    for(i = 0; i < edges; i++)
    {
        scanf("%d%d", &u, &v);
        if(choice == 1)
            addEdge(graph, u, v);
        else
            addUndirectedEdge(graph, u, v);
    }
    
    displayGraph(graph);
    
    return 0;
}