#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int c, int e)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node **head, struct Node **tail, int c, int e)
{
    struct Node *newNode = createNode(c, e);
    if(*head == NULL)
    {
        *head = *tail = newNode;
        return;
    }
    (*tail)->next = newNode;
    newNode->prev = *tail;
    *tail = newNode;
}

void display(struct Node *head)
{
    if(head == NULL)
    {
        printf("0\n");
        return;
    }
    struct Node *temp = head;
    int first = 1;
    while(temp != NULL)
    {
        if(temp->coeff != 0)
        {
            if(!first && temp->coeff > 0)
                printf("+");
            if(temp->exp == 0)
                printf("%d", temp->coeff);
            else if(temp->exp == 1)
            {
                if(temp->coeff == 1)
                    printf("x");
                else if(temp->coeff == -1)
                    printf("-x");
                else
                    printf("%dx", temp->coeff);
            }
            else
            {
                if(temp->coeff == 1)
                    printf("x^%d", temp->exp);
                else if(temp->coeff == -1)
                    printf("-x^%d", temp->exp);
                else
                    printf("%dx^%d", temp->coeff, temp->exp);
            }
            first = 0;
        }
        temp = temp->next;
    }
    if(first)
        printf("0");
    printf("\n");
}

void sortPoly(struct Node **head, struct Node **tail)
{
    if(*head == NULL || (*head)->next == NULL)
        return;
    int swapped;
    struct Node *ptr1, *ptr2 = NULL;
    do
    {
        swapped = 0;
        ptr1 = *head;
        while(ptr1->next != ptr2)
        {
            if(ptr1->exp < ptr1->next->exp)
            {
                int tempC = ptr1->coeff;
                int tempE = ptr1->exp;
                ptr1->coeff = ptr1->next->coeff;
                ptr1->exp = ptr1->next->exp;
                ptr1->next->coeff = tempC;
                ptr1->next->exp = tempE;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    }
    while(swapped);
}

void addPolynomials(struct Node *p1, struct Node *p2, struct Node **result, struct Node **rtail)
{
    struct Node *t1 = p1, *t2 = p2;
    
    while(t1 != NULL && t2 != NULL)
    {
        if(t1->exp == t2->exp)
        {
            int sum = t1->coeff + t2->coeff;
            if(sum != 0)
                insertEnd(result, rtail, sum, t1->exp);
            t1 = t1->next;
            t2 = t2->next;
        }
        else if(t1->exp > t2->exp)
        {
            insertEnd(result, rtail, t1->coeff, t1->exp);
            t1 = t1->next;
        }
        else
        {
            insertEnd(result, rtail, t2->coeff, t2->exp);
            t2 = t2->next;
        }
    }
    
    while(t1 != NULL)
    {
        insertEnd(result, rtail, t1->coeff, t1->exp);
        t1 = t1->next;
    }
    
    while(t2 != NULL)
    {
        insertEnd(result, rtail, t2->coeff, t2->exp);
        t2 = t2->next;
    }
}

int main()
{
    struct Node *p1_head = NULL, *p1_tail = NULL;
    struct Node *p2_head = NULL, *p2_tail = NULL;
    struct Node *result_head = NULL, *result_tail = NULL;
    int n, c, e, i;
    
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &c, &e);
        insertEnd(&p1_head, &p1_tail, c, e);
    }
    sortPoly(&p1_head, &p1_tail);
    
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &c, &e);
        insertEnd(&p2_head, &p2_tail, c, e);
    }
    sortPoly(&p2_head, &p2_tail);
    
    printf("\nFirst polynomial: ");
    display(p1_head);
    
    printf("Second polynomial: ");
    display(p2_head);
    
    addPolynomials(p1_head, p2_head, &result_head, &result_tail);
    
    printf("Sum: ");
    display(result_head);
    
    return 0;
}