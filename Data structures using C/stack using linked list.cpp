#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the stack
struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL; // Global variable to store the top of the stack

// Function to push an element onto the stack
struct node *push(struct node *top, int val)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node)); // Create a new node
    ptr->data = val; // Set the data of the node

    if (top == NULL)
    {
        ptr->next = NULL; // Set the next pointer of the new node to NULL
        top = ptr; // Update the top pointer to point to the new node
    }
    else
    {
        ptr->next = top; // Set the next pointer of the new node to the current top node
        top = ptr; // Update the top pointer to point to the new node
    }

    return top; // Return the updated top pointer
}

// Function to pop an element from the stack
struct node *pop(struct node *top)
{
    if (top == NULL)
    {
        printf("\nSTACK UNDERFLOW"); // If the stack is empty, display an error message
    }
    else
    {
        struct node *ptr = top; // Create a temporary pointer to the top node
        top = top->next; // Update the top pointer to point to the next node
        printf("\nThe value deleted is %d", ptr->data); // Display the value being popped
        free(ptr); // Free the memory of the popped node
    }

    return top; // Return the updated top pointer
}

// Function to get the top element of the stack (peek)
int peek(struct node *top)
{
    if (top == NULL)
    {
        return -1; // Return -1 to indicate that the stack is empty
    }
    else
    {
        return top->data; // Return the value of the top node
    }
}

// Function to display the elements in the stack
struct node *display(struct node *top)
{
    struct node *ptr = top; // Create a pointer to traverse the stack

    if (top == NULL)
    {
        printf("\nSTACK UNDERFLOW"); // If the stack is empty, display an error message
    }
    else
    {
        printf("\nStack elements: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data); // Print the data of each node
            ptr = ptr->next; // Move to the next node
        }
    }

    return top; // Return the top pointer
}

int main()
{
    int val, option;

    do
    {
        printf("\n***** MAIN MENU *****");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nEnter the number to be pushed on stack: ");
            scanf("%d", &val);
            top = push(top, val); // Call the push function to push the value onto the stack
            break;
        case 2:
            top = pop(top); // Call the pop function to pop the top element from the stack
            break;
        case 3:
            val = peek(top); // Call the peek function to get the value at the top of the stack
            if (val != -1)
                printf("\nThe value at the top of the stack is: %d", val);
            else
                printf("\nSTACK IS EMPTY");
            break;
        case 4:
            top = display(top); // Call the display function to print the elements in the stack
            break;
        }
    } while (option != 5);

    return 0;
}


