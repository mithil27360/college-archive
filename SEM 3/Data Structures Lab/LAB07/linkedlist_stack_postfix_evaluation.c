#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

void initStack(struct Stack *s)
{
    s->top = NULL;
}

int isEmpty(struct Stack *s)
{
    return s->top == NULL;
}

void push(struct Stack *s, int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(struct Stack *s)
{
    if(isEmpty(s))
        return 0;
    
    struct Node *temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

int evaluatePostfix(char postfix[])
{
    struct Stack s;
    initStack(&s);
    
    int i;
    
    for(i = 0; i < strlen(postfix); i++)
    {
        char ch = postfix[i];
        
        if(isdigit(ch))
        {
            push(&s, ch - '0');
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int op2 = pop(&s);
            int op1 = pop(&s);
            int result;
            
            switch(ch)
            {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }
            
            push(&s, result);
        }
    }
    
    return pop(&s);
}

int main()
{
    char postfix[100];
    
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    
    int result = evaluatePostfix(postfix);
    
    printf("Result: %d\n", result);
    
    return 0;
}