#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}
int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] > key) return binarySearchRecursive(arr, low, mid - 1, key);
        return binarySearchRecursive(arr, mid + 1, high, key);
    }
    return -1;
}
int main() {
    int arr[50], n, key, choice, pos;
    printf("Enter number of elements (in sorted order for Binary Search): ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    do {
        printf("\n1. Linear Search\n2. Binary Search (Iterative)\n3. Binary Search (Recursive)\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 3) {
            printf("Enter element to search: ");
            scanf("%d", &key);
        }
        switch (choice) {
            case 1:
                pos = linearSearch(arr, n, key);
                break;
            case 2:
                pos = binarySearchIterative(arr, n, key);
                break;
            case 3:
                pos = binarySearchRecursive(arr, 0, n - 1, key);
                break;
            case 4: return 0;
        }
        if (pos != -1) printf("Element found at position (1-based): %d\n", pos + 1);
        else printf("Element not found.\n");
    } while (choice != 4);
    return 0;
}