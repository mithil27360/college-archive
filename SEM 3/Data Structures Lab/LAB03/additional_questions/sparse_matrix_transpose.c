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

void transpose(struct Sparse s[], struct Sparse t[])
{
    int i, j, k = 1;
    
    t[0].row = s[0].col;
    t[0].col = s[0].row;
    t[0].val = s[0].val;
    
    for(i = 0; i < s[0].col; i++)
    {
        for(j = 1; j <= s[0].val; j++)
        {
            if(s[j].col == i)
            {
                t[k].row = s[j].col;
                t[k].col = s[j].row;
                t[k].val = s[j].val;
                k++;
            }
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
    
    transpose(s, t);
    
    printf("Transposed matrix:");
    displaySparse(t);
    
    return 0;
}