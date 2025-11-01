#include<stdio.h>

int stringLength(char *str)
{
    int len = 0;
    while(*(str + len) != '\0')
        len++;
    return len;
}

void stringConcat(char *s1, char *s2)
{
    int i = 0, j = 0;
    
    while(*(s1 + i) != '\0')
        i++;
    
    while(*(s2 + j) != '\0')
    {
        *(s1 + i) = *(s2 + j);
        i++;
        j++;
    }
    *(s1 + i) = '\0';
}

int stringCompare(char *s1, char *s2)
{
    int i = 0;
    
    while(*(s1 + i) != '\0' && *(s2 + i) != '\0')
    {
        if(*(s1 + i) != *(s2 + i))
            return *(s1 + i) - *(s2 + i);
        i++;
    }
    return *(s1 + i) - *(s2 + i);
}

void insertSubstring(char *str, char *sub, int pos)
{
    int i, j, len1 = 0, len2 = 0;
    
    while(*(str + len1) != '\0')
        len1++;
    
    while(*(sub + len2) != '\0')
        len2++;
    
    for(i = len1; i >= pos; i--)
        *(str + i + len2) = *(str + i);
    
    for(j = 0; j < len2; j++)
        *(str + pos + j) = *(sub + j);
}

void deleteSubstring(char *str, int pos, int len)
{
    int i, slen = 0;
    
    while(*(str + slen) != '\0')
        slen++;
    
    for(i = pos; i <= slen - len; i++)
        *(str + i) = *(str + i + len);
}

int main()
{
    char s1[100], s2[100], sub[50];
    int choice, pos, len, result;
    
    printf("1. Length\n2. Concatenation\n3. Comparison\n4. Insert\n5. Delete\nChoice: ");
    scanf("%d", &choice);
    
    if(choice == 1)
    {
        printf("Enter string: ");
        scanf("%s", s1);
        printf("Length: %d\n", stringLength(s1));
    }
    else if(choice == 2)
    {
        printf("Enter first string: ");
        scanf("%s", s1);
        printf("Enter second string: ");
        scanf("%s", s2);
        stringConcat(s1, s2);
        printf("Result: %s\n", s1);
    }
    else if(choice == 3)
    {
        printf("Enter first string: ");
        scanf("%s", s1);
        printf("Enter second string: ");
        scanf("%s", s2);
        result = stringCompare(s1, s2);
        if(result == 0)
            printf("Equal\n");
        else if(result > 0)
            printf("First is greater\n");
        else
            printf("Second is greater\n");
    }
    else if(choice == 4)
    {
        printf("Enter main string: ");
        scanf("%s", s1);
        printf("Enter substring: ");
        scanf("%s", sub);
        printf("Enter position: ");
        scanf("%d", &pos);
        insertSubstring(s1, sub, pos);
        printf("Result: %s\n", s1);
    }
    else if(choice == 5)
    {
        printf("Enter string: ");
        scanf("%s", s1);
        printf("Enter position: ");
        scanf("%d", &pos);
        printf("Enter length: ");
        scanf("%d", &len);
        deleteSubstring(s1, pos, len);
        printf("Result: %s\n", s1);
    }
    
    return 0;
}