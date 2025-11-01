#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertRear(struct Node **head, struct Node **tail, int val)
{
    struct Node *newNode = createNode(val);
    if(*head == NULL)
    {
        *head = *tail = newNode;
        return;
    }
    (*tail)->next = newNode;
    newNode->prev = *tail;
    *tail = newNode;
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

void concatenate(struct Node **head1, struct Node **tail1, struct Node **head2, struct Node **tail2)
{
    if(*head1 == NULL)
    {
        *head1 = *head2;
        *tail1 = *tail2;
    }
    else if(*head2 != NULL)
    {
        (*tail1)->next = *head2;
        (*head2)->prev = *tail1;
        *tail1 = *tail2;
    }
    *head2 = NULL;
    *tail2 = NULL;
}

int main()
{
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;
    int n, val, i;
    
    printf("Enter size of X1: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insertRear(&head1, &tail1, val);
    }
    
    printf("Enter size of X2: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insertRear(&head2, &tail2, val);
    }
    
    printf("\nX1: ");
    traverse(head1);
    printf("X2: ");
    traverse(head2);
    
    concatenate(&head1, &tail1, &head2, &tail2);
    
    printf("\nAfter concatenation X1: ");
    traverse(head1);
    
    return 0;
}