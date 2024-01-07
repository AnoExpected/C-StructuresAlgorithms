#include <stdio.h>

// Function prototypes
void linear_search(int val, int n, int arr[]);
int linear_search_re(int val, int n, int arr[]);

int main() {
    int n, i, val, pos, option;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the value to search: ");
    scanf("%d", &val);
    
    printf("Enter 1 for Non-Recursive Function\n");
    printf("Enter 2 for Recursive Function\n");
    scanf("%d", &option);
    
    switch (option) {
        case 1:
            linear_search(val, n, arr);
            break;
        case 2:
            pos = linear_search_re(val, n, arr);
            if (pos != 0) {
                printf("Element %d is found at position %d using Recursion\n", val, pos);
            } else {
                printf("Element %d was not found using Recursion\n", val);
            }
            break;
        default:
            printf("Enter correct option!\n");
            break;
    }
    
    return 0;
}

// Non-recursive function to perform linear search
void linear_search(int val, int n, int arr[]) {
    int i, found = 0, pos = -1;
    
    for (i = 0; i < n; i++) {
        if (arr[i] == val) {
            found = 1;
            pos = i;
            printf("Element %d is found at position %d using Non-Recursion\n", val, i + 1);
            break;
        }
    }
    
    if (found == 0) {
        printf("Element %d was not found using Non-Recursion\n", val);
    }
}

// Recursive function to perform linear search
int linear_search_re(int val, int n, int arr[]) {
    if (n > 0) {
        if (arr[n - 1] == val) {
            return n;
        } else {
            return linear_search_re(val, n - 1, arr);
        }
    }
    
    return 0;
}

