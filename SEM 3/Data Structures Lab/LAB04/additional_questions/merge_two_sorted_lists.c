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

void traverse(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* mergeSorted(struct Node **x, struct Node **y)
{
    if(*x == NULL)
        return *y;
    if(*y == NULL)
        return *x;
    
    struct Node *z = NULL, *tail = NULL;
    
    if((*x)->data <= (*y)->data)
    {
        z = *x;
        *x = (*x)->next;
    }
    else
    {
        z = *y;
        *y = (*y)->next;
    }
    tail = z;
    
    while(*x != NULL && *y != NULL)
    {
        if((*x)->data <= (*y)->data)
        {
            tail->next = *x;
            *x = (*x)->next;
        }
        else
        {
            tail->next = *y;
            *y = (*y)->next;
        }
        tail = tail->next;
    }
    
    if(*x != NULL)
        tail->next = *x;
    else
        tail->next = *y;
    
    *x = NULL;
    *y = NULL;
    
    return z;
}

int main()
{
    struct Node *x = NULL, *y = NULL, *z = NULL;
    int n, val, i;
    
    printf("Enter size of list X: ");
    scanf("%d", &n);
    printf("Enter sorted elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insertEnd(&x, val);
    }
    
    printf("Enter size of list Y: ");
    scanf("%d", &n);
    printf("Enter sorted elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insertEnd(&y, val);
    }
    
    z = mergeSorted(&x, &y);
    
    printf("Merged list Z: ");
    traverse(z);
    
    return 0;
}