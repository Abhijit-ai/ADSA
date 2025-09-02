#include <stdio.h>

// Binary Search with comparison count
int binarySearch(int arr[], int l, int r, int x, int *count) {
    while (l <= r) {
        (*count)++; // comparison with while condition
        int mid = l + (r - l) / 2;

        (*count)++; // comparison arr[mid] == x
        if (arr[mid] == x) return mid;

        (*count)++; // comparison arr[mid] < x
        if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// Ternary Search with comparison count
int ternarySearch(int arr[], int l, int r, int key, int *count) {
    while (l <= r) {
        (*count)++;
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        (*count)++;
        if (arr[mid1] == key) return mid1;

        (*count)++;
        if (arr[mid2] == key) return mid2;

        (*count)++;
        if (key < arr[mid1]) r = mid1 - 1;
        else if (key > arr[mid2]) {
            (*count)++;
            l = mid2 + 1;
        } else {
            (*count)++;
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
    return -1;
}

// Main
int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int bCount = 0, tCount = 0;
    int res1 = binarySearch(arr, 0, n - 1, key, &bCount);
    int res2 = ternarySearch(arr, 0, n - 1, key, &tCount);

    if (res1 != -1) printf("Binary Search: Found at index %d\n", res1);
    else printf("Binary Search: Not Found\n");
    printf("Binary Search Comparisons: %d\n", bCount);

    if (res2 != -1) printf("Ternary Search: Found at index %d\n", res2);
    else printf("Ternary Search: Not Found\n");
    printf("Ternary Search Comparisons: %d\n", tCount);

    return 0;
}
