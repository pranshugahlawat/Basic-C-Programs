#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double discriminant, root1, root2, realPart, imaginaryPart;
    // a) Accept the coefficients a, b, and c from the user.
    printf("Enter coefficients a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    // e) Validate the input to ensure that the coefficient a is non-zero.
    if (a == 0) {
        printf("Coefficient 'a' cannot be zero. Please enter a non-zero value for 'a'.\n");
        return 1; // Exit the program with an error code
    }
    // b) Calculate the discriminant using the formula: D = b^2 - 4ac
    discriminant = b * b - 4 * a * c;
    // c) Determine the nature of roots based on the discriminant
    if (discriminant > 0) {
        // If D > 0, calculate and display two distinct real roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("The roots are real and distinct.\n");
        printf("Root 1 = %.2lf\n", root1);
        printf("Root 2 = %.2lf\n", root2);
    } else if (discriminant == 0) {
        // If D = 0, calculate and display two equal real roots
        root1 = root2 = -b / (2 * a);
        printf("The roots are real and equal.\n");
        printf("Root 1 = Root 2 = %.2lf\n", root1);
    } else {
        // If D < 0, calculate and display two complex conjugate roots
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("The roots are complex and conjugate.\n");
        printf("Root 1 = %.2lf + %.2lfi\n", realPart, imaginaryPart);
        printf("Root 2 = %.2lf - %.2lfi\n", realPart, imaginaryPart);
    }
    return 0;
}