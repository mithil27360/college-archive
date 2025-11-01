#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char name[50];
    int time;
    int remainingTime;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

struct Node* createNode(char *n, int t)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, n);
    newNode->time = t;
    newNode->remainingTime = t;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void bookMachine(char *name, int time)
{
    struct Node *newNode = createNode(name, time);
    if(head == NULL)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
        current = head;
        printf("%s booked for %d minutes\n", name, time);
        return;
    }
    struct Node *tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    printf("%s booked for %d minutes\n", name, time);
}

void displayQueue()
{
    if(head == NULL)
    {
        printf("No bookings\n");
        return;
    }
    struct Node *temp = head;
    printf("\nCurrent Queue:\n");
    do
    {
        if(temp == current)
            printf(">>> ");
        printf("%s - %d/%d minutes", temp->name, temp->remainingTime, temp->time);
        if(temp == current)
            printf(" (Using)");
        printf("\n");
        temp = temp->next;
    }
    while(temp != head);
}

void tick()
{
    if(current == NULL)
    {
        printf("No active user\n");
        return;
    }
    
    printf("\n%s using machine... %d minutes remaining\n", current->name, current->remainingTime);
    current->remainingTime--;
    
    if(current->remainingTime == 0)
    {
        printf("%s finished using the machine\n", current->name);
        struct Node *temp = current;
        
        if(current->next == current)
        {
            free(temp);
            head = NULL;
            current = NULL;
            printf("Queue is now empty\n");
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            if(current == head)
                head = current->next;
            current = current->next;
            free(temp);
            printf("Next user: %s\n", current->name);
        }
    }
}

void runCycle(int cycles)
{
    int i;
    for(i = 0; i < cycles && current != NULL; i++)
    {
        printf("\n--- Minute %d ---\n", i + 1);
        tick();
    }
}

int main()
{
    int choice, time, cycles;
    char name[50];
    
    printf("Washing Machine Rental System\n");
    
    while(1)
    {
        printf("\n1. Book Machine\n2. Display Queue\n3. Simulate 1 Minute\n4. Run Multiple Minutes\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        
        if(choice == 1)
        {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter time (minutes): ");
            scanf("%d", &time);
            bookMachine(name, time);
        }
        else if(choice == 2)
        {
            displayQueue();
        }
        else if(choice == 3)
        {
            tick();
        }
        else if(choice == 4)
        {
            printf("Enter number of minutes: ");
            scanf("%d", &cycles);
            runCycle(cycles);
        }
        else if(choice == 5)
        {
            break;
        }
    }
    
    return 0;
}