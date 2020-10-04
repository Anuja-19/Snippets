#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}TREE;

TREE *search(TREE *root, int skey);
TREE *insert(TREE *root, int ikey); // called lexical insertion
TREE *del(TREE *root, int dkey);
TREE *Min(TREE *root);
TREE *Max(TREE *root);
void preorder(TREE *root);
void inorder(TREE *root);
void postorder(TREE *root);
int height(TREE *root);
int leaf_nodes(TREE *root);
int number_of_nodes(TREE *root);

int main()
{
    TREE *root = NULL;
    TREE *ptr;
    int choice, k;
    while(1)
    {
        printf("\n\n***** BINARY SEARCH TREE MENU *****\n\n");
        printf("1.Search\n");
        printf("2.Insert\n");
        printf("3.Delete\n");
        printf("4.Preorder Traversal\n");
        printf("5.Inorder Traversal\n");
        printf("6.Postorder Traversal\n");
        printf("7.Height of the tree\n");
        printf("8.Find min and max\n");
        printf("9.Number of leaf nodes\n");
        printf("10.Total number of nodes\n");
        printf("11.Quit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: printf("Enter key to be searched : "); scanf("%d",&k); ptr = search(root,k);
                    if(ptr == NULL)
                        printf("Key not present!\n");
                    else
                        printf("Key present\n");
                    break;
            case 2: printf("Enter key to be inserted : "); scanf("%d",&k); root = insert(root,k); break;
            case 3: printf("Enter the key to be deleted : "); scanf("%d",&k); root = del(root,k); break;
            case 4: preorder(root); break;
            case 5: inorder(root); break;
            case 6: postorder(root); break;
            case 7: printf("Height of tree : %d\n",height(root)); break;
            case 8: ptr = Min(root);
                    if(ptr != NULL)
                        printf("Minimum key is : %d\n",ptr->data);
                    ptr = Max(root);
                    if(ptr != NULL)
                        printf("Maximum key is : %d\n",ptr->data);
                    break;
            case 9: printf("Number of leaf nodes : %d\n",leaf_nodes(root)); break;
            case 10: printf("Total number of nodes : %d\n",number_of_nodes(root)); break;
            case 11: exit(1);
            default: printf("Wrong Choice!\n"); break;
        }
    }
}

TREE *search(TREE *root, int skey)
{
    TREE *ptr = root;
    if(ptr == NULL)
    {
        printf("key not found\n");
        return NULL;
    }
    else if(skey < ptr->data) // serach  if left subtree
        search(ptr->lchild,skey);
    else if(skey > ptr->data) // search in right subtree
        search(ptr->rchild,skey);
    else                       // key found
        return ptr;
}

TREE *insert(TREE *root, int ikey) // called lexical insertion
{
    if(root == NULL)
    {
        root = (TREE *)malloc(sizeof(TREE));
        root->data = ikey;
        root->lchild = NULL;
        root->rchild = NULL;
    }
    else if(ikey < root->data) // Insert in left subtree
        root->lchild = insert(root->lchild,ikey);
    else if(ikey > root->data) // Insert in right subtree
        root->rchild = insert(root->rchild,ikey);
    else                       // Base case
        printf("Duplicate key!\n");
    return root;
}

TREE *del(TREE *root, int dkey)
{
    TREE *temp, *succ;

    if(root == NULL)
        return root;
    if(dkey < root->data) // dkey lesser than root
        root->lchild = del(root->lchild,dkey);
    else if(dkey > root->data) // dkey greater than root
        root->rchild = del(root->rchild,dkey);
    else // This is the node to be deleted
    {
        if(root->rchild!=NULL && root->lchild!=NULL) // 2 children
        {
            succ = root->rchild;
            while(succ->lchild != NULL) // traverse to the leftmost child
                succ = succ->lchild;
            root->data = succ->data;
            root->rchild = del(root->rchild, succ->data);
        }
        else
        {
            temp = root;
            if(root->lchild != NULL) // Only left child
                root = root->lchild;
            else if(root->rchild != NULL) // only right child
                root = root->rchild;
            else // No child
                root = NULL;
            free(temp);
        }
    }
}

TREE *Min(TREE *root) // Smallest node is the last node in the leftmost path
{
    TREE *ptr = root;
    if(ptr == NULL)
        return NULL;
    else if(ptr->lchild == NULL)
        return ptr;
    else
        return(Min(ptr->lchild));
}

TREE *Max(TREE *root) // Largest node is the last node in the rightmost path
{
    TREE *ptr = root;
    if(ptr == NULL)
        return NULL;
    else if(ptr->rchild == NULL)
        return ptr;
    else
        return(Max(ptr->rchild));
}

