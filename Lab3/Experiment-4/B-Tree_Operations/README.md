## B-Tree Operations

### Problem Statement

This program demonstrates fundamental operations, primarily insertion and display (traversal), on a B-Tree data structure. A B-Tree is a self-balancing tree that maintains sorted data and allows efficient searches, insertions, and deletions in logarithmic time. It is particularly optimized for systems that store and retrieve large blocks of data, such as databases and file systems, by minimizing disk I/O operations.

### Related Algorithm: B-Tree

A B-Tree is a self-balancing tree data structure designed for efficient storage and retrieval of data on disk. Unlike binary trees, B-Trees can have many children per node, and all leaf nodes are at the same depth. This structure minimizes the height of the tree, which is crucial for reducing the number of disk accesses when searching for data.

Key characteristics of a B-Tree of order `m` (or minimum degree `t`):

*   **Node Structure**: Each node contains a sorted list of keys and pointers to its children.
*   **Minimum Degree `t`**: Every node (except the root) must have at least `t-1` keys and `t` children. The root must have at least one key (and two children) if it's not a leaf.
*   **Maximum Keys**: Each node can contain at most `2t-1` keys and `2t` children.
*   **Leaf Nodes**: All leaf nodes are at the same level.

#### Insertion

Inserting a new key into a B-Tree involves these steps:

1.  **Search for Leaf**: Traverse the tree from the root to find the appropriate leaf node where the new key should be inserted, maintaining sorted order within the node.
2.  **Insert into Leaf**: If the leaf node has space (fewer than `2t-1` keys), simply insert the new key into the sorted position.
3.  **Handle Overflow (Splitting)**: If the leaf node is full (`2t-1` keys), it must be split:
    *   The node is divided into two nodes, and the median key is promoted to the parent node.
    *   The keys smaller than the median stay in the original node, and keys larger than the median go into a new sibling node.
    *   If the parent also becomes full, this splitting process propagates upwards recursively until a parent with space is found or a new root is created, increasing the tree's height.

#### Deletion

Deletion is more complex, as it must ensure that the minimum number of keys (`t-1`) is maintained in each node (except the root). If a node underflows, keys might need to be borrowed from a sibling or merged with a sibling. The provided code includes a simple deletion function that doesn't handle rebalancing, which is critical for a functional B-Tree.

### Code Details

The `q10.c` file implements a B-Tree with `MAX` defined as 3, meaning a node can hold up to `MAX` (3) keys and `MAX+1` (4) children. This corresponds to a B-tree where each node (except the root) has a minimum of 1 key (`MIN = 1`) and a maximum of 3 keys.

*   **`struct BTreeNode`**: Defines the structure of a B-Tree node, containing an array `val` for keys, an array `link` for child pointers, and an integer `count` for the number of keys currently in the node.
*   **`root`**: A global pointer to the root of the B-Tree.
*   **`createNode(int val, struct BTreeNode *child)`**: Creates a new B-Tree node, typically used when the root splits.
*   **`addValToNode(int val, int pos, struct BTreeNode *node, struct BTreeNode *child)`**: Inserts a value and its corresponding child pointer into a node at a specified position, shifting existing elements.
*   **`splitNode(int val, int *pval, int pos, struct BTreeNode *node, struct BTreeNode *child, struct BTreeNode **newNode)`**: Handles the splitting of a full node. It determines the median, creates a `newNode`, distributes values, and sets the value (`pval`) to be promoted to the parent.
*   **`setValue(int val, int *pval, struct BTreeNode *node, struct BTreeNode **child)`**: A recursive helper function for insertion. It traverses the tree to find the correct insertion point. If a node is full, it triggers `splitNode`. It also handles duplicate values.
*   **`insert(int val)`**: The main insertion function. It calls `setValue` to insert the value into the tree. If `setValue` indicates that the root has split, it creates a new root node.
*   **`display(struct BTreeNode *node)`**: Performs an in-order like traversal to display the keys of the B-Tree.
*   **`deleteDemo(struct BTreeNode *node, int key)`**: A very basic deletion function. It removes the key if found but explicitly states "no rebalance". **This function is incomplete for a fully functional B-Tree as it does not handle underflow and rebalancing (borrowing or merging) which are critical parts of B-Tree deletion.**

The `main` function:
1.  Initializes an array of integer `values` to be inserted.
2.  Calls `insert` for each value in the array to build the B-Tree.
3.  Calls `display` to print the B-Tree after insertions.
4.  Calls `deleteDemo` to attempt to delete a key (e.g., `6`).
5.  Calls `display` again to show the tree after the simple deletion.

### Sample Input/Output

**Input:**

The values for insertion are hardcoded within the `main` function:
`int values[] = {10, 20, 5, 6, 12, 30, 7, 17};`
A value `6` is hardcoded for deletion.

**Output:**

```
Inserting values into B-Tree:
B-Tree after insertion:
5 6 7 10 12 17 20 30
Deleted 6 (simple demo, no rebalance)

B-Tree after deleting 6:
5 7 10 12 17 20 30
```
*(Note: The display function shows the keys in sorted order, demonstrating the B-Tree's ordered storage. The deletion simply removes the key without rebalancing, which is not how a robust B-Tree deletion would operate.)*