#include<stdio.h>

int main()
{
    int r1, c1, r2, c2, i, j, k, choice;
    
    printf("Enter rows and columns of A: ");
    scanf("%d%d", &r1, &c1);
    
    printf("Enter rows and columns of B: ");
    scanf("%d%d", &r2, &c2);
    
    int a[r1][c1], b[r2][c2];
    
    printf("Enter matrix A:\n");
    for(i = 0; i < r1; i++)
        for(j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);
    
    printf("Enter matrix B:\n");
    for(i = 0; i < r2; i++)
        for(j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);
    
    printf("1. Multiply\n2. Add\n3. Magic Square\nChoice: ");
    scanf("%d", &choice);
    
    if(choice == 1)
    {
        if(c1 != r2)
        {
            printf("Cannot multiply\n");
            return 0;
        }
        
        int mul[r1][c2];
        
        for(i = 0; i < r1; i++)
        {
            for(j = 0; j < c2; j++)
            {
                mul[i][j] = 0;
                for(k = 0; k < c1; k++)
                    mul[i][j] += a[i][k] * b[k][j];
            }
        }
        
        printf("Product:\n");
        for(i = 0; i < r1; i++)
        {
            for(j = 0; j < c2; j++)
                printf("%d ", mul[i][j]);
            printf("\n");
        }
    }
    else if(choice == 2)
    {
        if(r1 != r2 || c1 != c2)
        {
            printf("Cannot add\n");
            return 0;
        }
        
        int sum[r1][c1];
        
        for(i = 0; i < r1; i++)
            for(j = 0; j < c1; j++)
                sum[i][j] = a[i][j] + b[i][j];
        
        printf("Sum:\n");
        for(i = 0; i < r1; i++)
        {
            for(j = 0; j < c1; j++)
                printf("%d ", sum[i][j]);
            printf("\n");
        }
    }
    else if(choice == 3)
    {
        if(r1 != c1)
        {
            printf("Not a square matrix\n");
            return 0;
        }
        
        int sum = 0, flag = 1;
        
        for(j = 0; j < c1; j++)
            sum += a[0][j];
        
        for(i = 1; i < r1; i++)
        {
            int rsum = 0;
            for(j = 0; j < c1; j++)
                rsum += a[i][j];
            if(rsum != sum)
                flag = 0;
        }
        
        for(j = 0; j < c1; j++)
        {
            int csum = 0;
            for(i = 0; i < r1; i++)
                csum += a[i][j];
            if(csum != sum)
                flag = 0;
        }
        
        int d1 = 0, d2 = 0;
        for(i = 0; i < r1; i++)
        {
            d1 += a[i][i];
            d2 += a[i][r1-i-1];
        }
        
        if(d1 != sum || d2 != sum)
            flag = 0;
        
        if(flag)
            printf("Magic square\n");
        else
            printf("Not magic square\n");
    }
    
    return 0;
}