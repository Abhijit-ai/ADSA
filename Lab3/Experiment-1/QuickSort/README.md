## Quick Sort

### Problem Statement

This program implements the Quick Sort algorithm to sort an array of integers in ascending order. Quick Sort is a highly efficient, comparison-based sorting algorithm that uses a divide-and-conquer strategy, making it one of the fastest general-purpose sorting algorithms for large datasets.

### Related Algorithm: Quick Sort

Quick Sort is a prominent sorting algorithm that employs the "divide and conquer" paradigm. It's known for its speed in practical applications, often outperforming other `O(n log n)` algorithms like Merge Sort and Heap Sort on average.

The algorithm generally involves these steps:

1.  **Choose a Pivot**: A pivot element is selected from the array. The choice of pivot significantly impacts the algorithm's performance. Common strategies include picking the first, last, middle, or a random element. In this implementation, the last element is chosen as the pivot.
2.  **Partitioning**: The array is rearranged (partitioned) such that all elements smaller than the pivot are placed before it, and all elements larger than the pivot are placed after it. Elements equal to the pivot can go on either side. After partitioning, the pivot element is in its final sorted position.
3.  **Recursion**: The Quick Sort algorithm is then recursively applied to the sub-arrays on both sides of the pivot. This process continues until each sub-array contains zero or one element, which are inherently sorted.

**Time Complexity:**
*   **Best and Average Case:** `O(n log n)`
*   **Worst Case:** `O(n^2)` (occurs with poor pivot selection, e.g., always picking the smallest or largest element in an already sorted array).

**Space Complexity:** `O(log n)` on average due to the recursion stack. It can be implemented in-place, requiring minimal auxiliary space.

### Code Details

The `q4.c` file implements Quick Sort using the following functions:

*   **`swap(int *a, int *b)`**: A utility function to exchange the values of two integer pointers.
*   **`partition(int arr[], int low, int high)`**: This function performs the partitioning step.
    *   It takes the array `arr`, and the `low` and `high` indices of the sub-array to be partitioned.
    *   It selects the element at `arr[high]` as the `pivot`.
    *   It iterates through the sub-array, placing elements smaller than or equal to the pivot to the left of `i+1` (where `i` tracks the boundary of smaller elements).
    *   Finally, it swaps the pivot with the element at `arr[i + 1]`, placing the pivot in its correct sorted position, and returns the pivot's index.
*   **`quickSort(int arr[], int low, int high)`**: This is the main recursive Quick Sort function.
    *   It takes the array `arr`, and the `low` and `high` indices of the sub-array to be sorted.
    *   The base case for the recursion is `if (low < high)`. If `low >= high`, the sub-array has one or zero elements and is sorted.
    *   It calls `partition` to get the pivot's correct position (`pi`).
    *   It then recursively calls `quickSort` for the sub-array to the left of the pivot (`arr`, `low`, `pi - 1`) and the sub-array to the right of the pivot (`arr`, `pi + 1`, `high`).

The `main` function:
1.  Initializes a hardcoded integer array `arr = {34, 7, 23, 32, 5, 62, 19, 3}`.
2.  Determines the size `n` of the array.
3.  Prints the "Original array".
4.  Calls `quickSort` with the array and its boundaries (`0` to `n - 1`) to sort it.
5.  Prints the "Sorted array".

### Sample Input/Output

**Input:**

The array is hardcoded within the `main` function:
`int arr[] = {34, 7, 23, 32, 5, 62, 19, 3};`

**Output:**

```
Original array:
34 7 23 32 5 62 19 3

Sorted array:
3 5 7 19 23 32 34 62
```