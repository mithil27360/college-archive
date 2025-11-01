#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

void initQueue(struct Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(struct Queue *q)
{
    return q->front == NULL;
}

void enqueue(struct Queue *q, int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if(q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    
    printf("Enqueued: %d\n", value);
}

int dequeue(struct Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    
    struct Node *temp = q->front;
    int value = temp->data;
    
    q->front = q->front->next;
    
    if(q->front == NULL)
        q->rear = NULL;
    
    free(temp);
    return value;
}

void display(struct Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    
    struct Node *temp = q->front;
    printf("Queue: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    initQueue(&q);
    
    int choice, value;
    
    while(1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        
        if(choice == 1)
        {
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(&q, value);
        }
        else if(choice == 2)
        {
            value = dequeue(&q);
            if(value != -1)
                printf("Dequeued: %d\n", value);
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