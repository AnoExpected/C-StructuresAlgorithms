/* b) Use functions to perform insertion operation in a singly linked list */ 
#include<stdio.h>
#include<stdlib.h>

// Structure for a node in the linked list
struct node
{
    int data;
    struct node* next;
};

// Global variable to store the start of the linked list
struct node* start = NULL;

// Function prototypes
struct node* createll(struct node*);
void display(struct node*);
struct node* insert_beg(struct node*);
struct node* insert_end(struct node*);
struct node* insert_after(struct node*);

// Main function
int main()
{
    int option;
    do
    {
        printf("\n\n ***** MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Insert a node at the beginning of the list");
        printf("\n 4: Insert a node at the end of the list");
        printf("\n 5: Insert a node after a particular node in the list");
        printf("\n 6: Exit");
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
            case 3:
                start = insert_beg(start);
                break;
            case 4:
                start = insert_end(start);
                break;
            case 5:
                start = insert_after(start);
                break;
        }
    } while(option != 6);
}

// Function to create a linked list
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
        
        if(start == NULL)
        {
            newnode->next = NULL;
            start = newnode;
        }
        else
        {
            ptr = start;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->next = NULL;
        }
        
        printf("Enter the data or -1 to end: ");
        scanf("%d", &num);
    }
    
    return start;
}

// Function to display the linked list
void display(struct node* start)
{
    struct node* ptr = start;
    
    while(ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

// Function to insert a node at the beginning of the list
struct node* insert_beg(struct node* start)
{
    struct node* newnode;
    int num;
    
    printf("\nEnter the data: ");
    scanf("%d", &num);
    
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = start;
    start = newnode;
    
    return start;
}

// Function to insert a node at the end of the list
struct node* insert_end(struct node* start)
{
    int num;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    
    struct node* new_node;
    struct node* ptr;
    
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    
    ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;
    
    ptr->next = new_node;
    
    return start;
}

// Function to insert a node after a particular node in the list
struct node* insert_after(struct node* start)
{
    int num, val;
    
    printf("\nEnter the data: ");
    scanf("%d", &num);
    
    printf("Enter a value after which the new node is inserted: ");
    scanf("%d", &val);
    
    struct node* new_node;
    struct node* ptr;
    struct node* preptr;
    
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    
    ptr = start;
    preptr = ptr;
    
    while(preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    
    preptr->next = new_node;
    new_node->next = ptr;
    
    return start;
}

