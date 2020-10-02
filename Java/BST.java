package Java;

import java.util.Scanner;

class BST {

    class Node {

        // every tree node has data and a pointer to the left and right side
        int data;
        Node leftSideNode, rightSideNode;

        Node(int data) {
            // Initializing values

            this.data = data;
            this.leftSideNode = null;
            this.rightSideNode = null;
        }

    }

    // Every tree has a root node
    Node rootNode;

    // Initialinzing new tree
    BST() {
        this.rootNode = null;
    }

    // Create a new Binary Search Tree
    static BST CreateBST() {
        return new BST();
    }

    // Updates the root of the BST after insertion
    void insertIntoBST(int newInsertion) {
        this.rootNode = insertNewNodes(this.rootNode, newInsertion);
    }

    // Actual node insertion occurs here
    Node insertNewNodes(Node rootNode, int data) {
        // BST is empty, then this data will form the root
        if (rootNode == null) {
            rootNode = new Node(data);
            return rootNode;
        }

        // newly added data is lesser than the root node, we recurse the process
        // considering left child as root
        if (data < rootNode.data) {
            rootNode.leftSideNode = insertNewNodes(rootNode.leftSideNode, data);
        }
        // newly added data is greater than the root node, we recurse the process
        // considering right child as root
        else if (data > rootNode.data) {
            rootNode.rightSideNode = insertNewNodes(rootNode.rightSideNode, data);
        }

        // return the root node pointer
        return rootNode;

    }

    // search data record
    boolean searchNodeBST(int data) {
        // if our BST is empty
        if (this.rootNode == null) {
            return false;
        }

        // start comparing from the root value data
        Node traversalNode = this.rootNode;

        while (traversalNode != null) {
            // return true if we find out the node
            if (data == traversalNode.data) {
                return true;
            }
            // if our data is greater than the rootNode data, then it ought to lie in the
            // right sub tree
            else if (data > traversalNode.data) {
                traversalNode = traversalNode.rightSideNode;
            }
            // if our data is lesser than the rootNode data, then it ought to lie in the
            // left sub tree
            else {
                traversalNode = traversalNode.leftSideNode;
            }
        }
        // if we do not find it still, it is not there in the BST
        return false;
    }

    // Updates the root of the BST after deletion
    void deleteFromBST(int data) {
        this.rootNode = deleteValueFromBST(this.rootNode, data);
    }

    Node deleteValueFromBST(Node rootNode, int data) {
        // If the tree is empty
        if (rootNode == null) {
            return rootNode;
        }

        // Else recurring down the tree
        // handle the case if the tree has only one side of subtree
        if (rootNode.leftSideNode == null) {
            return rootNode.rightSideNode;
        } else if (rootNode.rightSideNode == null) {
            return rootNode.leftSideNode;
        }

        else {
            // for nodes with two children, calculating inorder successor (smallest node in
            // right sub-tree)
            rootNode.data = minValue(rootNode.rightSideNode);

            // Delete the inorder successor
            rootNode.rightSideNode = deleteValueFromBST(rootNode.rightSideNode, data);
        }

        return rootNode;
    }

    int minValue(Node rootNode) {
        // initialize the data to root's data
        int minimumValue = rootNode.data;

        // keep on traversing left till null, and update lowest find
        while (rootNode.leftSideNode != null) {
            minimumValue = rootNode.leftSideNode.data;
            rootNode = rootNode.leftSideNode;
        }
        return minimumValue;
    }

    // This method displays inorder traversals 
    void inorder() 
    { 
        inorderTraversal(this.rootNode); 
    } 
    
    // A utility function to do inorder traversal of BST 
    void inorderTraversal(Node rootNode) 
    { 
        if (rootNode != null) 
        { 
            inorderTraversal(rootNode.leftSideNode); 
            System.out.print(rootNode.data + " => "); 
            inorderTraversal(rootNode.rightSideNode); 
        } 
    }

    public static void main(String[] args) {
        // create a new binary search tree
        BST binary_search_tree = CreateBST();
        Scanner sc = new Scanner(System.in);
        int test;
        System.out.println("=========================================================");
        System.out.println("Enter 101 to stop taking inputs else inserting into the BST");
        do {
            System.out.println("Enter data to be inserted into the BST");
            test = sc.nextInt();
            if (test != 101) {
                binary_search_tree.insertIntoBST(test);
            }
        } while (test != 101);
        
        System.out.println("The BST uptil now is");
        binary_search_tree.inorder();
        System.out.println("=========================================================");
        System.out.println("Enter 101 to stop taking inputs else searching values from the BST");
        do {
            System.out.println("Enter data to be searched for in the BST");
            test = sc.nextInt();
            if (test != 101) {
                System.out.println(test + " is there in the BST? => "+ binary_search_tree.searchNodeBST(test));
            }
        } while (test != 101);
        
        System.out.println("The BST uptil now is");
        binary_search_tree.inorder();
        System.out.println("=========================================================");
        System.out.println("Enter 101 to stop taking inputs else deleting values from the BST");
        do {
            System.out.println("Enter data to be deleted from the BST");
            test = sc.nextInt();
            if (test != 101) {
                binary_search_tree.deleteFromBST(test);
            }
        } while (test != 101);
        sc.close();
        System.out.println("The BST uptil now is");
        binary_search_tree.inorder();

    }

}