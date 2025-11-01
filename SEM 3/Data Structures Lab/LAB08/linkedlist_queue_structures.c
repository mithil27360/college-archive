#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Patient
{
    char name[50];
    int age;
    int priority;
};

struct Node
{
    struct Patient patient;
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

void enqueue(struct Queue *q, char *name, int age, int priority)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->patient.name, name);
    newNode->patient.age = age;
    newNode->patient.priority = priority;
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
    
    printf("Patient added: %s, Age: %d, Priority: %d\n", name, age, priority);
}

void dequeue(struct Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    
    struct Node *temp = q->front;
    printf("Serving: %s, Age: %d, Priority: %d\n", 
           temp->patient.name, temp->patient.age, temp->patient.priority);
    
    q->front = q->front->next;
    
    if(q->front == NULL)
        q->rear = NULL;
    
    free(temp);
}

void display(struct Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    
    struct Node *temp = q->front;
    printf("\nPatient Queue:\n");
    printf("%-20s %-10s %-10s\n", "Name", "Age", "Priority");
    printf("----------------------------------------\n");
    while(temp != NULL)
    {
        printf("%-20s %-10d %-10d\n", 
               temp->patient.name, temp->patient.age, temp->patient.priority);
        temp = temp->next;
    }
}

int main()
{
    struct Queue q;
    initQueue(&q);
    
    int choice, age, priority;
    char name[50];
    
    while(1)
    {
        printf("\n1. Add Patient\n2. Serve Patient\n3. Display Queue\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        
        if(choice == 1)
        {
            printf("Enter patient name: ");
            scanf("%s", name);
            printf("Enter age: ");
            scanf("%d", &age);
            printf("Enter priority (1-5): ");
            scanf("%d", &priority);
            enqueue(&q, name, age, priority);
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