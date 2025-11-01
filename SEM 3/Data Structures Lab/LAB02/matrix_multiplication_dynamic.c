#include<stdio.h>
#include<stdlib.h>

void readMatrix(int **mat, int r, int c)
{
    int i, j;
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", (*(mat + i) + j));
}

void displayMatrix(int **mat, int r, int c)
{
    int i, j;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%d ", *(*(mat + i) + j));
        printf("\n");
    }
}

void multiplyMatrix(int **a, int **b, int **c, int r1, int c1, int c2)
{
    int i, j, k;
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            *(*(c + i) + j) = 0;
            for(k = 0; k < c1; k++)
                *(*(c + i) + j) += *(*(a + i) + k) * *(*(b + k) + j);
        }
    }
}

int main()
{
    int r1, c1, r2, c2, i;
    int **a, **b, **c;
    
    printf("Enter rows and columns of A: ");
    scanf("%d%d", &r1, &c1);
    
    printf("Enter rows and columns of B: ");
    scanf("%d%d", &r2, &c2);
    
    if(c1 != r2)
    {
        printf("Cannot multiply\n");
        return 0;
    }
    
    a = (int**)malloc(r1 * sizeof(int*));
    for(i = 0; i < r1; i++)
        *(a + i) = (int*)malloc(c1 * sizeof(int));
    
    b = (int**)malloc(r2 * sizeof(int*));
    for(i = 0; i < r2; i++)
        *(b + i) = (int*)malloc(c2 * sizeof(int));
    
    c = (int**)malloc(r1 * sizeof(int*));
    for(i = 0; i < r1; i++)
        *(c + i) = (int*)malloc(c2 * sizeof(int));
    
    printf("Enter matrix A:\n");
    readMatrix(a, r1, c1);
    
    printf("Enter matrix B:\n");
    readMatrix(b, r2, c2);
    
    multiplyMatrix(a, b, c, r1, c1, c2);
    
    printf("Product:\n");
    displayMatrix(c, r1, c2);
    
    for(i = 0; i < r1; i++)
        free(*(a + i));
    free(a);
    
    for(i = 0; i < r2; i++)
        free(*(b + i));
    free(b);
    
    for(i = 0; i < r1; i++)
        free(*(c + i));
    free(c);
    
    return 0;
}