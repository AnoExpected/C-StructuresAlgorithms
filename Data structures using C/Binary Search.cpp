#include<stdio.h>

// Recursive function to perform binary search
int binarySearchRecursive(int arr[], int beg, int end, int val);

// Non-recursive function to perform binary search
void binarySearchNonRecursive(int arr[], int beg, int end, int val);

int main()
{
    int n, val, pos, option;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in ascending order: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the value to search: ");
    scanf("%d", &val);
    printf("Enter 1 for Non-Recursive Function\n");
    printf("Enter 2 for Recursive Function\n");
    scanf("%d", &option);
    switch (option)
    {
        case 1:
            binarySearchNonRecursive(arr, 0, n - 1, val);
            break;
        case 2:
            pos = binarySearchRecursive(arr, 0, n - 1, val);
            if (pos != -1)
                printf("\nElement %d found at position %d using Recursion", val, pos + 1);
            else
                printf("\nElement %d not found using Recursion", val);
            break;
        default:
            printf("Enter the correct option!");
    }
}

// Recursive function to perform binary search
int binarySearchRecursive(int arr[], int beg, int end, int val)
{
    if (beg <= end)
    {
        int mid = (beg + end) / 2;
        if (arr[mid] == val)
            return mid; // Element found at the middle index
        if (arr[mid] > val)
            return binarySearchRecursive(arr, beg, mid - 1, val); // Search in the left half
        else
            return binarySearchRecursive(arr, mid + 1, end, val); // Search in the right half
    }
    return -1; // Element not found
}

// Non-recursive function to perform binary search
void binarySearchNonRecursive(int arr[], int beg, int end, int val)
{
    int mid, pos = -1;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (arr[mid] == val)
        {
            pos = mid + 1;
            printf("\nElement %d is found at position %d using Non-Recursion", val, pos);
            break;
        }
        else if (arr[mid] > val)
            end = mid - 1;
        else
            beg = mid + 1;
    }
    if (pos == -1)
        printf("\nElement %d was not found in the array using Non-Recursion", val);
}

