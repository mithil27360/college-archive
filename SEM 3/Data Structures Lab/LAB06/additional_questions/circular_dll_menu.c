#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert(int val)
{
    struct Node *newNode = createNode(val);
    if(head == NULL)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }
    struct Node *tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
}

void deleteElement(int val)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    do
    {
        if(temp->data == val)
        {
            if(temp->next == temp)
            {
                free(temp);
                head = NULL;
                return;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if(temp == head)
                head = temp->next;
            free(temp);
            return;
        }
        temp = temp->next;
    }
    while(temp != head);
    printf("Element not found\n");
}

void display()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != head);
    printf("\n");
}

int main()
{
    int choice, val;
    
    while(1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        
        if(choice == 1)
        {
            printf("Enter value: ");
            scanf("%d", &val);
            insert(val);
        }
        else if(choice == 2)
        {
            printf("Enter value: ");
            scanf("%d", &val);
            deleteElement(val);
        }
        else if(choice == 3)
        {
            display();
        }
        else if(choice == 4)
        {
            break;
        }
    }
    
    return 0;
}