#include<stdio.h>
#include<string.h>

#define MAX 100

struct Stack
{
    char items[MAX];
    int top;
};

void initStack(struct Stack *s)
{
    s->top = -1;
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

int isFull(struct Stack *s)
{
    return s->top == MAX - 1;
}

void push(struct Stack *s, char value)
{
    if(isFull(s))
    {
        printf("Stack overflow\n");
        return;
    }
    s->items[++s->top] = value;
}

char pop(struct Stack *s)
{
    if(isEmpty(s))
    {
        return '\0';
    }
    return s->items[s->top--];
}

int isMatchingPair(char open, char close)
{
    if(open == '(' && close == ')')
        return 1;
    if(open == '{' && close == '}')
        return 1;
    if(open == '[' && close == ']')
        return 1;
    return 0;
}

int checkParentheses(char expr[])
{
    struct Stack s;
    initStack(&s);
    
    int i;
    for(i = 0; i < strlen(expr); i++)
    {
        if(expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {
            push(&s, expr[i]);
        }
        else if(expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if(isEmpty(&s))
                return 0;
            
            char top = pop(&s);
            if(!isMatchingPair(top, expr[i]))
                return 0;
        }
    }
    
    return isEmpty(&s);
}

int main()
{
    char expr[MAX];
    
    printf("Enter expression: ");
    scanf("%s", expr);
    
    if(checkParentheses(expr))
        printf("Parentheses are balanced\n");
    else
        printf("Parentheses are not balanced\n");
    
    return 0;
}