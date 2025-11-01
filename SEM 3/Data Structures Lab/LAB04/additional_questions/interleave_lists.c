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

struct Node* interleave(struct Node **list1, struct Node **list2)
{
    if(*list1 == NULL)
        return *list2;
    if(*list2 == NULL)
        return *list1;
    
    struct Node *p1 = *list1, *p2 = *list2;
    struct Node *next1, *next2;
    
    while(p1 != NULL && p2 != NULL)
    {
        next1 = p1->next;
        next2 = p2->next;
        
        p1->next = p2;
        
        if(next1 == NULL)
        {
            p2->next = next2;
            break;
        }
        
        p2->next = next1;
        
        p1 = next1;
        p2 = next2;
    }
    
    struct Node *result = *list1;
    *list1 = NULL;
    *list2 = NULL;
    
    return result;
}

int main()
{
    struct Node *list1 = NULL, *list2 = NULL, *list3 = NULL;
    int n, val, i;
    
    printf("Enter size of list1: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insertEnd(&list1, val);
    }
    
    printf("Enter size of list2: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insertEnd(&list2, val);
    }
    
    list3 = interleave(&list1, &list2);
    
    printf("Interleaved list: ");
    traverse(list3);
    
    return 0;
}