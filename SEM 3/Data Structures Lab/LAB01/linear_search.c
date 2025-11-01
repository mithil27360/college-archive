#include<stdio.h>

int main()
{
    int n, key, i, pos = -1;
    
    printf("Enter size: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("Enter key: ");
    scanf("%d", &key);
    
    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            pos = i;
            break;
        }
    }
    
    if(pos != -1)
        printf("Found at position %d\n", pos);
    else
        printf("Not found\n");
    
    return 0;
}