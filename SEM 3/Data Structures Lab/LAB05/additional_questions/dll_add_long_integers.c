#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int digit;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->digit = val;
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

void createNumber(struct Node **head, struct Node **tail, char *num)
{
    int i;
    for(i = 0; i < strlen(num); i++)
        insertRear(head, tail, num[i] - '0');
}

void traverse(struct Node *head)
{
    if(head == NULL)
    {
        printf("0\n");
        return;
    }
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d", temp->digit);
        temp = temp->next;
    }
    printf("\n");
}

void addNumbers(struct Node *tail1, struct Node *tail2, struct Node **rhead, struct Node **rtail)
{
    struct Node *t1 = tail1, *t2 = tail2;
    int carry = 0, sum;
    
    while(t1 != NULL || t2 != NULL || carry)
    {
        sum = carry;
        if(t1 != NULL)
        {
            sum += t1->digit;
            t1 = t1->prev;
        }
        if(t2 != NULL)
        {
            sum += t2->digit;
            t2 = t2->prev;
        }
        
        struct Node *newNode = createNode(sum % 10);
        if(*rhead == NULL)
        {
            *rhead = *rtail = newNode;
        }
        else
        {
            newNode->next = *rhead;
            (*rhead)->prev = newNode;
            *rhead = newNode;
        }
        
        carry = sum / 10;
    }
}

int main()
{
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;
    struct Node *rhead = NULL, *rtail = NULL;
    char num1[1000], num2[1000];
    
    printf("Enter first number: ");
    scanf("%s", num1);
    printf("Enter second number: ");
    scanf("%s", num2);
    
    createNumber(&head1, &tail1, num1);
    createNumber(&head2, &tail2, num2);
    
    printf("\nFirst number: ");
    traverse(head1);
    printf("Second number: ");
    traverse(head2);
    
    addNumbers(tail1, tail2, &rhead, &rtail);
    
    printf("Sum: ");
    traverse(rhead);
    
    return 0;
}