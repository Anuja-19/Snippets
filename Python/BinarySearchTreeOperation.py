# A Binary Tree Node
class Node:
# Constructor to create a new node
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


# A utility function to do inorder traversal of BST
# Printing
def inorder(root):
    if root is not None:
        inorder(root.left)
        print (root.key),
        inorder(root.right)


# A utility function to insert a new node with given key in BST
# Insertion 
def insert(node, key):
    # If the tree is empty, return a new node
    if node is None:
        return Node(key)

    # Otherwise recur down the tree
    if key < node.key:
        node.left = insert(node.left, key)
    else:
        node.right = insert(node.right, key)

    # return the (unchanged) node pointer
    return node

# A utility function to search a given key in BST 
# Searching
def search(root,key): 
	# Base Cases: root is null or key is present at root 
	if root is None or root.val == key: 
		return root 

	# Key is greater than root's key 
	if root.val < key: 
		return search(root.right,key) 
	
	# Key is smaller than root's key 
	return search(root.left,key) 


# Given a non-empty binary search tree, return the node with minum key value found in that tree. Note that the
# entire tree does not need to be searched
def minValueNode(node):
    current = node
    # loop down to find the leftmost leaf
    while(current.left is not None):
        current = current.left
    return current


# Given a binary search tree and a key, this function delete the key and returns the new root
# Deletion 
def deleteNode(root, key):
    # Base Case
    if root is None:
        return root

    # If the key to be deleted is smaller than the root's key then it lies in left subtree
    if key < root.key:
        root.left = deleteNode(root.left, key)

    # If the kye to be delete is greater than the root's key then it lies in right subtree
    elif(key > root.key):
        root.right = deleteNode(root.right, key)

    # If key is same as root's key, then this is the node to be deleted
    else:
        # Node with only one child or no child
        if root.left is None:
            temp = root.right
            root = None
            return temp

        elif root.right is None:
            temp = root.left
            root = None
            return temp

        # Node with two children: Get the inorder successor
        # (smallest in the right subtree)
        temp = minValueNode(root.right)

        # Copy the inorder successor's content to this node
        root.key = temp.key

        # Delete the inorder successor
        root.right = deleteNode(root.right, temp.key)
    return root


# Driver program to test above functions
    """ 
    Let us create following BST 
		  1 
	   /	 \ 
	   2	   5 
	 /  \     /  \ 
	3    4   6    7 
    """

root = None
root = insert(root, 1)
root = insert(root, 2)
root = insert(root, 3)
root = insert(root, 4)
root = insert(root, 5)
root = insert(root, 6)
root = insert(root, 7)

print ("Inorder traversal of the given tree")
inorder(root)

print ("\nDelete 3")
root = deleteNode(root, 3)
print ("Modified tree")
inorder(root)

print ("\nDelete 2")
root = deleteNode(root, 2)
print ("Modified tree")
inorder(root)


''' 
Output of the above program : 
Inorder traversal of the given tree
1 2 3 4 5 6 7

Delete 3
Modified tree
1 2 4 5 6 7

Delete 2
Modified tree
1 4 5 6 7
'''