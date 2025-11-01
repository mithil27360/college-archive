#include<stdio.h>

int main()
{
    int n, key, i, low, high, mid, pos = -1;
    
    printf("Enter size: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter sorted elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("Enter key: ");
    scanf("%d", &key);
    
    low = 0;
    high = n - 1;
    
    while(low <= high)
    {
        mid = (low + high) / 2;
        
        if(arr[mid] == key)
        {
            pos = mid;
            break;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    if(pos != -1)
        printf("Found at position %d\n", pos);
    else
        printf("Not found\n");
    
    return 0;
}