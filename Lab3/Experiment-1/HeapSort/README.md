## Heap Sort

### Problem Statement

This program implements the Heap Sort algorithm to sort a hardcoded array of integers in ascending order. Heap Sort is a comparison-based sorting technique that leverages the binary heap data structure to efficiently arrange elements.

### Related Algorithm: Heap Sort

Heap Sort is an efficient, in-place sorting algorithm with a time complexity of O(n log n) in all cases (best, average, and worst). It works in two primary phases:

1.  **Heapify (Build Max-Heap)**:
    *   The unsorted input array is transformed into a binary max-heap. In a max-heap, the value of each parent node is always greater than or equal to the values of its children. This property ensures that the largest element is at the root of the heap.
    *   This phase starts from the last non-leaf node and recursively calls a `heapify` procedure upwards to the root, ensuring the max-heap property is established for all subtrees.

2.  **Extract Elements (Sorting)**:
    *   Once the max-heap is built, the largest element (which is at the root, index 0) is swapped with the last element of the array.
    *   The size of the heap is then effectively reduced by one, excluding the now-sorted largest element from further heap operations.
    *   The `heapify` procedure is then called on the new root (index 0) of the reduced heap to restore the max-heap property. This brings the next largest element to the root.
    *   These steps are repeated until the heap contains only one element, at which point the entire array is sorted in ascending order.

### Code Details

The `q1.c` file implements Heap Sort using the following functions:

*   **`swap(int *a, int *b)`**: A utility function to exchange the values of two integer pointers.
*   **`heapify(int arr[], int n, int i)`**: This function is crucial for maintaining the max-heap property.
    *   It takes an array `arr`, the current size of the heap `n`, and an index `i` (representing the root of the subtree to heapify).
    *   It finds the largest among the root, left child (`2*i + 1`), and right child (`2*i + 2`).
    *   If the largest element is not the current root `i`, it swaps the elements and recursively calls `heapify` on the affected subtree to ensure the max-heap property is maintained down the tree.
*   **`heapSort(int arr[], int n)`**: This is the main Heap Sort function.
    *   **Building the heap**: It iterates from the last non-leaf node (`n / 2 - 1`) up to the root (index 0), calling `heapify` for each node. This builds the initial max-heap from the unsorted array.
    *   **Extracting elements**: It then iterates from the last element of the array (`n - 1`) down to the second element (index 1). In each iteration:
        *   It swaps the current root (largest element) with the element at the current end of the heap (`arr[0]` with `arr[i]`).
        *   It then calls `heapify` on the reduced heap (size `i`) starting from the new root (index 0) to restore the max-heap property.

The `main` function:
1.  Initializes a hardcoded integer array `arr = {12, 11, 13, 5, 6, 7}`.
2.  Determines the size `n` of the array.
3.  Prints the original unsorted array.
4.  Calls `heapSort` to sort the array.
5.  Prints the sorted array in ascending order.

### Sample Input/Output

**Input:**

The input array is hardcoded within the `main` function:
`int arr[] = {12, 11, 13, 5, 6, 7};`

**Output:**

```
Original array:
12 11 13 5 6 7
Sorted array:
5 6 7 11 12 13
```