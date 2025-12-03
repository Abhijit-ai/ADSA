## Binary Search Tree (BST) Operations

### Problem Statement

This program demonstrates fundamental operations on a Binary Search Tree (BST), including insertion, deletion, and various tree traversals (inorder, preorder, and postorder). The goal is to illustrate how a BST efficiently stores and manages data based on its hierarchical, sorted structure.

### Related Algorithm: Binary Search Tree (BST)

A Binary Search Tree (BST) is a node-based binary tree data structure where each node has at most two children. It maintains a specific ordering property:

*   For any given node, all values in its **left subtree** are smaller than the node's own value.
*   All values in its **right subtree** are greater than the node's own value.

This property enables efficient searching, insertion, and deletion operations, with an average time complexity of O(log n), where 'n' is the number of nodes. However, in the worst-case scenario (e.g., if elements are inserted in strictly ascending or descending order), the tree can become skewed, resembling a linked list, and the time complexity can degrade to O(n).

#### Core Operations:

1.  **Insertion**:
    *   To insert a new node, start at the root and traverse the tree.
    *   If the new value is less than the current node's value, go left; otherwise, go right.
    *   Continue until an empty spot (NULL child pointer) is found, and then insert the new node there.

2.  **Deletion**: This is the most complex operation, with three main cases:
    *   **Node is a Leaf (no children)**: Simply remove the node.
    *   **Node has One Child**: Replace the node with its child.
    *   **Node has Two Children**: Find the node's in-order successor (the smallest node in its right subtree) or in-order predecessor (the largest node in its left subtree). Copy the successor's (or predecessor's) value to the node to be deleted, and then recursively delete the successor (or predecessor) from its original position (which will now fall into one of the first two cases).

3.  **Traversal**: Ways to visit all nodes in the tree:
    *   **Inorder Traversal**: Visits nodes in ascending order (Left -> Root -> Right).
    *   **Preorder Traversal**: Visits the root first, then its left subtree, then its right subtree (Root -> Left -> Right). Useful for creating a copy of the tree.
    *   **Postorder Traversal**: Visits the left subtree, then the right subtree, then the root (Left -> Right -> Root). Useful for deleting the tree.

### Code Details

The `q7.c` file implements a basic Binary Search Tree with the following functionalities:

*   **`struct Node`**: Defines the structure of a BST node, containing an integer `key` and pointers to its `left` and `right` children.
*   **`newNode(int key)`**: A utility function to create a new BST node and initialize its fields.
*   **`insert(struct Node* root, int key)`**: Recursively inserts a new node with the given `key` into the BST, maintaining the BST property.
*   **`minValueNode(struct Node* node)`**: A helper function for deletion. It finds the node with the minimum value in a given subtree (which is the leftmost node in that subtree).
*   **`deleteNode(struct Node* root, int key)`**: Recursively deletes the node with the specified `key` from the BST. It handles all three deletion cases by finding the in-order successor for nodes with two children.
*   **`inorder(struct Node* root)`**: Performs an in-order traversal of the BST and prints the node keys.
*   **`preorder(struct Node* root)`**: Performs a pre-order traversal of the BST and prints the node keys.
*   **`postorder(struct Node* root)`**: Performs a post-order traversal of the BST and prints the node keys.

The `main` function:
1.  Initializes an empty BST (`root = NULL`).
2.  Performs a series of hardcoded `insert` operations to build an initial tree.
3.  Prints the tree using inorder, preorder, and postorder traversals.
4.  Demonstrates `deleteNode` operations for specific keys (e.g., `20`, `50`).
5.  Prints the inorder traversal after each deletion to show the tree's updated state.
6.  Finally, prints all three traversals of the modified tree.

### Sample Input/Output

**Input:**

The tree operations (insertions and deletions) are hardcoded within the `main` function.

**Output:**

```
Creating Binary Search Tree...Inserting nodes one by one

Inorder Traversal: 20 30 40 50 60 70 80
Preorder Traversal: 50 30 20 40 70 60 80
Postorder Traversal: 20 40 30 60 80 70 50

Deleting 20...
Inorder after deleting 20: 30 40 50 60 70 80

Deleting 50...
Inorder after deleting 50: 30 40 60 70 80

Final Tree Traversals:
Inorder: 30 40 60 70 80
Preorder: 60 30 40 70 80
Postorder: 40 30 80 70 60
```