#include<stdio.h>

void towerOfHanoi(int n, char source, char dest, char aux)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }
    
    towerOfHanoi(n - 1, source, aux, dest);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    towerOfHanoi(n - 1, aux, dest, source);
}

int main()
{
    int n;
    
    printf("Enter number of disks: ");
    scanf("%d", &n);
    
    towerOfHanoi(n, 'A', 'C', 'B');
    
    return 0;
}