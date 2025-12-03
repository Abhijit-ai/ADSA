## Merge Sort

### Problem Statement

This program implements the Merge Sort algorithm to sort an array of integers in ascending order. Merge Sort is an efficient, comparison-based sorting algorithm that uses a divide-and-conquer approach.

### Related Algorithm: Merge Sort

Merge Sort is a highly efficient, general-purpose, comparison-based sorting algorithm. It is a stable sort, meaning that the relative order of equal sort items is preserved. It has a time complexity of O(n log n) in all three cases: best, average, and worst.

The algorithm follows the divide-and-conquer paradigm and consists of two main parts:

1.  **Divide**: The unsorted list is recursively divided into `N` sublists, each containing one element (a list of one element is considered sorted). This division continues until there are `N` sub-lists, each containing one element.
2.  **Conquer (Merge)**: The sub-lists are repeatedly merged to produce new sorted sub-lists. The merging process compares elements from two sorted sub-lists and places them into a new sorted sub-list in the correct order. This continues until there is only one sorted list remaining.

The core idea is to break down a big problem (sorting a large array) into smaller, more manageable sub-problems (sorting smaller sub-arrays) and then combine the solutions to the sub-problems to solve the original big problem.

### Code Details

The `q3.c` file implements Merge Sort using two key functions:

*   **`merge(int arr[], int left, int mid, int right)`**: This function is responsible for merging two sorted sub-arrays back into a single sorted array.
    *   It takes the main `arr`, the `left` boundary of the first sub-array, the `mid` point (end of the first, start of the second), and the `right` boundary of the second sub-array.
    *   It creates temporary arrays `L` and `R` to hold the elements of the two sub-arrays.
    *   It then iterates through `L` and `R`, comparing elements and placing the smaller one into the correct position in the main `arr`.
    *   Finally, it copies any remaining elements from `L` or `R` (if one sub-array finishes before the other) back into `arr`.
*   **`mergeSort(int arr[], int left, int right)`**: This is the recursive function that implements the divide-and-conquer strategy.
    *   It takes the main `arr` and the `left` and `right` boundaries of the current portion of the array to be sorted.
    *   The base case for the recursion is `if (left < right)`. If `left >= right`, it means the sub-array has one or zero elements and is considered sorted.
    *   It calculates the `mid` point of the current sub-array.
    *   It then recursively calls `mergeSort` on the left half (`arr`, `left`, `mid`) and the right half (`arr`, `mid + 1`, `right`).
    *   After the two halves are sorted by the recursive calls, it calls the `merge` function to combine them into a single sorted sub-array.

The `main` function:
1.  Initializes a hardcoded integer array `arr = {38, 27, 43, 3, 9, 82, 10}`.
2.  Determines the size `n` of the array.
3.  Prints the "Original array".
4.  Calls `mergeSort` with the array and its boundaries (`0` to `n - 1`) to sort it.
5.  Prints the "Sorted array".

### Sample Input/Output

**Input:**

The array is hardcoded within the `main` function:
`int arr[] = {38, 27, 43, 3, 9, 82, 10};`

**Output:**

```
Original array:
38 27 43 3 9 82 10

Sorted array:
3 9 10 27 38 43 82
```