#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node
{
    char data;
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

void push(struct Stack *s, char value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

char pop(struct Stack *s)
{
    if(isEmpty(s))
        return '\0';
    
    struct Node *temp = s->top;
    char value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

char peek(struct Stack *s)
{
    if(isEmpty(s))
        return '\0';
    return s->top->data;
}

int isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char ch)
{
    if(ch == '^')
        return 3;
    if(ch == '*' || ch == '/')
        return 2;
    if(ch == '+' || ch == '-')
        return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    struct Stack s;
    initStack(&s);
    
    int i, j = 0;
    
    for(i = 0; i < strlen(infix); i++)
    {
        char ch = infix[i];
        
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            postfix[j++] = ch;
        }
        else if(ch == '(')
        {
            push(&s, ch);
        }
        else if(ch == ')')
        {
            while(!isEmpty(&s) && peek(&s) != '(')
            {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }
        else if(isOperator(ch))
        {
            while(!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    
    while(!isEmpty(&s))
    {
        postfix[j++] = pop(&s);
    }
    
    postfix[j] = '\0';
}

int main()
{
    char infix[100], postfix[100];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}