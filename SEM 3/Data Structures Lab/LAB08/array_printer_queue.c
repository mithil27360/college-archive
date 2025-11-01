#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Task
{
    int docID;
    char name[50];
};

struct Queue
{
    struct Task tasks[100];
    int front;
    int rear;
};

void initQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q)
{
    return q->front == -1;
}

int isFull(struct Queue *q)
{
    return q->rear == 99;
}

void enqueue(struct Queue *q, int id, char *name)
{
    if(isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    
    if(q->front == -1)
        q->front = 0;
    
    q->rear++;
    q->tasks[q->rear].docID = id;
    strcpy(q->tasks[q->rear].name, name);
    printf("Task added: ID=%d, Name=%s\n", id, name);
}

void dequeue(struct Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Printing: ID=%d, Name=%s\n", q->tasks[q->front].docID, q->tasks[q->front].name);
    
    if(q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }
}

void display(struct Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    
    printf("\nPrinter Queue:\n");
    for(int i = q->front; i <= q->rear; i++)
    {
        printf("ID=%d, Name=%s\n", q->tasks[i].docID, q->tasks[i].name);
    }
}

int main()
{
    struct Queue q;
    initQueue(&q);
    
    int choice, id;
    char name[50];
    
    while(1)
    {
        printf("\n1. Add Print Job\n2. Process Print Job\n3. Display Queue\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        
        if(choice == 1)
        {
            printf("Enter document ID: ");
            scanf("%d", &id);
            printf("Enter document name: ");
            scanf("%s", name);
            enqueue(&q, id, name);
        }
        else if(choice == 2)
        {
            dequeue(&q);
        }
        else if(choice == 3)
        {
            display(&q);
        }
        else if(choice == 4)
        {
            break;
        }
    }
    
    return 0;
}