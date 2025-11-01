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

void BFS(struct Graph *graph, int startVertex)
{
    int visited[100] = {0};
    int queue[100];
    int front = 0, rear = 0;
    
    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    
    printf("BFS Traversal: ");
    
    while(front < rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        
        struct Node *temp = graph->adjLists[currentVertex];
        
        while(temp)
        {
            int adjVertex = temp->vertex;
            
            if(visited[adjVertex] == 0)
            {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
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
    
    BFS(graph, start);
    
    return 0;
}