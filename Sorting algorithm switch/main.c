#include <stdio.h>

void createArray(int arr[], int n) {
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
}
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
            }
}
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min]) min = j;
        int temp = arr[min]; arr[min] = arr[i]; arr[i] = temp;
    }
}
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int arr[50], n, choice;
    printf("Enter size of array: ");
    scanf("%d", &n);
    createArray(arr, n);
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\nEnter choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        bubbleSort(arr, n);
        break;
    case 2:
        selectionSort(arr, n);
        break;
    case 3:
        insertionSort(arr, n);
        break;
    default:
        printf("Invalid choice. Try Again\n");
        main();
        break;
    }
    printf("Sorted Array: ");
    displayArray(arr, n);
    return 0;
}