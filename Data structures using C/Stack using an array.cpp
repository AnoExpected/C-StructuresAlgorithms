#include <stdio.h>

#define MAX_SIZE 100

int top = -1; // Global variable to keep track of the top index of the stack

void push(int stack[], int value); // Function to push an element onto the stack
int pop(int stack[]); // Function to pop an element from the stack
int peek(int stack[]); // Function to get the value at the top of the stack without removing it
void display(int stack[]); // Function to display all the elements in the stack
int isEmpty(); // Function to check if the stack is empty
int isFull(); // Function to check if the stack is full

int main()
{
    int option;
    int stack[MAX_SIZE]; // Array to store the stack elements
    int value;

    do
    {
        printf("\n***** MAIN MENU *****");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. CHECK IF STACK IS EMPTY");
        printf("\n6. CHECK IF STACK IS FULL");
        printf("\n7. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printf("\nEnter the number to be pushed on the stack: ");
                scanf("%d", &value);
                push(stack, value);
                break;

            case 2:
                value = pop(stack);
                if (value != -1)
                    printf("\nThe value deleted from the stack is: %d", value);
                break;

            case 3:
                value = peek(stack);
                if (value != -1)
                    printf("\nThe value at the top of the stack is: %d", value);
                break;

            case 4:
                display(stack);
                break;

            case 5:
                if (isEmpty())
                    printf("\nThe stack is empty");
                else
                    printf("\nThe stack is not empty");
                break;

            case 6:
                if (isFull())
                    printf("\nThe stack is full");
                else
                    printf("\nThe stack is not full");
                break;

            case 7:
                printf("\nExiting the program...");
                break;

            default:
                printf("\nEnter a valid option!");
        }

    } while (option != 7);

    return 0;
}

// Function to push an element onto the stack
void push(int stack[], int value)
{
    if (top == MAX_SIZE - 1)
    {
        printf("\nStack Overflow: Cannot push element");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("\nElement %d pushed to the stack", value);
    }
}

// Function to pop an element from the stack
int pop(int stack[])
{
    if (top == -1)
    {
        printf("\nStack Underflow: Cannot pop element");
        return -1;
    }
    else
    {
        int value = stack[top];
        top--;
        return value;
    }
}

// Function to get the value at the top of the stack without removing it
int peek(int stack[])
{
    if (top == -1)
    {
        printf("\nStack is empty");
        return -1;
    }
    else
    {
        return stack[top];
    }
}

// Function to display all the elements in the stack
void display(int stack[])
{
    if (top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nStack elements: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}

// Function to check if the stack is empty
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

// Function to check if the stack is full
int isFull()
{
    if (top == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

