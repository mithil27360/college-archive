#include<stdio.h>

int main()
{
    int r, c, i, j;
    
    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);
    
    int a[r][c], b[r][c], c_mat[r][c];
    
    printf("Enter matrix A:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    
    printf("Enter matrix B:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &b[i][j]);
    
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            c_mat[i][j] = (a[i][j] > b[i][j]) ? a[i][j] : b[i][j];
        }
    }
    
    printf("Matrix C:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%d ", c_mat[i][j]);
        printf("\n");
    }
    
    return 0;
}