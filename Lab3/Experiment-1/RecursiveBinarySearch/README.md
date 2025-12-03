## Recursive Binary Search

### Problem Statement

This program implements the recursive version of the Binary Search algorithm to find a specific key within a sorted array of integers. It demonstrates how to locate an element efficiently by repeatedly halving the search interval through recursive function calls.

### Related Algorithm: Binary Search

Binary Search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing in half the portion of the list that could contain the item, until you've narrowed down the possible locations to just one.

**How it works (Recursive Approach):**

1.  **Base Case**: The recursion stops when the `low` index becomes greater than the `high` index. This indicates that the search interval is empty, and the `key` is not found, so `-1` is returned.
2.  **Find Midpoint**: In each recursive call, calculate the middle index `mid` of the current search interval: `mid = low + (high - low) / 2`.
3.  **Comparison**:
    *   If the element at `arr[mid]` is equal to the `key`, the element is found, and its index `mid` is returned. This is another base case for successful termination.
    *   If the element at `arr[mid]` is less than the `key`, it means the key (if present) must be in the right half of the current sub-array. The function then recursively calls itself with the new search interval (`mid + 1` to `high`).
    *   If the element at `arr[mid]` is greater than the `key`, it means the key (if present) must be in the left half of the current sub-array. The function then recursively calls itself with the new search interval (`low` to `mid - 1`).

The time complexity of Binary Search is O(log n), making it very efficient for searching in large sorted arrays. Its space complexity is O(log n) for the recursive version due to the function call stack.

### Code Details

The `q6.c` file implements the recursive binary search using the `binarySearchRecursive` function:

*   **`binarySearchRecursive(int arr[], int low, int high, int key)`**:
    *   Takes the sorted array `arr`, the current `low` and `high` boundaries of the search space, and the `key` to search for.
    *   It first checks the base case `low > high` to determine if the key is not found.
    *   It calculates the `mid` index.
    *   It compares `arr[mid]` with `key`. If they match, `mid` is returned.
    *   Otherwise, it makes a recursive call to search either the left or right sub-array based on the comparison.

The `main` function:
1.  Initializes a hardcoded sorted integer array `arr = {3, 6, 9, 15, 20, 36, 42, 57, 73, 88}`.
2.  Determines the size `n` of the array.
3.  Sets a hardcoded `key = 15` to be searched.
4.  Prints the array and the key being searched for.
5.  Calls `binarySearchRecursive` with the array, initial boundaries (`0` and `n - 1`), and the `key`.
6.  Prints whether the key was found and, if so, its index.

### Sample Input/Output

**Input:**

The array and key are hardcoded within the `main` function:
`int arr[] = {3, 6, 9, 15, 20, 36, 42, 57, 73, 88};`
`int key = 15;`

**Output:**

```
Array: 3 6 9 15 20 36 42 57 73 88
Searching for key = 15
Key 15 found at index 3.
```