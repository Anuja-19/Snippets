#include<iostream>
using namespace std;
struct Node {
	int data; 
	Node* left;
	Node* right;
};
Node* Insert(Node* root,int data) {
	if(root == NULL) { 
		root = new Node;
        root->data=data;
        root->left=NULL;
        root->right=NULL;
	}
	
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}
void inorder(Node *root){
	if(root==NULL) return;    //check if node current node is the end
	
	inorder(root->left);
    cout<<root->data<<" ";
	inorder(root->right);
}
void preorder(Node *root){
	if(root==NULL) return;    //check if node current node is the end
	
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(Node *root){
	if(root==NULL) return;    //check if node current node is the end
	
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
int main()
{
    int n=0,val;
    Node* root = NULL; 
    cout<<"\n Enter number of elements/nodes:";
    cin>>n;
    int a[n];
	cout<<"\n enter elements:\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        val=a[i];
        root = Insert(root,val);
    } 
    cout<<"Inorder Traversal :\n";
    inorder(root);
    cout<<"Preorder Traversal :\n";
    preorder(root);
	cout<<"\n";
    cout<<"Postorder Traversal :\n";
	postorder(root);
	cout<<"\n";
}

