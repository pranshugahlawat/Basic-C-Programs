#include <stdio.h>

int main() {
    float l, b;
    printf("\nEnter the length of the rectangle:\n");
    scanf("%f", &l);
    printf("\nEnter the breadth of the rectangle:\n");
    scanf("%f", &b);
    printf("\nThe area of the rectangle is: %f\n", l * b);
    printf("\nThe perimeter of the rectangle is: %f\n\n", 2 * (l + b));
    return 0;
}