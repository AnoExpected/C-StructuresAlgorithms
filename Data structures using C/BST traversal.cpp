#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the binary tree
struct node {
  char data;
  struct node *left;
  struct node *right;
};

// Declare a global variable for the root of the binary tree
struct node *root = NULL;

// Function to create a binary tree
struct node *create() {
  struct node *p;
  char x;

  // Prompt the user to enter data for the node
  printf("Enter data (0 for no data):");
  scanf(" %c", &x);

  // If the user enters '0', return NULL (indicating no data)
  if (x == '0') {
    return NULL;
  }

  // Allocate memory for the new node
  p = (struct node *)malloc(sizeof(struct node));
  p->data = x;

  // Prompt the user to enter the left child of the current node
  printf("Enter left child of %c: \n", x);
  p->left = create();

  // Prompt the user to enter the right child of the current node
  printf("Enter right child of %c: \n", x);
  p->right = create();

  // Return the created node
  return p;
}

// Function to perform inorder traversal of the binary tree
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse the left subtree
    inorder(root->left);
    // Print the data of the current node
    printf("%2c", root->data);
    // Traverse the right subtree
    inorder(root->right);
  }
}

// Function to perform preorder traversal of the binary tree
void preorder(struct node *root) {
  if (root != NULL) {
    // Print the data of the current node
    printf("%2c", root->data);
    // Traverse the left subtree
    preorder(root->left);
    // Traverse the right subtree
    preorder(root->right);
  }
}

// Function to perform postorder traversal of the binary tree
void postorder(struct node *root) {
  if (root != NULL) {
    // Traverse the left subtree
    postorder(root->left);
    // Traverse the right subtree
    postorder(root->right);
    // Print the data of the current node
    printf("%2c", root->data);
  }
}

// Main function
int main() {
  int option;

  // Display a menu and perform operations until the user chooses to exit
  do {
    printf("\n\n *****MAIN MENU*****");
    printf("\n 1. Create a binary tree");
    printf("\n 2. In-order traversal");
    printf("\n 3. Pre-order traversal");
    printf("\n 4. Post-order traversal");
    printf("\n 5. EXIT");
    printf("\n Enter your option : ");
    scanf("%d", &option);

    // Perform different operations based on the user's choice
    switch (option) {
      case 1:
        // Create a binary tree
        root = create();
        break;
      case 2:
        // Perform in-order traversal
        printf("\n The elements after in-order traversal: ");
        inorder(root);
        break;
      case 3:
        // Perform pre-order traversal
        printf("\n The elements after pre-order traversal: ");
        preorder(root);
        break;
      case 4:
        // Perform post-order traversal
        printf("\n The elements after post-order traversal: ");
        postorder(root);
        break;
    }
  } while (option != 5);

  return 0;
}


