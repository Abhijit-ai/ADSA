## Iterative Binary Search

### Problem Statement

This program implements the iterative version of the Binary Search algorithm to find a specific key within a sorted array of integers. It demonstrates how to locate an element efficiently by repeatedly halving the search interval using a loop.

### Related Algorithm: Binary Search

Binary Search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing in half the portion of the list that could contain the item, until you've narrowed down the possible locations to just one.

**How it works (Iterative Approach):**

1.  **Initialization**: Start with `low` pointing to the first element's index and `high` pointing to the last element's index of the sorted array.
2.  **Loop Condition**: Continue the search process as long as `low` is less than or equal to `high`.
3.  **Find Midpoint**: Calculate the middle index `mid` of the current search interval: `mid = low + (high - low) / 2`. This calculation prevents potential integer overflow that `(low + high) / 2` might cause with very large `low` and `high` values.
4.  **Comparison**:
    *   If the element at `arr[mid]` is equal to the `key`, the element is found, and its index `mid` is returned.
    *   If the element at `arr[mid]` is less than the `key`, it means the key (if present) must be in the right half of the array. Adjust `low` to `mid + 1`.
    *   If the element at `arr[mid]` is greater than the `key`, it means the key (if present) must be in the left half of the array. Adjust `high` to `mid - 1`.
5.  **Not Found**: If the loop finishes and the key has not been found (i.e., `low` becomes greater than `high`), it means the key is not present in the array, and -1 is returned.

The time complexity of Binary Search is O(log n), making it very efficient for searching in large sorted arrays. Its space complexity is O(1) for the iterative version.

### Code Details

The `q2.c` file implements the iterative binary search using the `binarySearchIterative` function:

*   **`binarySearchIterative(int arr[], int n, int key)`**:
    *   Takes the sorted array `arr`, its size `n`, and the `key` to search for.
    *   Uses a `while` loop to perform the search.
    *   Inside the loop, it calculates the `mid` index and compares `arr[mid]` with `key`.
    *   Updates `low` or `high` pointers based on the comparison to narrow down the search space.
    *   Returns the index if the `key` is found, otherwise returns `-1`.

The `main` function:
1.  Initializes a hardcoded sorted integer array `arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}`.
2.  Determines the size `n` of the array.
3.  Sets a hardcoded `key = 23` to be searched.
4.  Prints the array and the key being searched for.
5.  Calls `binarySearchIterative` to find the key.
6.  Prints whether the key was found and, if so, its index.

### Sample Input/Output

**Input:**

The array and key are hardcoded within the `main` function:
`int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};`
`int key = 23;`

**Output:**

```
Array: 2 5 8 12 16 23 38 56 72 91
Searching for key = 23
Key 23 found at index 5.
```