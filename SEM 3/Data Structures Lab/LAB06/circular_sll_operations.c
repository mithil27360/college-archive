#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first = NULL;
struct Node *last = NULL;

struct Node* createNode(int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(int val)
{
    struct Node *newNode = createNode(val);
    if(first == NULL)
    {
        first = last = newNode;
        last->next = first;
        printf("Inserted %d\n", val);
        return;
    }
    last->next = newNode;
    newNode->next = first;
    last = newNode;
    printf("Inserted %d\n", val);
}

void deleteBeginning()
{
    if(first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(first == last)
    {
        printf("Deleted %d\n", first->data);
        free(first);
        first = last = NULL;
        return;
    }
    struct Node *temp = first;
    printf("Deleted %d\n", first->data);
    first = first->next;
    last->next = first;
    free(temp);
}

void deleteEnd()
{
    if(first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(first == last)
    {
        printf("Deleted %d\n", first->data);
        free(first);
        first = last = NULL;
        return;
    }
    struct Node *temp = first;
    while(temp->next != last)
        temp = temp->next;
    printf("Deleted %d\n", last->data);
    free(last);
    last = temp;
    last->next = first;
}

void display()
{
    if(first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = first;
    printf("List: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != first);
    printf("\n");
}

int main()
{
    int choice, val;
    
    while(1)
    {
        printf("\n1. Insert at End\n2. Delete from Beginning\n3. Delete from End\n4. Display\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        
        if(choice == 1)
        {
            printf("Enter value: ");
            scanf("%d", &val);
            insertEnd(val);
            display();
        }
        else if(choice == 2)
        {
            deleteBeginning();
            display();
        }
        else if(choice == 3)
        {
            deleteEnd();
            display();
        }
        else if(choice == 4)
        {
            display();
        }
        else if(choice == 5)
        {
            break;
        }
    }
    
    return 0;
}