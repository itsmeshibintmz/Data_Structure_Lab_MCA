#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node of binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Root of binary tree
struct node *root= NULL;

// Function to create new node
struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data= data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert new data to tree
void insert(int data) {
    struct node *newNode = createNode(data);
    if(root == NULL) {
        root = newNode;
        return;
    }
    else {
        struct node *current = root, *parent = NULL;
        while(true) {
            parent = current;
            if(data < current->data) {
                current = current->left;
                if(current == NULL) {
                    parent->left = newNode;
                    return;
                }
            }

            else {
                current = current->right;
                if(current == NULL) {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}

// To find the minimum value
struct node* minNode(struct node *root) {
    if (root->left != NULL)
        return minNode(root->left);
    else
        return root;
}

// Delete a node from tree
struct node* deleteNode(struct node *node, int value) {
    if(node == NULL){
          return NULL;
    }
    else {
        if(value < node->data)
            node->left = deleteNode(node->left, value);
        else if(value > node->data)
            node->right = deleteNode(node->right, value);

        // If value is equal to node's data node to be deleted is found
        else {
            // Deletion node has no childern
            if(node->left == NULL && node->right == NULL)
                node = NULL;

            // Deletion node has on right child
            else if(node->left == NULL) {
                node = node->right;
            }

            // Deletion node has one right child
            else if(node->right == NULL) {
                node = node->left;
            }

            // Deletion node has two childern
            else {
                // Minmum value from right sub-tree
                struct node *temp = minNode(node->right);
                //Exchange the data between node and temp
                node->data = temp->data;
                //Delete the node duplicate node from right subtree
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }
}

// Inorder traversal
void inorderTraversal(struct node *node) {
    if(root == NULL){
        printf("Tree is empty\n");
            return;
    }
    else {
        if(node->left!= NULL)
            inorderTraversal(node->left);
        printf("%d ", node->data);
        if(node->right!= NULL)
            inorderTraversal(node->right);

    }
}

// Search a node in tree
struct node* search(int data) {
    struct node *current = root;
    printf("Visiting elements: ");
    while(current->data != data) {
        if(current != NULL) {
            printf("%d ",current->data);

            //go to left tree
            if(current->data > data) {
                current = current->left;
            }    
            //else go to right tree
            else {
                current = current->right;
            }
            //not found
            if(current == NULL) {
                printf("The given data %d not found in the tree\n", data);
                return NULL;
            }
        }
    }
    printf("\nData %d found in tree\n", data);
    //return current;
}

void main() {
    int data;
    int choice = 0;
    while(choice != 5) {
        printf("\n1.Insertion\n2.Deletion\n3.Inorder Traversal\n4.Search\n5.Quit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("\nEnter the node to be insertd into binary search tree: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2: 
                printf("\nEnter the node to be deleted from binary search tree: ");
                scanf("%d", &data);
                deleteNode(root, data);
                break;
            case 3: 
                printf("\nInorder traversal of tree\n");
                inorderTraversal(root);
                break;
            case 4: 
                printf("\nEnter the value to be searched in the tree: ");
                scanf("%d", &data);
                struct node *searchElement = NULL;
                search(data);
                break;
            case 5: 
                exit(0);
            default: 
                printf("Wrong choice !!!!!");
        }
    }
}
