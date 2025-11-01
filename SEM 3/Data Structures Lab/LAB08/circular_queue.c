#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct CircularQueue
{
    int items[MAX];
    int front;
    int rear;
};

void initQueue(struct CircularQueue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct CircularQueue *q)
{
    return q->front == -1;
}

int isFull(struct CircularQueue *q)
{
    return (q->rear + 1) % MAX == q->front;
}

void enqueue(struct CircularQueue *q, int value)
{
    if(isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    
    if(q->front == -1)
        q->front = 0;
    
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(struct CircularQueue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    
    int value = q->items[q->front];
    
    if(q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX;
    }
    
    return value;
}

void display(struct CircularQueue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue: ");
    int i = q->front;
    while(1)
    {
        printf("%d ", q->items[i]);
        if(i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    struct CircularQueue q;
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