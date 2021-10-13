package com.jacob.wakatimeapp.login

import java.util.*

class BST private constructor() {
    class Node(
        var data: Int,
        var leftSideNode: Node? = null,
        var rightSideNode: Node? = null,
    )

    // Every tree has a root node
    private var rootNode: Node? = null

    // Updates the root of the BST after insertion
    fun insertIntoBST(newInsertion: Int) {
        rootNode = insertNewNodes(rootNode, newInsertion)
    }

    // Actual node insertion occurs here
    private fun insertNewNodes(rootNode: Node?, data: Int): Node {
        // BST is empty, then this data will form the root
        var newRootNode = rootNode
        if (newRootNode == null) {
            newRootNode = Node(data)
            return newRootNode
        }

        // newly added data is lesser than the root node, we recurse the process
        // considering left child as root
        if (data < newRootNode.data) {
            newRootNode.leftSideNode = insertNewNodes(newRootNode.leftSideNode, data)
        } else if (data > newRootNode.data) {
            newRootNode.rightSideNode = insertNewNodes(newRootNode.rightSideNode, data)
        }

        // return the root node pointer
        return newRootNode
    }

    // search data record
    fun searchNodeBST(data: Int): Boolean {
        if (rootNode == null) return false

        // start comparing from the root value data
        var traversalNode = rootNode
        while (traversalNode != null) {
            // return true if we find out the node
            traversalNode = when {
                data == traversalNode.data -> return true
                data > traversalNode.data -> traversalNode.rightSideNode
                else -> traversalNode.leftSideNode
            }
        }
        // if we do not find it still, it is not there in the BST
        return false
    }

    // Updates the root of the BST after deletion
    fun deleteFromBST(data: Int) {
        rootNode = deleteValueFromBST(rootNode, data)
    }

    private fun deleteValueFromBST(rootNode: Node?, data: Int): Node? {
        if (rootNode == null) return rootNode

        // Else recurring down the tree
        // handle the case if the tree has only one side of subtree
        return when {
            rootNode.leftSideNode == null -> rootNode.rightSideNode
            rootNode.rightSideNode == null -> rootNode.leftSideNode
            else -> {
                // for nodes with two children, calculating inorder successor (smallest node in
                // right sub-tree)
                rootNode.data = minValue(rootNode.rightSideNode)

                // Delete the inorder successor
                rootNode.rightSideNode = deleteValueFromBST(rootNode.rightSideNode, data)
                rootNode
            }
        }
    }

    private fun minValue(rootNode: Node?): Int {
        // initialize the data to root's data
        var newRootNode = rootNode
        var minimumValue = newRootNode!!.data

        // keep on traversing left till null, and update lowest find
        while (newRootNode?.leftSideNode != null) {
            minimumValue = newRootNode.leftSideNode!!.data
            newRootNode = newRootNode.leftSideNode
        }
        return minimumValue
    }

    fun inorder() = inorderTraversal(rootNode)

    // A utility function to do inorder traversal of BST
    private fun inorderTraversal(rootNode: Node?) {
        if (rootNode != null) {
            inorderTraversal(rootNode.leftSideNode)
            print(rootNode.data.toString() + " => ")
            inorderTraversal(rootNode.rightSideNode)
        }
    }

    fun preorder() = preorderTraversal(rootNode)

    private fun preorderTraversal(rootNode: Node?) {
        if (rootNode != null) {
            print(rootNode.data.toString() + " => ")
            preorderTraversal(rootNode.leftSideNode)
            preorderTraversal(rootNode.rightSideNode)
        }
    }

    fun postorder() = postorderTraversal(rootNode)

    private fun postorderTraversal(rootNode: Node?) {
        if (rootNode != null) {
            postorderTraversal(rootNode.leftSideNode)
            postorderTraversal(rootNode.rightSideNode)
            print(rootNode.data.toString() + " => ")
        }
    }

    companion object {
        fun createBST(): BST = BST()
    }
}

fun main() {
    // create a new binary search tree
    val binarySearchTree = BST.createBST()
    val sc = Scanner(System.`in`)
    var test: Int
    val message = "========================================================="
    println(message)
    println("Enter 101 to stop taking inputs else inserting into the BST")
    do {
        println("Enter data to be inserted into the BST")
        test = sc.nextInt()
        if (test != 101) {
            binarySearchTree.insertIntoBST(test)
        }
    } while (test != 101)
    println("The BST up-til now is")
    binarySearchTree.inorder()
    println(message)
    println("Enter 101 to stop taking inputs else searching values from the BST")
    do {
        println("Enter data to be searched for in the BST")
        test = sc.nextInt()
        if (test != 101) {
            println("$test is there in the BST? => ${binarySearchTree.searchNodeBST(test)}")
        }
    } while (test != 101)
    println("The BST up-til now is")
    binarySearchTree.inorder()
    println(message)
    println("Enter 101 to stop taking inputs else deleting values from the BST")
    do {
        println("Enter data to be deleted from the BST")
        test = sc.nextInt()
        if (test != 101) {
            binarySearchTree.deleteFromBST(test)
        }
    } while (test != 101)
    sc.close()
    println("The BST up-til now is:")
    println(" -in Inorder Traversal:")
    binarySearchTree.inorder()
    println(" -in Preorder Traversal:")
    binarySearchTree.preorder()
    println(" -in Postorder Traversal:")
    binarySearchTree.postorder()
}