void preorder(TREE *root)
{
    TREE *ptr = root;
    if(ptr == NULL)
        return;
    printf("%d ",ptr->data);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

void inorder(TREE *root)
{
    TREE *ptr = root;
    if(ptr == NULL)
        return;
    inorder(ptr->lchild);
    printf("%d ",ptr->data);
    inorder(ptr->rchild);
}

void postorder(TREE *root)
{
    TREE *ptr = root;
    if(ptr == NULL)
        return;
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d ",ptr->data);
}

int height(TREE *root)
{
    int h_left, h_right;
    TREE *ptr = root;
    if(ptr == NULL)
        return 0;
    h_left = height(ptr->lchild);
    h_right = height(ptr->rchild);
    if(h_left > h_right)
        return 1 + h_left;
    else
        return 1 + h_right;
}

int leaf_nodes(TREE *root)
{
    if(root == NULL)
        return 0;
    if(root->lchild == NULL && root->rchild == NULL)
        return 1;
    return leaf_nodes(root->lchild) + leaf_nodes(root->rchild);
}

int number_of_nodes(TREE *root)
{
    int cnt = 0;
    if(root == NULL)
        return 0;
    number_of_nodes(root->lchild);
    cnt++;
    number_of_nodes(root->rchild);
    return cnt;
}

// BST using Arrays
/* int t[50];

void search(int skey);
void insert(int ikey);
void del(int dkey);
int isEmpty();
void preorder(int i);
void inorder(int i);
void postorder(int i);
int height(int i); // can it be done?
int leaf_nodes(int i);
int number_of_nodes(int i);

int main()
{
    int i=0;
    for(i=0 ; i<50 ; i++)
        t[i] = 0;

    int choice, k;
    while(1)
    {
        printf("\n\n***** BINARY SEARCH TREE MENU *****\n\n");
        printf("1.Search\n");
        printf("2.Insert\n");
        printf("3.Delete\n");
        printf("4.Preorder Traversal\n");
        printf("5.Inorder Traversal\n");
        printf("6.Postorder Traversal\n");
        printf("7.Height of the tree\n");
        printf("8.Number of leaf nodes\n");
        printf("9.Total number of nodes\n");
        printf("10.Quit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: printf("Enter key to be searched : "); scanf("%d",&k); search(k); break;
            case 2: printf("Enter key to be inserted : "); scanf("%d",&k); insert(k); break;
            case 3: printf("Enter the key to be deleted : "); scanf("%d",&k); del(k); break;
            case 4: preorder(i); break;
            case 5: inorder(i); break;
            case 6: postorder(i); break;
            case 7: printf("Height of tree : %d\n",height(i)); break;
            case 8: printf("Number of leaf nodes : %d\n",leaf_nodes(i)); break;
            case 9: printf("Total number of nodes : %d\n",number_of_nodes(i)); break;
            case 10: exit(1);
            default: printf("Wrong Choice!\n"); break;
        }
    }
}

// index of left is always 2i+1 and right is always 2i+2
void insert(int ikey)
{
    int i=0;
    if(t[i] == 0) // Empty tree
    {
        t[i] = ikey;
        return;
    }
    while(t[i] != 0)
    {
        if(ikey < t[i])
            i = 2*i+1;
        else
            i = 2*i+2;
    }
    t[i] = ikey;
}

void search(int skey)
{
    int i=0;
    if(isEmpty())
    {
        printf("Empty Tree\n");
        return;
    }
    while(t[i] != 0)
    {
        if(t[i] == skey)
        {
            printf("Key found\n");
            return;
        }
    }
}

void preorder(int i)
{
    if(isEmpty())
    {
        printf("Empty Tree\n");
        return;
    }
    printf("%d ",t[i]);
    preorder(2*i+1);
    preorder(2*i+2);
}

void inorder(int i)
{
    if(isEmpty())
    {
        printf("Empty Tree\n");
        return;
    }
    inorder(2*i+1);
    printf("%d ",t[i]);
    inorder(2*i+2);
}

void postorder(int i)
{
    if(isEmpty())
    {
        printf("Empty Tree\n");
        return;
    }
    postorder(2*i+1);
    postorder(2*i+2);
    printf("%d ",t[i]);
}

int isEmpty()
{
    int num=0;
    for(int i=0 ; i<50 ; i++)
    {
        if(t[i] == 0)
            num++;
    }
    if(num == 50)
        return 1;
    else
        return 0;
}

int number_of_nodes(int i)
{
    int cnt;
    for(int i=0 ; i<50; i++)
    {
        if(t[i] != 0)
            cnt++;
    }
    return cnt;
} */
