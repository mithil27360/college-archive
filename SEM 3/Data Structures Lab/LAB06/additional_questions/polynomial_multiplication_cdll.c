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

struct Node* createHeader()
{
    struct Node *header = createNode(0, -1);
    header->next = header;
    header->prev = header;
    return header;
}

void insertTerm(struct Node *header, int c, int e)
{
    struct Node *newNode = createNode(c, e);
    struct Node *tail = header->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = header;
    header->prev = newNode;
}

void display(struct Node *header)
{
    if(header->next == header)
    {
        printf("0\n");
        return;
    }
    struct Node *temp = header->next;
    while(temp != header)
    {
        if(temp->coeff > 0 && temp != header->next)
            printf("+");
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}

void addTerm(struct Node *result, int c, int e)
{
    struct Node *temp = result->next;
    while(temp != result)
    {
        if(temp->exp == e)
        {
            temp->coeff += c;
            return;
        }
        temp = temp->next;
    }
    insertTerm(result, c, e);
}

void sortPoly(struct Node *header)
{
    if(header->next == header)
        return;
    int swapped;
    struct Node *ptr1, *ptr2 = header;
    do
    {
        swapped = 0;
        ptr1 = header->next;
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

void multiplyPoly(struct Node *p1, struct Node *p2, struct Node *result)
{
    struct Node *t1 = p1->next;
    while(t1 != p1)
    {
        struct Node *t2 = p2->next;
        while(t2 != p2)
        {
            int c = t1->coeff * t2->coeff;
            int e = t1->exp + t2->exp;
            addTerm(result, c, e);
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    sortPoly(result);
}

int main()
{
    struct Node *p1 = createHeader();
    struct Node *p2 = createHeader();
    struct Node *result = createHeader();
    int n, c, e, i;
    
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter coeff and exp: ");
        scanf("%d%d", &c, &e);
        insertTerm(p1, c, e);
    }
    
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter coeff and exp: ");
        scanf("%d%d", &c, &e);
        insertTerm(p2, c, e);
    }
    
    printf("\nFirst polynomial: ");
    display(p1);
    printf("Second polynomial: ");
    display(p2);
    
    multiplyPoly(p1, p2, result);
    
    printf("Product: ");
    display(result);
    
    return 0;
}