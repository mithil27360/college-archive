#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node* createNode(int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertRear(int val)
{
    struct Node *newNode = createNode(val);
    if(head == NULL)
    {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void deleteRear()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(head == tail)
    {
        free(head);
        head = tail = NULL;
        return;
    }
    struct Node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
}

void insertAtPosition(int val, int pos)
{
    if(pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    struct Node *newNode = createNode(val);
    if(pos == 1)
    {
        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return;
    }
    struct Node *temp = head;
    int i;
    for(i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if(temp == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode;
    temp->next = newNode;
}

void deleteAtPosition(int pos)
{
    if(head == NULL || pos < 1)
    {
        printf("Invalid operation\n");
        return;
    }
    struct Node *temp = head;
    int i;
    for(i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if(temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    if(temp->prev == NULL)
        head = temp->next;
    else
        temp->prev->next = temp->next;
    if(temp->next == NULL)
        tail = temp->prev;
    else
        temp->next->prev = temp->prev;
    free(temp);
}

void insertAfter(int val, int target)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    while(temp != NULL && temp->data != target)
        temp = temp->next;
    if(temp == NULL)
    {
        printf("Element not found\n");
        return;
    }
    struct Node *newNode = createNode(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode;
    temp->next = newNode;
}

void insertBefore(int val, int target)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    while(temp != NULL && temp->data != target)
        temp = temp->next;
    if(temp == NULL)
    {
        printf("Element not found\n");
        return;
    }
    struct Node *newNode = createNode(val);
    newNode->prev = temp->prev;
    newNode->next = temp;
    if(temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode;
    temp->prev = newNode;
}

void traverseForward()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void traverseReverse()
{
    if(tail == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = tail;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    int choice, val, pos, target;
    
    while(1)
    {
        printf("\n1. Insert Rear\n2. Delete Rear\n3. Insert at Position\n4. Delete at Position\n");
        printf("5. Insert After\n6. Insert Before\n7. Traverse Forward\n8. Traverse Reverse\n9. Exit\nChoice: ");
        scanf("%d", &choice);
        
        if(choice == 1)
        {
            printf("Enter value: ");
            scanf("%d", &val);
            insertRear(val);
        }
        else if(choice == 2)
        {
            deleteRear();
        }
        else if(choice == 3)
        {
            printf("Enter value: ");
            scanf("%d", &val);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAtPosition(val, pos);
        }
        else if(choice == 4)
        {
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
        }
        else if(choice == 5)
        {
            printf("Enter value: ");
            scanf("%d", &val);
            printf("Enter target: ");
            scanf("%d", &target);
            insertAfter(val, target);
        }
        else if(choice == 6)
        {
            printf("Enter value: ");
            scanf("%d", &val);
            printf("Enter target: ");
            scanf("%d", &target);
            insertBefore(val, target);
        }
        else if(choice == 7)
        {
            traverseForward();
        }
        else if(choice == 8)
        {
            traverseReverse();
        }
        else if(choice == 9)
        {
            break;
        }
    }
    
    return 0;
}