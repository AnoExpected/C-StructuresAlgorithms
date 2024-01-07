#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 100

int front = -1, rear = -1;  // Variables to keep track of the front and rear of the queue

// Function to insert an element into the queue
void enqueue(int arr[], int num);

// Function to delete an element from the queue
int dequeue(int arr[]);

// Function to get the value at the front of the queue
int peek(int arr[]);

// Function to check if the queue is empty or not
bool isEmpty();

// Function to check if the queue is full or not
bool isFull();

// Function to display the elements in the queue
void display(int arr[]);

int main()
{
    int queue[MAX_SIZE];  // Array to store the elements of the queue
    bool x;  // Variable to store the result of isEmpty and isFull functions
    int option;  // Variable to store the selected option from the menu
    int val;  // Variable to store the value to be inserted or deleted

    do
    {
        printf("\n\n **** MAIN MENU ****");
        printf("\n 1. Insert an element into the queue");
        printf("\n 2. Delete an element from the queue");
        printf("\n 3. Peek value of the queue");
        printf("\n 4. Is the queue empty");
        printf("\n 5. Is the queue full");
        printf("\n 6. Display the queue");
        printf("\n 7. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printf("\n Enter the number to be inserted in the queue: ");
                scanf("%d", &val);
                enqueue(queue, val);  // Call the enqueue function to insert the value
                break;
            case 2:
                val = dequeue(queue);  // Call the dequeue function to delete an element
                if (val != -1)
                    printf("\n The number deleted is: %d", val);
                break;
            case 3:
                val = peek(queue);  // Call the peek function to get the front value
                if (val != -1)
                    printf("\n The first value in the queue is: %d", queue[val]);
                break;
            case 4:
                x = isEmpty();  // Call the isEmpty function to check if the queue is empty
                if (x == true)
                    printf("\n The queue is empty");
                else
                    printf("\n The queue is not empty");
                break;
            case 5:
                x = isFull();  // Call the isFull function to check if the queue is full
                if (x == true)
                    printf("\n The queue is full");
                else
                    printf("\n The queue is not full");
                break;
            case 6:
                display(queue);  // Call the display function to print the elements of the queue
                break;
            default:
                printf("Enter correct option!");
        }
    } while (option != 7);

    return 0;
}

// Function to insert an element into the queue
void enqueue(int arr[], int num)
{
    if (rear == MAX_SIZE - 1)
        printf("\n Overflow");  // If the rear is at the maximum index, the queue is full
    else
    {
        if (front == -1)
            front = 0;  // If the queue is empty, set front to 0

        rear++;  // Move the rear pointer
        arr[rear] = num;  // Insert the element at the rear position
    }
}

// Function to delete an element from the queue
int dequeue(int arr[])
{
    int val;

    if (front == -1 || front > rear)
    {
        printf("\n Underflow");  // If the front is -1 or greater than the rear, the queue is empty
        return -1;
    }
    else
    {
        val = arr[front];  // Get the value at the front position
        front++;  // Move the front pointer

        if (front > rear)
            front = rear = -1;  // If the front becomes greater than the rear, the queue becomes empty

        return val;  // Return the deleted value
    }
}

// Function to get the value at the front of the queue
int peek(int arr[])
{
    if (front == -1 || front > rear)
    {
        printf("\n The queue is empty");  // If the front is -1 or greater than the rear, the queue is empty
        return -1;
    }
    else
    {
        return front;  // Return the front position
    }
}

// Function to check if the queue is empty or not
bool isEmpty()
{
    if (front == -1 || front > rear)
        return true;  // If the front is -1 or greater than the rear, the queue is empty
    else
        return false;
}

// Function to check if the queue is full or not
bool isFull()
{
    if (rear == MAX_SIZE - 1)
        return true;  // If the rear is at the maximum index, the queue is full
    else
        return false;
}

// Function to display the elements in the queue
void display(int arr[])
{
    if (front == -1 || front > rear)
        printf("\n The queue is empty");  // If the front is -1 or greater than the rear, the queue is empty
    else
    {
        printf("\n Elements in the queue are: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", arr[i]);  // Print the elements from front to rear
    }
}

