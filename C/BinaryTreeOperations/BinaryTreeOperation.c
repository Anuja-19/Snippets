// C program to demonstrate insert operation in binary search tree.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

// function to create a new BST(Binary Search Tree) node
// Initialisation
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do print inorder traversal the binary search tree.
// Printing
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

/* A utility function to insert a new node with given key in BST */
// Insertion
struct node *insert(struct node *node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

// C function to search a given key in a given BST
// Searching
struct node *search(struct node *root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

/* Given a non-empty binary search tree, return the node with minimum key value found in that tree. Note that the entire tree does not 
   need to be searched. */
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
    return current; 
} 

/* Given a binary search tree and a key, this function deletes the key and returns the new root */
// Deletion
struct node *deleteNode(struct node *root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest in the right subtree)
        struct node *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Driver Program to test above functions
int main()
{
    /* 
    Let us create following BST 
		   1 
		/	 \ 
	   2	  5 
	  / \    / \ 
	 3  4   6   7 
    */
    struct node *root = NULL; 
	root = insert(root, 1); 
	root = insert(root, 2); 
	root = insert(root, 3); 
	root = insert(root, 4); 
	root = insert(root, 5); 
	root = insert(root, 6); 
	root = insert(root, 7); 

    // print inoder traversal of the BST
    inorder(root);

    printf("Delete 3\n"); 
    root = deleteNode(root, 3); 
    printf("Modified tree \n"); 
    inorder(root); 

    printf("\nDelete 2\n"); 
    root = deleteNode(root, 2); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 

    return 0;
}


/*
Output of the Above Program - 
1 2 3 4 5 6 7 

Delete 3
Modified tree 
1 2 4 5 6 7 

Delete 2
Modified tree 
1 4 5 6 7 
*/ 


