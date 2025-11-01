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

struct Node* createListRecursive(int n)
{
    int val;
    if(n == 0)
        return NULL;
    
    printf("Enter value: ");
    scanf("%d", &val);
    
    struct Node *newNode = createNode(val);
    newNode->next = createListRecursive(n - 1);
    
    return newNode;
}

void traverseRecursive(struct Node *head)
{
    if(head == NULL)
        return;
    
    printf("%d ", head->data);
    traverseRecursive(head->next);
}

int main()
{
    struct Node *head = NULL;
    int n;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    head = createListRecursive(n);
    
    printf("List: ");
    traverseRecursive(head);
    printf("\n");
    
    return 0;
}