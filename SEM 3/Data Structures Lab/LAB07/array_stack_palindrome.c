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
        printf("Stack underflow\n");
        return '\0';
    }
    return s->items[s->top--];
}

int isPalindrome(char str[])
{
    struct Stack s;
    initStack(&s);
    
    int len = strlen(str);
    int i;
    
    for(i = 0; i < len; i++)
    {
        push(&s, str[i]);
    }
    
    for(i = 0; i < len; i++)
    {
        if(str[i] != pop(&s))
            return 0;
    }
    
    return 1;
}

int main()
{
    char str[MAX];
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    if(isPalindrome(str))
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);
    
    return 0;
}