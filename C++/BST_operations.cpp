#include<iostream>
using namespace std;

struct Node {
	int data; 
	Node* left;
	Node* right;
};


Node* GetNode(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}


Node* Insert(Node* root,int data) {
	if(root == NULL) { 
		root = GetNode(data);
	}
	
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}

bool Search(Node* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}

Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}


struct Node* Delete(struct Node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);	
	else {
		
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		 
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			delete temp;
		}
		
		else { 
			struct Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
 

void Inorder(Node *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}
 
int main() {
    int n,val;
    Node* root = NULL; 
    cout<<"\n Enter number of elements/nodes:";
    cin>>n;
    int a[n];
	cout<<"\n enter elements:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        val=a[i];
        root = Insert(root,val);
    } 
	int choice;
	int number;
	cout<<"Enter number to search\n";
	cin>>number;
	if(Search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
    cout<<"\nEnter element to be deleted:";
    cin>>number;
    root = Delete(root,number);
	cout<<"Modified tree: ";
	Inorder(root);
	cout<<"\n";
}