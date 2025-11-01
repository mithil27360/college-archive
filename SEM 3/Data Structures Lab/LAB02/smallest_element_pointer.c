#include<stdio.h>
#include<stdlib.h>

int findSmallest(int *arr, int n)
{
    int *ptr = arr;
    int min = *ptr;
    int i;
    
    for(i = 1; i < n; i++)
    {
        ptr++;
        if(*ptr < min)
            min = *ptr;
    }
    
    return min;
}

int main()
{
    int n, i, *arr, smallest;
    
    printf("Enter size: ");
    scanf("%d", &n);
    
    arr = (int*)malloc(n * sizeof(int));
    
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", arr + i);
    
    smallest = findSmallest(arr, n);
    
    printf("Smallest element: %d\n", smallest);
    
    free(arr);
    
    return 0;
}