#include <stdio.h>

// Function prototypes
void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main()
{
    int arr[20];
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements to be sorted: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quicksort(arr, 0, n - 1);

    printf("After applying quick sort: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

// Function to perform quicksort
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Partition the array into two halves
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

// Function to partition the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    // Continue until the indices cross each other
    while (i < j)
    {
        // Find an element greater than the pivot from the left side
        while (arr[i] <= pivot && i < high)
        {
            i++;
        }

        // Find an element smaller than or equal to the pivot from the right side
        while (arr[j] > pivot && j >= low)
        {
            j--;
        }

        // Swap the elements if the left index is still smaller than the right index
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap the pivot element with the element at the right index (j)
    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;

    // Return the index of the pivot element
    return j;
}

