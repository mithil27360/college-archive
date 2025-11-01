#include<stdio.h>

struct Sparse
{
    int row;
    int col;
    int val;
};

void readSparse(struct Sparse s[])
{
    int i;
    printf("Enter row col val for first element (metadata): ");
    scanf("%d%d%d", &s[0].row, &s[0].col, &s[0].val);
    
    for(i = 1; i <= s[0].val; i++)
    {
        printf("Enter row col val: ");
        scanf("%d%d%d", &s[i].row, &s[i].col, &s[i].val);
    }
}

void displaySparse(struct Sparse s[])
{
    int i;
    printf("\nRow\tCol\tVal\n");
    for(i = 0; i <= s[0].val; i++)
        printf("%d\t%d\t%d\n", s[i].row, s[i].col, s[i].val);
}

void fastTranspose(struct Sparse s[], struct Sparse t[])
{
    int rowTerms[100] = {0}, startPos[100] = {0};
    int i, j;
    
    t[0].row = s[0].col;
    t[0].col = s[0].row;
    t[0].val = s[0].val;
    
    if(s[0].val > 0)
    {
        for(i = 1; i <= s[0].val; i++)
            rowTerms[s[i].col]++;
        
        startPos[0] = 1;
        for(i = 1; i < s[0].col; i++)
            startPos[i] = startPos[i - 1] + rowTerms[i - 1];
        
        for(i = 1; i <= s[0].val; i++)
        {
            j = startPos[s[i].col]++;
            t[j].row = s[i].col;
            t[j].col = s[i].row;
            t[j].val = s[i].val;
        }
    }
}

int main()
{
    struct Sparse s[100], t[100];
    
    printf("Enter sparse matrix:\n");
    readSparse(s);
    
    printf("\nOriginal matrix:");
    displaySparse(s);
    
    fastTranspose(s, t);
    
    printf("\nTransposed matrix:");
    displaySparse(t);
    
    return 0;
}