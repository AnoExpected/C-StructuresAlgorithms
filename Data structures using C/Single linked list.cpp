#include<stdio.h>
#include<stdlib.h>

// Structure to represent a node in the linked list
struct node
{
    int data;
    struct node* next;
};

struct node* start = NULL; // Global variable to store the starting node of the linked list

// Function prototypes
struct node* createll(struct node*);
void display(struct node*);

// Main function
int main()
{
    int option, val;
    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Exit");
        printf("\nEnter your option: ");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                start = createll(start);
                printf("\nLinked list is created");
                break;
            case 2:
                display(start);
                break;
        }
    } while(option != 3);
}

// Function to create a singly linked list
struct node* createll(struct node* start)
{
    struct node* newnode;
    struct node* ptr;
    int num;
    
    printf("\nEnter the data or -1 to end: ");
    scanf("%d", &num);
    
    while(num != -1)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = num;
        
        if(start == NULL) // If the list is empty
        {
            newnode->next = NULL;
            start = newnode;
        }
        else // If the list is not empty
        {
            ptr = start;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->next = NULL;
        }
        
        printf("\nEnter the data or -1 to end: ");
        scanf("%d", &num);
    }
    
    return start;
}

// Function to display the linked list
void display(struct node* start)
{
    struct node* ptr;
    ptr = start;
    
    while(ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

