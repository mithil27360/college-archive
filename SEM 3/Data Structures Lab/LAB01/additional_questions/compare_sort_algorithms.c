#include<stdio.h>

int main()
{
    int n, i, j, temp, min, key;
    int comp1 = 0, swap1 = 0, comp2 = 0, swap2 = 0, comp3 = 0, swap3 = 0;
    
    printf("Enter size: ");
    scanf("%d", &n);
    
    int arr[n], arr1[n], arr2[n], arr3[n];
    
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        arr1[i] = arr2[i] = arr3[i] = arr[i];
    }
    
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            comp1++;
            if(arr1[j] > arr1[j+1])
            {
                temp = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = temp;
                swap1++;
            }
        }
    }
    
    for(i = 0; i < n-1; i++)
    {
        min = i;
        for(j = i+1; j < n; j++)
        {
            comp2++;
            if(arr2[j] < arr2[min])
                min = j;
        }
        if(min != i)
        {
            temp = arr2[i];
            arr2[i] = arr2[min];
            arr2[min] = temp;
            swap2++;
        }
    }
    
    for(i = 1; i < n; i++)
    {
        key = arr3[i];
        j = i - 1;
        
        while(j >= 0 && arr3[j] > key)
        {
            comp3++;
            arr3[j+1] = arr3[j];
            swap3++;
            j--;
        }
        if(j >= 0)
            comp3++;
        arr3[j+1] = key;
    }
    
    printf("\nBubble Sort - Comparisons: %d, Swaps: %d\n", comp1, swap1);
    printf("Selection Sort - Comparisons: %d, Swaps: %d\n", comp2, swap2);
    printf("Insertion Sort - Comparisons: %d, Swaps: %d\n", comp3, swap3);
    
    return 0;
}