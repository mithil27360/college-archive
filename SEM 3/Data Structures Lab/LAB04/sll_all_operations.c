#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node **head, int val)
{
    struct Node *newNode = createNode(val);
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertBefore(struct Node **head, int val, int target)
{
    struct Node *newNode = createNode(val);
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if((*head)->data == target)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while(temp->next != NULL && temp->next->data != target)
        temp = temp->next;
    if(temp->next == NULL)
    {
        printf("Element not found\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfter(struct Node **head, int val, int target)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    while(temp != NULL && temp->data != target)
        temp = temp->next;
    if(temp == NULL)
    {
        printf("Element not found\n");
        return;
    }
    struct Node *newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteElement(struct Node **head, int val)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if((*head)->data == val)
    {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node *temp = *head;
    while(temp->next != NULL && temp->next->data != val)
        temp = temp->next;
    if(temp->next == NULL)
    {
        printf("Element not found\n");
        return;
    }
    struct Node *delNode = temp->next;
    temp->next = temp->next->next;
    free(delNode);
}

void traverse(struct Node *head)
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

void reverse(struct Node **head)
{
    struct Node *prev = NULL, *curr = *head, *next = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void sortList(struct Node **head)
{
    if(*head == NULL)
        return;
    int swapped;
    struct Node *ptr1, *ptr2 = NULL;
    do
    {
        swapped = 0;
        ptr1 = *head;
        while(ptr1->next != ptr2)
        {
            if(ptr1->data > ptr1->next->data)
            {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    }
    while(swapped);
}

void deleteAlternate(struct Node **head)
{
    if(*head == NULL || (*head)->next == NULL)
        return;
    struct Node *temp = *head;
    while(temp != NULL && temp->next != NULL)
    {
        struct Node *delNode = temp->next;
        temp->next = temp->next->next;
        free(delNode);
        temp = temp->next;
    }
}

void insertSorted(struct Node **head, int val)
{
    struct Node *newNode = createNode(val);
    if(*head == NULL || (*head)->data >= val)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while(temp->next != NULL && temp->next->data < val)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{
    struct Node *head = NULL;
    int choice, val, target;
    
    while(1)
    {
        printf("\n1. Insert End\n2. Insert Before\n3. Insert After\n4. Delete\n5. Traverse\n");
        printf("6. Reverse\n7. Sort\n8. Delete Alternate\n9. Insert Sorted\n10. Exit\nChoice: ");
        scanf("%d", &choice);
        
        if(choice == 1)
        {
            printf("Enter value: ");
            scanf("%d", &val);
            insertEnd(&head, val);
        }
        else if(choice == 2)
        {
            printf("Enter value: ");
            scanf("%d", &val);
            printf("Enter target: ");
            scanf("%d", &target);
            insertBefore(&head, val, target);
        }
        else if(choice == 3)
        {
            printf("Enter value: ");
            scanf("%d", &val);
            printf("Enter target: ");
            scanf("%d", &target);
            insertAfter(&head, val, target);
        }
        else if(choice == 4)
        {
            printf("Enter value: ");
            scanf("%d", &val);
            deleteElement(&head, val);
        }
        else if(choice == 5)
        {
            traverse(head);
        }
        else if(choice == 6)
        {
            reverse(&head);
        }
        else if(choice == 7)
        {
            sortList(&head);
        }
        else if(choice == 8)
        {
            deleteAlternate(&head);
        }
        else if(choice == 9)
        {
            printf("Enter value: ");
            scanf("%d", &val);
            insertSorted(&head, val);
        }
        else if(choice == 10)
        {
            break;
        }
    }
    
    return 0;
}