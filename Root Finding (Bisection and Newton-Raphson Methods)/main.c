#include <stdio.h>
#include <math.h>

double function(double x) {
    return (x * x * x - x - 2);
}

double derivative(double x) {
    return (3 * x * x - 1);
}

void bisection(double a, double b) {
    double c = a, prev_c, error = 1.0;
    int i = 0;
    while (error >= 0.0001) {
        prev_c = c;
        c = (a + b) / 2;
        i++;
        if (i > 1) error = fabs(c - prev_c);
        if (function(c) == 0.0) break;
        else if (function(c) * function(a) < 0) b = c;
        else a = c;
    }
    printf("\n--- Bisection Method ---\n");
    printf("Approximate Root: %.5lf\nIterations: %d\nError: %.6lf\n", c, i, error);
}

void newtonRaphson(double x0) {
    double x1, error = 1.0;
    int i = 0;
    while (error >= 0.0001) {
        x1 = x0 - function(x0) / derivative(x0);
        error = fabs(x1 - x0);
        x0 = x1;
        i++;
    }
    printf("\n--- Newton-Raphson Method ---\n");
    printf("Approximate Root: %.5lf\nIterations: %d\nError: %.6lf\n", x1, i, error);
}

int main() {
    bisection(1.0, 2.0);
    newtonRaphson(1.5);
    printf("\nComparison: Newton-Raphson converges much faster (fewer iterations) with higher accuracy.\n");
    return 0;
}