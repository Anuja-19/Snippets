class BST {
  constructor(val) {
    this.val = val;
    this.left = null;
    this.right = null;
  }

  inorder(node) {
    if (node == null) return;
    this.inorder(node.left);
    console.log(node.val);
    this.inorder(node.right);
  }

  postorder(node) {
    if (node == null) return;
    this.postorder(node.left);
    this.postorder(node.right);
    console.log(node.val);
  }

  preorder(node) {
    if (node == null) return;
    console.log(node.val);
    this.preorder(node.left);
    this.preorder(node.right);
  }

  insert(node, val) {
    if (node == null) return new BST(val);
    if (val < node.val) {
      node.left = this.insert(node.left, val);
    } else {
      node.right = this.insert(node.right, val);
    }
    return node;
  }
}

/*
Let us create following BST 
		  1 
	   /	 \ 
	   2	   5 
	 /  \     /  \ 
	3    4   6    7 
*/
root = new BST(1);
root.insert(root, 2);
root.insert(root, 5);
root.insert(root, 3);
root.insert(root, 4);
root.insert(root, 6);
root.insert(root, 7);

tmpRoot = root;
root.inorder(tmpRoot);
tmpRoot = root;
root.preorder(tmpRoot);
tmpRoot = root;
root.postorder(tmpRoot);
// The following sequence of inorder traversal: 1 2 3 4 5 6 7
