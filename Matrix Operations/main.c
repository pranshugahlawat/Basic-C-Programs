#include <stdio.h>

void display(int m[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d\t", m[i][j]);
        printf("\n");
    }
}

void multiplyMatrix(int a[10][10], int b[10][10], int n) {
    int res[10][10] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                res[i][j] += a[i][k] * b[k][j];
    printf("\nResultant Multiplied Matrix:\n");
    display(res, n);
}

void transposeMatrix(int m[10][10], int n) {
    int t[10][10];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) t[j][i] = m[i][j];
    display(t, n);
}

int isSymmetric(int m[10][10], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (m[i][j] != m[j][i]) return 0;
    return 1;
}

int main() {
    int a[10][10], b[10][10], n;
    printf("Enter order N of square matrices: ");
    scanf("%d", &n);
    printf("Enter Matrix A:\n");
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    printf("Enter Matrix B:\n");
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &b[i][j]);
    multiplyMatrix(a, b, n);
    printf("\nTranspose of Matrix A:\n"); transposeMatrix(a, n);
    printf("Matrix A is %s\n", isSymmetric(a, n) ? "Symmetric" : "Not Symmetric");
    printf("\nTranspose of Matrix B:\n"); transposeMatrix(b, n);
    printf("Matrix B is %s\n", isSymmetric(b, n) ? "Symmetric" : "Not Symmetric");
    return 0;
}