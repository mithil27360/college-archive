#include<stdio.h>

void selectionSort(int *arr, int n, int index)
{
    int *p, *min_ptr, temp;
    int min_index = index;
    
    if(index >= n - 1)
        return;
    
    p = arr + index + 1;
    min_ptr = arr + index;
    
    for(int i = index + 1; i < n; i++)
    {
        if(*p < *min_ptr)
        {
            min_ptr = p;
            min_index = i;
        }
        p++;
    }
    
    temp = *(arr + index);
    *(arr + index) = *min_ptr;
    *min_ptr = temp;
    
    selectionSort(arr, n, index + 1);
}

int main()
{
    int n, i;
    
    printf("Enter size: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", arr + i);
    
    selectionSort(arr, n, 0);
    
    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\n");
    
    return 0;
}