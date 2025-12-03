## Quick Sort with Median-of-Three Pivot

### Problem Statement

This program implements the Quick Sort algorithm, specifically utilizing the "median-of-three" strategy for pivot selection, to sort an array of integers in ascending order. This pivot selection method aims to improve the algorithm's average-case performance and mitigate the risk of worst-case scenarios compared to simply picking the first or last element as the pivot.

### Related Algorithm: Quick Sort with Median-of-Three Pivot

Quick Sort is a highly efficient, comparison-based sorting algorithm based on the divide-and-conquer paradigm. Its performance heavily relies on the choice of the pivot element during the partitioning step. A poor pivot choice (e.g., always picking the smallest or largest element) can lead to highly unbalanced partitions and degrade the algorithm's time complexity from its average `O(n log n)` to its worst-case `O(n^2)`.

The **median-of-three pivot strategy** is a common technique to make pivot selection more robust. Instead of simply picking a fixed element (like the first or last), it involves:

1.  **Selecting Three Candidates**: Typically, the elements at the `low` index (first), `high` index (last), and `mid` index of the current sub-array are chosen as candidates.
2.  **Finding the Median**: These three candidate elements are sorted, and their median value is identified.
3.  **Positioning the Pivot**: The identified median value is then placed in a strategic position (e.g., swapped with `arr[high-1]` or `arr[high]`) to be used as the pivot for the partitioning process. This ensures that the pivot is not an extreme value among these three, leading to more balanced partitions on average.

By employing the median-of-three strategy, the likelihood of encountering the `O(n^2)` worst-case is significantly reduced, and the average-case performance is often slightly enhanced, especially on data that might otherwise cause Quick Sort to perform poorly (e.g., nearly sorted or reverse sorted arrays).

### Code Details

The `q5.c` file implements Quick Sort with the median-of-three pivot using the following functions:

*   **`swap(int *a, int *b)`**: A utility function to exchange the values of two integer pointers.
*   **`medianOfThree(int arr[], int low, int high)`**: This function selects and positions the median pivot.
    *   It takes the `arr` and the `low` and `high` indices.
    *   It calculates the `mid` index.
    *   It then performs a series of comparisons and `swap` operations to sort `arr[low]`, `arr[mid]`, and `arr[high]` in place, ensuring that `arr[mid]` holds the median of these three.
    *   It then swaps `arr[mid]` (the median) with `arr[high - 1]`. This moves the chosen pivot to a known location just before the very last element, making it easier to handle in the `partition` function.
    *   It returns the value of this chosen pivot (`arr[high - 1]`).
*   **`partition(int arr[], int low, int high)`**: This function performs the partitioning step around the pivot determined by `medianOfThree`.
    *   It takes the `arr` and the `low` and `high` indices.
    *   It calls `medianOfThree` to get the pivot and ensure it's positioned correctly (at `arr[high - 1]`).
    *   It uses two pointers, `i` starting from `low` and `j` starting from `high - 1` (since the actual pivot is now at `high-1`, the effective high for scanning is `high - 1`).
    *   It scans from the left (`i`) to find an element greater than or equal to the pivot, and from the right (`j`) to find an element less than or equal to the pivot.
    *   If `i < j`, it swaps `arr[i]` and `arr[j]`.
    *   When `i >= j`, the loops terminate, and `arr[i]` is swapped with the pivot (which was at `arr[high - 1]`), placing the pivot in its final sorted position, and returning its index `i`.
*   **`quickSort(int arr[], int low, int high)`**: This is the main recursive Quick Sort function.
    *   It takes the array `arr`, and the `low` and `high` indices of the sub-array to be sorted.
    *   The base case for the recursion is `if (low < high)`.
    *   It calls `partition` to get the pivot's index (`pi`).
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