#include <stdio.h>

int main() {
    int i, n;
    double x, sum = 1.0, term = 1.0;

    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("Enter number of terms (N): ");
    scanf("%d", &n);

    for (i = 1; i < n; i++) {
        term = term * (x / i);
        sum = sum + term;
    }

    printf("Approximate value of e^%.2lf up to %d terms = %.6lf\n", x, n, sum);
    return 0;
}