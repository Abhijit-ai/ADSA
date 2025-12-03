## AVL Tree Operations

### Problem Statement

This program implements fundamental operations (insertion and deletion) on an AVL (Adelson-Velsky and Landis) Tree. An AVL tree is a self-balancing binary search tree, meaning it automatically adjusts its structure after insertions or deletions to maintain a balanced state. This ensures that all operations (search, insert, delete) have a time complexity of O(log n), preventing performance degradation seen in skewed binary search trees.

### Related Algorithm: AVL Tree

An AVL Tree is a self-balancing Binary Search Tree (BST). Its self-balancing property ensures that the height difference between the left and right subtrees of any node is at most 1. This height balance is maintained by performing rotations whenever an insertion or deletion causes an imbalance.

#### Balance Factor

The balance factor of a node is calculated as:
**`Balance Factor = Height(Left Subtree) - Height(Right Subtree)`**

For an AVL tree to be balanced, the balance factor of every node must be -1, 0, or 1.
*   **0**: Perfectly balanced (left and right subtrees have equal height).
*   **1**: Left-heavy (left subtree is one level taller).
*   **-1**: Right-heavy (right subtree is one level taller).

If the balance factor becomes > 1 (left-left or left-right imbalance) or < -1 (right-right or right-left imbalance), rotations are performed.

#### Rotations

Rotations are local structural changes to the tree that restore balance while preserving the BST property. There are four types of rotations:

1.  **Left Rotation (LL Case)**: Occurs when a node is unbalanced and the new node is inserted into the left subtree of the left child. This is a single rotation.
2.  **Right Rotation (RR Case)**: Occurs when a node is unbalanced and the new node is inserted into the right subtree of the right child. This is a single rotation.
3.  **Left-Right Rotation (LR Case)**: Occurs when a node is unbalanced and the new node is inserted into the right subtree of the left child. This is a double rotation (a left rotation on the child, then a right rotation on the parent).
4.  **Right-Left Rotation (RL Case)**: Occurs when a node is unbalanced and the new node is inserted into the left subtree of the right child. This is a double rotation (a right rotation on the child, then a left rotation on the parent).

#### Core Operations:

*   **Insertion**: A new node is inserted as in a regular BST. Then, the path from the inserted node up to the root is checked. For each node on this path, its height and balance factor are updated. If an imbalance is detected (balance factor > 1 or < -1), the appropriate rotation(s) are performed to restore balance.
*   **Deletion**: A node is deleted as in a regular BST. Similar to insertion, after deletion, the heights and balance factors of affected nodes on the path to the root are updated. If an imbalance occurs, rotations are performed to rebalance the tree.

All operations in an AVL tree (search, insertion, and deletion) guarantee a time complexity of O(log n) because the tree's height remains logarithmically proportional to the number of nodes.

### Code Details

The `q9.c` file implements AVL tree operations with the following functions:

*   **`struct Node`**: Defines the structure for an AVL tree node, including `key`, pointers to `left` and `right` children, and `height`.
*   **`height(struct Node *N)`**: Returns the height of a given node (0 if NULL).
*   **`max(int a, int b)`**: A utility function to find the maximum of two integers.
*   **`newNode(int key)`**: Creates and initializes a new AVL tree node.
*   **`rightRotate(struct Node* y)`**: Performs a right rotation around node `y`.
*   **`leftRotate(struct Node* x)`**: Performs a left rotation around node `x`.
*   **`getBalance(struct Node* N)`**: Calculates the balance factor of node `N`.
*   **`insert(struct Node* node, int key)`**: Inserts a new `key` into the AVL tree. After standard BST insertion, it updates heights, calculates the balance factor, and performs necessary rotations (LL, RR, LR, RL cases) to rebalance the tree.
*   **`minValueNode(struct Node* node)`**: A helper function for deletion, finding the node with the minimum value in a given subtree.
*   **`deleteNode(struct Node* root, int key)`**: Deletes a `key` from the AVL tree. It follows BST deletion logic for 0, 1, or 2 children, and then, similar to insertion, it rebalances the tree using rotations if an imbalance occurs.
*   **`inorder(struct Node* root)`**: Performs an in-order traversal of the AVL tree and prints the keys (which will be in sorted order).

The `main` function:
1.  Initializes an empty AVL tree (`root = NULL`).
2.  Performs a series of hardcoded `insert` operations (`10, 20, 30, 40, 50, 25`) to build the AVL tree. The order of insertion is specifically chosen to demonstrate the self-balancing properties and rotations.
3.  Prints the in-order traversal of the tree after insertions.
4.  Demonstrates a `deleteNode` operation (e.g., deleting `40`).
5.  Prints the in-order traversal after deletion to show the tree's updated and balanced state.

### Sample Input/Output

**Input:**

The tree operations (insertions and deletions) are hardcoded within the `main` function.

**Output:**

```
Inserting nodes...
Inorder traversal of the AVL tree:
10 20 25 30 40 50
After deleting 40:
10 20 25 30 50
```
*(The output shows the keys in sorted order after insertions and after deleting a node, confirming the BST property is maintained and the tree remains balanced internally.)*