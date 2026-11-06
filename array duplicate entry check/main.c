#include <stdio.h>

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void countFrequency(int orig[], int n_orig, int uniq[], int n_uniq) {
    printf("\nElement | Frequency\n-------------------\n");
    for (int i = 0; i < n_uniq; i++) {
        int count = 0;
        for (int j = 0; j < n_orig; j++) {
            if (uniq[i] == orig[j]) count++;
        }
        printf("   %d    |     %d\n", uniq[i], count);
    }
}

int removeDuplicates(int orig[], int n, int uniq[]) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        int exists = 0;
        for (int j = 0; j < k; j++) {
            if (orig[i] == uniq[j]) { exists = 1; break; }
        }
        if (!exists) uniq[k++] = orig[i];
    }
    return k;
}

int main() {
    int orig[50], uniq[50], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &orig[i]);

    printf("Original Array: ");
    displayArray(orig, n);

    int n_uniq = removeDuplicates(orig, n, uniq);
    printf("Array after removing duplicates: ");
    displayArray(uniq, n_uniq);

    countFrequency(orig, n, uniq, n_uniq);
    return 0;
}