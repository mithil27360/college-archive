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
        printf("Empty\n");
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

int search(struct Node *head, int val)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        if(temp->data == val)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void findUnion(struct Node *head1, struct Node *head2, struct Node **uhead, struct Node **utail)
{
    struct Node *temp = head1;
    while(temp != NULL)
    {
        if(!search(*uhead, temp->data))
            insertRear(uhead, utail, temp->data);
        temp = temp->next;
    }
    temp = head2;
    while(temp != NULL)
    {
        if(!search(*uhead, temp->data))
            insertRear(uhead, utail, temp->data);
        temp = temp->next;
    }
}

void findIntersection(struct Node *head1, struct Node *head2, struct Node **ihead, struct Node **itail)
{
    struct Node *temp = head1;
    while(temp != NULL)
    {
        if(search(head2, temp->data) && !search(*ihead, temp->data))
            insertRear(ihead, itail, temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;
    struct Node *uhead = NULL, *utail = NULL;
    struct Node *ihead = NULL, *itail = NULL;
    int n, val, i;
    
    printf("Enter size of list1: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insertRear(&head1, &tail1, val);
    }
    
    printf("Enter size of list2: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insertRear(&head2, &tail2, val);
    }
    
    findUnion(head1, head2, &uhead, &utail);
    findIntersection(head1, head2, &ihead, &itail);
    
    printf("\nUnion: ");
    traverse(uhead);
    printf("Intersection: ");
    traverse(ihead);
    
    return 0;
}