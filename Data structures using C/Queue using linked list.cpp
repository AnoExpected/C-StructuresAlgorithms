#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for linked list
struct node
{
    int data;
    struct node *next;
};

// Pointers to track front and rear of the queue
struct node *front = NULL;
struct node *rear = NULL;

// Function declarations
struct node *insert(struct node *, int);
struct node *delete_element(struct node *);
struct node *display(struct node *);
void peek(struct node *);
bool isEmpty(struct node *);

// Main function
int main()
{
    int val, option;
    bool x;

    do
    {
        printf("\n\n *****MAIN MENU*****");
        printf("\n 1. Insert an element");
        printf("\n 2. Delete an element");
        printf("\n 3. Peek value");
        printf("\n 4. Check if the queue is empty");
        printf("\n 5. Display the queue");
        printf("\n 6. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printf("\n Enter the number to insert in the queue: ");
                scanf("%d", &val);
                front = insert(front, val);
                break;

            case 2:
                front = delete_element(front);
                break;

            case 3:
                peek(front);
                break;

            case 4:
                x = isEmpty(front);
                if (x == true)
                    printf("\n The queue is empty");
                else
                    printf("\n The queue is not empty");
                break;

            case 5:
                front = display(front);
                break;

            default:
                printf("Enter a correct option!");
        }
    } while (option != 6);

    return 0;
}

// Function to insert an element into the queue
struct node *insert(struct node *front, int val)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;

    if (front == NULL)
    {
        front = ptr;
        rear = ptr;
        front->next = rear->next = NULL;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
        rear->next = NULL;
    }

    return front;
}

// Function to delete an element from the queue
struct node *delete_element(struct node *front)
{
    struct node *ptr;
    ptr = front;

    if (front == NULL)
        printf("\n UNDERFLOW");
    else
    {
        front = front->next;
        printf("\n The value being deleted is: %d", ptr->data);
        free(ptr);
    }

    return front;
}

// Function to display the front value of the queue
void peek(struct node *front)
{
    if (front == NULL)
        printf("\n QUEUE IS EMPTY");
    else
        printf("\n Peek = %d", front->data);
}

// Function to check if the queue is empty
bool isEmpty(struct node *front)
{
    if (front == NULL)
        return true;
    else
        return false;
}

// Function to display the elements of the queue
struct node *display(struct node *front)
{
    struct node *ptr;
    ptr = front;

    if (ptr == NULL)
        printf("\n QUEUE IS EMPTY");
    else
    {
        printf("\n");
        while (ptr != rear)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\t", ptr->data);
    }

    return front;
}

